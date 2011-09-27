all: gethttp webcrawler 

gethttp: gethttp.cpp openhttp.cpp SimpleHTMLParser.cpp
	g++ -o gethttp -g gethttp.cpp openhttp.cpp SimpleHTMLParser.cpp -lnsl -lsocket

webcrawler: webcrawler.cpp SimpleHTMLParser.cpp
	g++ -o webcrawler -g webcrawler.cpp SimpleHTMLParser.cpp

clean:
	rm -f *.o gethttp webcrawler core
