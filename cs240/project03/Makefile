webstore: webstore.o main.o
	gcc -o webstore main.o webstore.o

webstore.o: webstore.h webstore.c
	gcc -c webstore.c

main.o: webstore.h main.c
	gcc -c main.c

clean:
	rm -rf core *.o webstore *~
