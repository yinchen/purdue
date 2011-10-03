#include "webcrawler.h"

char *word;
char *description;

int inserted;

int
slength(const char *string)
{
    int length;
    length = 0;
    
    while (string[length] != '\0')
    {
        length++;
    }
    
    return length;
}

void
WebCrawler::onContentFound(char c)
{
    // initialize word
    if (word == NULL)
    {
        word = new char[1];
        word[0] = '\0';
    }
    
    // initialize description
    if (description == NULL)
    {
        description = new char[1];
        description[0] = '\0';
    }
    
    // check if this is the end of a word
    if (c != ' ' && c != '\n')
    {
        char *buffer;
        buffer = new char[slength(word) + 1];
        
        strcpy(buffer, word);
        
        int size;
        size = slength(word) + 1 + 1;
        
        word = new char[size];
        
        strcpy(word, buffer);
        
        word[size - 2] = c;
        word[size - 1] = '\0';
    }
    else
    {
        //  For each word in the document without tags, add the index of this URL to
        //    a URLRecordList in the _wordToURLRecordList table if the URL is not already there.
        
        /*
        URLRecordList *tmp;
        
        if (_wordToURLRecordList->find(word, &tmp) == false)
        {
            URLRecordList *data = new URLRecordList();
            data->_urlRecordIndex = _headURL;
            data->_next = NULL;
            
            _wordToURLRecordList->insertItem(word, data);
        }
        */
        
        word = NULL;
    }
    
    // only store the first 500 characters in description
    if (slength(description) < 500)
    {
        char *buffer;
        buffer = new char[slength(description) + 1];
        
        strcpy(buffer, description);
        
        int size;
        size = slength(description) + 1 + 1;
        
        description = new char[size];
        
        strcpy(description, buffer);
        
        description[size - 2] = c;
        description[size - 1] = '\0';
    }
}

void
WebCrawler::onAnchorFound(char *url)
{
    //  Find all the hyperlinks of this document and add them to the
        //    _urlArray and _urlToUrlRecord if they are not already in the
        //    _urlToUrlRecord. Only insert up to _maxURL entries.
    
    if (inserted >= _maxUrls)
        return;
    
    char *root = _urlArray[_headURL]._url;
    
    // append trailing slash to root url
    if (root[slength(root) - 1] != '/')
    {
        char *buffer;
        buffer = new char[slength(root) + 1];
        
        strcpy(buffer, root);
        
        int size;
        size = slength(root) + 1 + 1;
        
        root = new char[size];
        
        strcpy(root, buffer);
        
        root[size - 2] = '/';
        root[size - 1] = '\0';
    }
    
    // remove leading slash from current url
    if (url[0] == '/')
    {
        char *buffer;
        buffer = new char[slength(url)];
        
        strcpy(buffer, url);
        
        int size;
        size = slength(url);
        
        url = new char[size];
        
        strcpy(url, buffer + 1);
        
        url[size - 1] = '\0';
    }
        
    // append relative urls
    char *http = "http://";
    char *https = "https://";
    
    if (strncmp(url, http, 7) != 0 &&
        strncmp(url, https, 8) != 0)
    {
        char *buffer;
        buffer = new char[slength(url)];
        
        strcpy(buffer, url);
        
        int size;
        size = slength(root) + slength(url) + 1;
        
        url = new char[size];
        
        strcpy(url, root);
        strcpy(url + slength(root), buffer);
        
        url[size - 1] = '\0';
    }
    
    char *absoluteURL = new char[slength(url) + 1];
    strcpy(absoluteURL, url);
    
    int tmp;
    if (_urlToUrlRecord->find(absoluteURL, &tmp) == false)
    {
        _urlArray[_tailURL]._url = absoluteURL;
        _urlArray[_tailURL]._description = NULL;
        _tailURL = _tailURL + 1;
        
        _urlToUrlRecord->insertItem(absoluteURL, _headURL);
        inserted = inserted + 1;
    }
}

void
WebCrawler::crawl()
{
    while (_headURL < _tailURL)
    {
        char *curr = _urlArray[_headURL]._url;
        
        int n;
        char *buffer = fetchHTML(curr, &n);
        if (buffer == NULL)
        {
            _headURL = _headURL + 1;
            continue;
        }
        
        parse(buffer, n);
        
        _urlArray[_headURL]._description = description;
        
        word = NULL;
        description = NULL;

        _headURL = _headURL + 1;
    }
}

void
WebCrawler::print()
{
    int i;
    for (i = 0; i < _tailURL; i++)
    {
        printf("%s\n", _urlArray[i]._description);
    }
}

void
WebCrawler::writeURLFile(const char *urlFileName)
{
    // TODO: implement this method
    
    FILE *file;
    file = fopen(urlFileName, "w");
    
    int i;
    for (i = 0; i < _tailURL; i++)
    {
        fprintf(file, "%d %s\n", i, _urlArray[i]._url);
        fprintf(file, "%s\n", _urlArray[i]._description);
        fprintf(file, "\n");
    }
    
    fclose(file);
}

void
WebCrawler::writeWordFile(const char *wordFileName)
{
    // TODO: implement this method
}

WebCrawler::WebCrawler(int maxUrls, int nInitialUrls, const char **initialUrls)
{
    _urlArray = new URLRecord[nInitialUrls + maxUrls];

    _maxUrls = maxUrls;
    _headURL = 0;
    _tailURL = nInitialUrls;
    
    int i;
    for (i = 0; i < nInitialUrls; i++)
    {
        char *tmp = new char[strlen(initialUrls[i])];
        strcpy(tmp, initialUrls[i]);
        
        if (tmp[slength(tmp) - 1] != '/')
        {
            char *buffer;
            buffer = new char[slength(tmp) + 1];
            
            strcpy(buffer, tmp);
            
            int size;
            size = slength(tmp) + 1 + 1;
            
            tmp = new char[size];
            
            strcpy(tmp, buffer);
            
            tmp[size - 2] = '/';
            tmp[size - 1] = '\0';
        }
        
        _urlArray[i]._url = tmp;
        _urlArray[i]._description = NULL;
    }

    _urlToUrlRecord = new HashTableTemplate<int>();
    _wordToURLRecordList = new HashTableTemplate<URLRecordList*>();
}

int
main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf( stderr, "  Usage: webcrawler [-u <maxurls>] url-list\n");
        exit(1);
    }
    
    int maxUrls;
    maxUrls = 1000;
    
    inserted = 0;
    
    int start;
    start = 1;
    
    const char **initialUrls;
    
    if (strcmp(argv[1], "-u") == 0)
    {
        maxUrls = atoi(argv[2]);
        start = 3;
    }
    
    initialUrls = new const char*[(argc - start)];
    
    int i;
    for (i = start; i < argc; i++)
    {
        initialUrls[i - start] = argv[i];
    }
    
    WebCrawler *crawler = new WebCrawler(maxUrls, (argc - start), initialUrls);
    
    crawler->crawl();
    
    // crawler->print();
    
    crawler->writeURLFile("url.txt");
    crawler->writeWordFile("word.txt");
}

