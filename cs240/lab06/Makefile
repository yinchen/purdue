lab06: main.o separate.o
	gcc -lm -o lab06 main.o separate.o

main.o: main.c
	gcc -c main.c

separate.o: separate.c separate.h
	gcc -c separate.c separate.h

clean:
	rm -f lab06 main.o separate.o
