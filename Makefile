CC=      tcc
CFLAGS=  -Wfatal-errors -Wall -Wextra
LDFLAGS= -s
OBJS=    str.o vec.o term.o ve.o

all: ve
ve: main.o $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)
o: o.o $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)
clean:
	$(RM) $(OBJS) ve *.o
