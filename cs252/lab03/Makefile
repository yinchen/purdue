
#Use GNU compiler
cc = gcc -g
CC = g++ -g

all: shell cat_grep ctrl-c regular

lex.yy.o: shell.l 
	lex shell.l
	$(cc) -o lex.yy.o -c lex.yy.c

y.tab.o: shell.y
	yacc -d shell.y
	$(CC) -o y.tab.o -c y.tab.c

command.o: command.cc
	$(CC) -o command.o -c command.cc -lgen
	
tty-raw-mode.o: tty-raw-mode.c
	gcc -c tty-raw-mode.c

read-line.o: read-line.c
	gcc -c read-line.c

shell: y.tab.o lex.yy.o command.o tty-raw-mode.o read-line.o
	$(CC) -o shell lex.yy.o y.tab.o command.o tty-raw-mode.o read-line.o -ll -lgen

cat_grep: cat_grep.cc
	$(CC) -o cat_grep cat_grep.cc

ctrl-c: ctrl-c.cc
	$(CC) -o ctrl-c ctrl-c.cc

regular: regular.cc
	$(CC) -o regular regular.cc -lgen

clean:
	rm -f shell ctrl-c regular cat_grep read-line-example keyboard-example *.o

