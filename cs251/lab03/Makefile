all: gethttp webcrawl

gethttp: gethttp.cpp openhttp.cpp SimpleHTMLParser.cpp
	g++ -o gethttp -g gethttp.cpp openhttp.cpp SimpleHTMLParser.cpp -lnsl -lsocket

webcrawl: webcrawler.cpp openhttp.cpp SimpleHTMLParser.cpp
	g++ -o webcrawl -g webcrawler.cpp openhttp.cpp SimpleHTMLParser.cpp -lnsl -lsocket

clean:
	rm -f *.o gethttp webcrawl core *.txt

