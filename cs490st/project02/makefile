chess.so sample1 sample2: chess.cpp sample1.c sample2.c
	g++ -o $@ -Wall -shared -g -O0 -D_GNU_SOURCE -fPIC -ldl $^
	gcc -o sample1 -lpthread -lrt sample1.c
	gcc -o sample2 -lpthread -lrt sample2.c

clean:
	rm *.so sample1 sample2 core
