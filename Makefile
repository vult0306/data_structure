IDIR =./inc
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=./obj
LDIR =./lib

LIBS=-lm

_DEPS = helloworld.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ =  helloworld.o \
		hashing.o \
		static_stack.o \
		dynamic_stack.o \
		queue.o \
		tree.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

helloworld: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 