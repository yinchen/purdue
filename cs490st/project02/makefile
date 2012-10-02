chess.so: chess.cpp
	g++ -o $@ -Wall -shared -g -O0 -D_GNU_SOURCE -fPIC -ldl $^

clean:
	rm *.so sample1 sample2
