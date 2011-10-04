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
    if (('A' <= c && c <= 'Z') ||
        ('a' <= c && c <= 'z') ||
        ('0' <= c && c <= '9')
    {
        char *single = new char[2];
        single[0] = c;
        single[1] = '\0';
        
        char *buffer;
        buffer = strcat(word, single);
        
        strcpy(word, buffer);
    }
    else
    {
        //  For each word in the document without tags, add the index of this URL to
        //    a URLRecordList in the _wordToURLRecordList table if the URL is not already there.
        
        if (word == NULL || slength(word) <= 0)
            return;
        
        URLRecordList *tmp = NULL;        
        if (_wordToURLRecordList->find(word, &tmp) == false)
        {
            URLRecordList *data = new URLRecordList();
            data->_urlRecordIndex = _headURL;
            data->_next = NULL;
            
            _wordToURLRecordList->insertItem(word, data);
        }
        else
        {
            URLRecordList *data = new URLRecordList();
            data->_urlRecordIndex = _headURL;
            data->_next = tmp;
            
            _wordToURLRecordList->insertItem(word, data);
        }
        
        word = NULL;
    }
    
    // only store the first 500 characters in description
    if (slength(description) < 500)
    {
        char *single = new char[2];
        single[0] = c;
        single[1] = '\0';
        
        char *buffer;
        buffer = strcat(description, single);
        
        strcpy(description, buffer);
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
        root = strcat(root, "/");
    }
    
    // check if this is an absolute url
    if (url[0] == '/')
    {
        // chop off the directory structure
        int count;
        count = 0;
        
        int i;
        for (i = 0; i < slength(root); i++)
        {
            if (root[i] == '/')
                count = count + 1;
            else
                continue;
            
            if (count >= 3)
            {
                root[i] = '\0';
                break;
            }
        }
        
        url = strcat(root, url);
    }
    else
    {
        char *http = "http://";
        char *https = "https://";
        
        if (strncmp(url, http, 7) != 0 &&
            strncmp(url, https, 8) != 0)
        {
            url = strcat(root, url);
        }
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
WebCrawler::writeURLFile(const char *urlFileName)
{
    FILE *file;
    file = fopen(urlFileName, "w");
    
    int i;
    for (i = 0; i < _tailURL; i++)
    {
        fprintf(file, "%d %s\n", i, _urlArray[i]._url);
        if (_urlArray[i]._description != NULL)
            fprintf(file, "%s\n", _urlArray[i]._description);
        else
            fprintf(file, "%s\n", "");
        fprintf(file, "\n");
    }
    
    fclose(file);
}

void
WebCrawler::writeWordFile(const char *wordFileName)
{
    FILE *file;
    file = fopen(wordFileName, "w");
    
    int i;
    for (i = 0; i < 2039; i++)
    {
        if (_wordToURLRecordList->_buckets[i] == NULL)
            continue;
        
        fprintf(file, "%s", _wordToURLRecordList->_buckets[i]->_key);
        
        URLRecordList *curr = _wordToURLRecordList->_buckets[i]->_data;
        while (curr != NULL)
        {
            fprintf(file, " %d", curr->_urlRecordIndex);
            curr = curr->_next;
        }
        
        fprintf(file, "\n");
    }
    
    fclose(file);
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
            tmp = strcat(tmp, "/");
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

