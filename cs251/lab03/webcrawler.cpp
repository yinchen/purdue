#include "webcrawler.h"

WebCrawler::WebCrawler(int maxUrls, int nInitialUrls, const char **initialUrls)
{
  _urlArray = new URLRecord[maxUrls];
  
  int i;
  for (i = 0; i < nInitialUrls; i++)
  {
  	strcpy(_urlArray[i]._url, initialUrls[i]);
  	strcpy(_urlArray[i]._description, "initialUrls[i]");
  }
  
  _maxUrls = maxUrls;
  _headURL = nInitialUrls;
  _tailURL = nInitialUrls;
}

void
WebCrawler::crawl()
{

  //while (_headURL <_tailURL) {
  //  Fetch the next URL in _headURL

  //  Increment _headURL

  //  If the document is not text/html 

  //        continue;

  //  Get the first 500 characters (at most) of the document without tags. Add this 
  //     description to theURL record for this URL.

  //  Find all the hyperlinks of this document and add them to the
  //    _urlArray and _urlToUrlRecord if they are not already in the
  //    _urlToUrlRecord. Only insert up to _maxURL entries.

  //  For each word in the document without tags, add the index of this URL to
  //    a URLRecordList in the _wordToURLRecordList table if the URL is not already there.
  //}
}

int
main(int argc, char **argv)
{

}