CC=      tcc
CFLAGS=  -Wfatal-errors -Wall -Wextra
LDFLAGS= -s
OBJS=    str.o vec.o
TESTS=   $(shell \ls test*.c|cut -d'.' -f1)

all: $(OBJS) $(TESTS)
%: %.c $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)
clean:
	$(RM) $(OBJS) $(TESTS) *.o
