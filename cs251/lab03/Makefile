all: gethttp webcrawler 

gethttp: gethttp.cpp openhttp.cpp SimpleHTMLParser.cpp
	g++ -o gethttp -g gethttp.cpp openhttp.cpp SimpleHTMLParser.cpp # -lnsl -lsocket

webcrawler: webcrawler.cpp openhttp.cpp SimpleHTMLParser.cpp
	g++ -o webcrawler -g webcrawler.cpp openhttp.cpp SimpleHTMLParser.cpp # -lnsl -lsocket

clean:
	rm -f *.o gethttp webcrawler core

