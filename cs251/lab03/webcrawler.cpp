#include "webcrawler.h"

char *word;
char *description;

void
onContentFound(char c)
{
    if (word == NULL)
    {
        word = new char[1];
    }
    
    if (description == NULL)
    {
        description = new char[500];
    }
    
    if (c != ' ')
    {
        char *buffer = new char[strlen(word)];
        strcpy(buffer, word);
        
        word = new char[strlen(word) + 1];
        
        strcpy(word, buffer);

        word[strlen(word) - 2] = c;
        word[strlen(word) - 1] = '\0';
    }
    else
    {
        // TODO: do something with word
        
        word = NULL;
    }
}

void
onAnchorFound(char *url)
{
    // TODO: implement this method
}

WebCrawler::WebCrawler(int maxUrls, int nInitialUrls, const char **initialUrls)
{
    _urlArray = new URLRecord[maxUrls];

    _maxUrls = maxUrls;
    _headURL = 0;
    _tailURL = 0;
    
    int i;
    for (i = 0; i < nInitialUrls; i++)
    {
        char *tmp = new char[strlen(initialUrls[i])];
        strcpy(tmp, initialUrls[i]);
        
        _urlArray[i]._url = tmp;
    }

    _urlToUrlRecord = new HashTableTemplate<int>();
    _wordToURLRecordList = new HashTableTemplate<URLRecordList*>();
}

void
WebCrawler::crawl()
{
    while (_headURL < _tailURL)
    {
        char *curr = _urlArray[_headURL]._url;
        
        _headURL = _headURL + 1;
        
        int n;
        char *buffer = WebCrawler.fetchHTML(curr, &n);
        if (buffer == NULL)
        {
            continue;
        }
        
        parse(buffer, n);

        //  Find all the hyperlinks of this document and add them to the
        //    _urlArray and _urlToUrlRecord if they are not already in the
        //    _urlToUrlRecord. Only insert up to _maxURL entries.

        //  For each word in the document without tags, add the index of this URL to
        //    a URLRecordList in the _wordToURLRecordList table if the URL is not already there.
    }
}

void
WebCrawler::writeURLFile(const char *urlFileName)
{
    // TODO: implement this method
}

void
WebCrawler::writeWordFile(const char *wordFileName)
{
    // TODO: implement this method
}

int
main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf( stderr, "  Usage: webcrawl [-u <maxurls>] url-list\n");
        exit(1);
    }
    
    int maxUrls;
    maxUrls = 1000;
    
    int start;
    start = 1;
    
    const char **initialUrls;
    
    if (strcmp(argv[1], "-u") == 0)
    {
        maxUrls = ((int)argv[2] - 48);
        start = 3;
    }
    
    initialUrls = new const char*[maxUrls];
    
    int i;
    for (i = start; i < argc; i++)
    {
        initialUrls[i - start] = argv[i];
    }
    
    WebCrawler *crawler = new WebCrawler(maxUrls, (argc - start - 1), initialUrls);
    
    crawler->crawl();
    crawler->writeURLFile("url.txt");
    crawler->writeWordFile("word.txt");
}

