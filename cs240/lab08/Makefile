scheduler: main.o my_scheduler.o
	gcc -o scheduler main.o my_scheduler.o

my_scheduler.o: my_scheduler.c my_scheduler.h
	gcc -c my_scheduler.c

main.o: main.c my_scheduler.h
	gcc -c main.c

clean:
	rm -rf *.o scheduler core *~
