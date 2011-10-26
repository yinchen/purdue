#include <string.h>
#include "search-engine.h"

SearchEngine::SearchEngine( int port, DictionaryType dictionaryType):
  MiniHTTPD(port)
{
	// Create dictionary of the indicated type

	// Populate dictionary and sort it if necessary
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
