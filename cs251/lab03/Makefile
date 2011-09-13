
all: gethttp

gethttp: gethttp.cpp openhttp.cpp SimpleHTMLParser.cpp
	g++ -o gethttp -g gethttp.cpp openhttp.cpp SimpleHTMLParser.cpp -lnsl -lsocket

clean:
	rm -f *.o gethttp core
