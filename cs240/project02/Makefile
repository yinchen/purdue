
all: gauss bisection trapezoid

gauss: gauss.c
	gcc -g -o gauss gauss.c

bisection: bisection.c
	gcc -lm -g -o bisection bisection.c

trapezoid: trapezoid.c
	gcc -g -o trapezoid trapezoid.c

clean:
	rm -f gauss bisection trapezoid *out

