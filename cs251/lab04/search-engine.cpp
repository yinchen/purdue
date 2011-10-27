#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "search-engine.h"
#include "webcrawl.h"

SearchEngine::SearchEngine( int port, DictionaryType dictionaryType):
  MiniHTTPD(port)
{
	// create dictionary of the indicated type
	if (dictionaryType == ArrayDictionaryType)
		_wordToURLList = new ArrayDictionary();
	else if (dictionaryType == HashDictionaryType)
		_wordToURLList = new HashDictionary();
	else if (dictionaryType == AVLDictionaryType)
		_wordToURLList = new AVLDictionary();
	else if (dictionaryType == BinarySearchDictionaryType)
		_wordToURLList = new BinarySearchDictionary();
	else
		_wordToURLList = NULL;

	// populate dictionary and sort it if necessary
	URLRecord *records = new URLRecord[1024];
	
	FILE *infile;
	infile = fopen("url.txt", "r");
	
	char *line;
	line = new char[256];
	
	int index;
	index = 0;
	
	while (fgets(line, 256, infile))
	{
		if (strcmp(line, "\n") != 0)
		{
			// parse the url
			char *url = new char[256];
			strtok(line, " ");
			
			strcpy(url, strtok(NULL, " "));
			url[strlen(url) - 1] = '\0';
			
			// parse the description
			fgets(line, 512, infile);
			
			char *desc = new char[512];
			strcpy(desc, line);
			
			// store this entry
			records[index]._url = strdup(url);
			records[index]._description = strdup(desc);	

			index++;			
		}
	}
	
	delete line;
	fclose(infile);
	
	infile = fopen("word.txt", "r");
	
	line = new char[256];
	
	while (fgets(line, 256, infile))
	{
		if (strcmp(line, "\n") != 0)
		{
			// parse the word
			char *token = new char[256];
			token = strtok(line, " ");
			
			char *word = new char[256];
			strcpy(word, token);
			
			URLRecordList *head;
			head = NULL;
			
			URLRecordList *prev;
			prev = NULL;
			
			strtok(NULL, " ");
			
			while (token != NULL)
			{
				int position = atoi(token);
				
				URLRecordList *entry = new URLRecordList();
				
				if (head == NULL)
					head = entry;
				
				entry->_urlRecord = &records[position];
				entry->_next = NULL;
				
				if (prev != NULL)
					prev->_next = entry;
					
				prev = entry;
				
				token = strtok(NULL, " ");
			}
			
			_wordToURLList->addRecord(word, (URLRecordList*)head);
			
			delete prev;
			delete head;
			delete word;
			delete token;
		}
	}
	
	delete line;
	fclose(infile);
}

void
SearchEngine::dispatch( FILE * fout, const char * documentRequested)
{
	// display initial form
	if (strcmp(documentRequested, "/")==0)
	{
		fprintf(fout, "<TITLE>CS251 Search</TITLE>\r\n");
		fprintf(fout, "<CENTER><H1><em>Boiler Search</em></H1>\n");
		fprintf(fout, "<H2>\n");
		fprintf(fout, "<FORM ACTION=\"search\">\n");
		fprintf(fout, "Search:\n");
		fprintf(fout, "<INPUT TYPE=\"text\" NAME=\"word\" MAXLENGTH=\"80\"><P>\n");
		fprintf(fout, "</H2>\n");
		fprintf(fout, "</FORM></CENTER>\n");
		return;
	}
	
	// ignore if this is not a search
	if (strlen(documentRequested) < 13)
		return;
	
	// extract query string
	char *param = new char[strlen(documentRequested)];
	strcpy(param, documentRequested+13);

	// initialize words list
	char **words = new char*[100];
	int i;
	for (i = 0; i < 100; i++)
	{
		words[i] = NULL;
	}
	
	// parse url for search parameters
	int numWords;
	numWords = 0;
	
	char *word;
	word = strtok(param, "+");
	
	while (word != NULL)
	{
		words[numWords] = new char[100];
		
		strcpy(words[numWords], word);
		numWords++;
		
		word = strtok(NULL, "+");
	}

	// search index for urls and descriptions
	const int nurls = 2;

	char * urls[] = 
	{
		"http://www.cs.purdue.edu",
		"http://www.cs.purdue.edu/homes/cs251"
	};

	char * description[] =
	{
		"Computer Science Department. Purdue University.",
		"CS251 Data Structures"
	};
	
	// create friendly search string
	char *query = new char[100*100];
	strcpy(query, "");
	
	for (i = 0; i < numWords; i++)
	{
		strcat(query, words[i]);
		
		if (i < numWords - 1)
			strcat(query, " ");
	}
	
	// print search results
	fprintf(stderr, "Search for words: \"%s\"\n", query);

	fprintf(fout, "<TITLE>Search Results</TITLE>\r\n");
	fprintf(fout, "<H1> <Center><em>Boiler Search</em></H1>\n");
	fprintf(fout, "<H2> Search Results for \"%s\"</center></H2>\n", query);

	for (int i = 0; i < nurls; i++)
	{
		fprintf(fout, "<h3>%d. <a href=\"%s\">%s</a><h3>\n", i+1, urls[i], urls[i]);
		fprintf(fout, "<blockquote>%s<p></blockquote>\n", description[i]);
	}

	// Add search form at the end
	fprintf(fout, "<HR><H2>\n");
	fprintf(fout, "<FORM ACTION=\"search\">\n");
	fprintf(fout, "Search:\n");
	fprintf(fout, "<INPUT TYPE=\"text\" NAME=\"word\" MAXLENGTH=\"80\"><P>\n");
	fprintf(fout, "</H2>\n");
	fprintf(fout, "</FORM>\n");
}

void
printUsage()
{
	const char * usage =
		"Usage: search-engine port (array | hash | avl | bsearch)\n"
		"  It starts a search engine at this port using the\n"
		"  data structure indicated. Port has to be larger than 1024.\n";

	fprintf(stderr, usage);
}

int main(int argc, char ** argv)
{
	if (argc < 3)
	{
		printUsage();
		return 1;
	}

	// get port
	int port;
	sscanf( argv[1], "%d", &port);

	// get dictionarytype
	const char * dictType = argv[2];
	DictionaryType dictionaryType;
	if (!strcmp(dictType, "array"))
	{
		dictionaryType = ArrayDictionaryType;
	}
	else if (!strcmp(dictType, "hash"))
	{
		dictionaryType = HashDictionaryType;
	}
	else if (!strcmp(dictType, "avl"))
	{
		dictionaryType = AVLDictionaryType;
	}
	else if (!strcmp(dictType, "bsearch"))
	{
		dictionaryType = BinarySearchDictionaryType;
	}
	else
	{
		printUsage();
		return 0;
	}

	SearchEngine httpd(port, dictionaryType);
	httpd.run();

	return 0;
}
