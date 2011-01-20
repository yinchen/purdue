CC = gcc
CFLAGS = -g -I ./include -o
LFLAGS = -lintl
FILES = indent.c args.c backup.c comments.c lexi.c parse.c globs.c io.c output.c
OUT_EXE = indent

indent: $(FILES)
	$(CC) $(CFLAGS) $(OUT_EXE) $(FILES) $(LFLAGS)

clean: 
	rm -f *.o core

