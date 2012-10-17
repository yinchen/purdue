all: chess.so sample1 sample2 chess_runner

chess.so: chess.cpp
	g++ -o $@ -Wall -shared -g -O0 -D_GNU_SOURCE -fPIC -ldl $^

sample1: sample1.c
	gcc -o sample1 -lpthread -lrt sample1.c

sample2: sample2.c
	gcc -o sample2 -lpthread -lrt sample2.c

chess_runner: chess_runner.c
	gcc -o chess_runner -lpthread -lrt chess_runner.c

clean:
	rm chess.so sample1 sample2 core *.txt
