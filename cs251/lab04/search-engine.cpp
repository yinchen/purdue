#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "search-engine.h"
#include "webcrawl.h"

DictionaryType dictType;
hrtime_t average;

int searches = 0;

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
		
	dictType = dictionaryType;

	// populate dictionary and sort it if necessary
	URLRecord **records = new URLRecord*[1024];
	
	int i;
	for (i = 0; i < 1024; i++)
	{
		records[i] = new URLRecord();
	}
	
	FILE *infile;
	infile = fopen("url.txt", "r");
	
	char *line;
	line = new char[512];
	
	while (fgets(line, 512, infile))
	{
		if (strcmp(line, "\n") != 0)
		{
			// parse the index
			char *token = new char[512];
			token = strtok(line, " \n");
			int index = atoi(token);
			
			// parse the url
			token = strtok(NULL, " \n");
			char *url = new char[512];
			strcpy(url, token);
						
			// parse the description
			fgets(line, 512, infile);
			
			char *desc = new char[512];
			token = strtok(line, "\n");
			strcpy(desc, token);
			
			// store this entry
			records[index]->_url = url;
			records[index]->_description = desc;			
		}
	}
	
	delete line;
	fclose(infile);
	
	infile = fopen("word.txt", "r");
	
	line = new char[512];
	
	while (fgets(line, 512, infile))
	{
		if (strcmp(line, "\n") != 0)
		{
			// parse the word
			char *token = new char[512];
			token = strtok(line, " \n");
			
			char *word = new char[512];
			strcpy(word, token);
			
			URLRecordList *head;
			head = NULL;
			
			URLRecordList *prev;
			prev = NULL;
			
			token = strtok(NULL, " \n");
			
			while (token != NULL)
			{
				int position = atoi(token);
				
				if (records[position]->_url == NULL)
					continue;
				
				URLRecordList *entry = new URLRecordList();
				
				if (head == NULL)
					head = entry;
				
				entry->_urlRecord = records[position];
				entry->_next = NULL;
				
				if (prev != NULL)
					prev->_next = entry;
					
				prev = entry;
				
				token = strtok(NULL, " \n");
			}
			
			_wordToURLList->addRecord(word, (URLRecordList*)head);
			
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
		words[numWords] = new char[50];
		
		strcpy(words[numWords], word);
		numWords++;
		
		word = strtok(NULL, "+");
	}

	// create friendly search string
	char *query = new char[100*50];
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
	
	hrtime_t time1, time2;
	
	int counter;
	counter = 0;
	
	int listCount;
	listCount = 0;
	
	URLRecord **list = new URLRecord*[500];
	
	if (average == NULL)
		average = 0.0;
	time1 = gethrtime();
	
	for (i = 0; i < numWords; i++)
	{
		URLRecordList* data;
		data = (URLRecordList*)_wordToURLList->findRecord(words[i]);
		
		while (data != NULL)
		{
			int exists = 0;
			
			int j;
			for (j = 0; j < listCount; j++)
			{
				if (list[j] == data->_urlRecord)
				{
					exists = 1;
					break;
				}
			}
			
			if (exists == 0)
			{
				list[listCount] = data->_urlRecord;
				listCount++;
			}
			
			data = data->_next;
		}
	}
	
	for (i = 0; i < listCount; i++)
	{
		int j;
		for (j = 0; j < numWords; j++)
		{
			URLRecordList* data;
			data = (URLRecordList*)_wordToURLList->findRecord(words[j]);
			
			int exists = 0;
			
			while (data != NULL)
			{
				if (data->_urlRecord == list[i])
				{
					exists = 1;
				}
				
				data = data->_next;
			}
			
			if (exists == 0)
				list[i] = NULL;
		}
	}
	
	time2 = gethrtime();
	
	average += time2-time1;	
	
	for (i = 0; i < listCount; i++)
	{
		if (list[i] == NULL) continue;
		
		fprintf(fout, "<h3>%d. <a href=\"%s\">%s</a><h3>\n", counter+1, list[i]->_url, list[i]->_url);
		fprintf(fout, "<blockquote>%s<p></blockquote>\n", list[i]->_description);
	
		counter++;
	}
	
	searches++;
	
	fprintf(fout, "<BR>\n");
	fprintf(fout, "<h3>Search Time: %lld ns</h3>\n", time2 - time1);
	fprintf(fout, "<h3>Average Search Time: %lld ns</h3>\n", average/searches);
	
	if (dictType == ArrayDictionaryType)
		fprintf(fout, "<h3>Dictionary Used: Array Dictionary</h3>\n");
	else if (dictType == HashDictionaryType)
		fprintf(fout, "<h3>Dictionary Used: Hash Dictionary</h3>\n");
	else if (dictType == AVLDictionaryType)
		fprintf(fout, "<h3>Dictionary Used: AVL Dictionary</h3>\n");
	else if (dictType == BinarySearchDictionaryType)
		fprintf(fout, "<h3>Dictionary Used: Binary Search Dictionary</h3>\n");
	else
		fprintf(fout, "<h3>Dictionary Used: Unknown Dictionary</h3>\n");
	
	// add search form at the end
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
