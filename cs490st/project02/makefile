sample1: sample1.c
	gcc -o sample1 -lpthread -lrt sample1.c

sample2: sample2.c
	gcc -o sample2 -lpthread -lrt sample2.c

chess.so: chess.cpp
	g++ -o $@ -Wall -shared -g -O0 -D_GNU_SOURCE -fPIC -ldl $^

clean:
	rm *.so sample1 sample2
