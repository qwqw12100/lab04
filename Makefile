CC=gcc
CFLAGS=-lWarn -pedantic
LDFLAGS=-lwiringPi


irtester: irtester.o libmyifttt.a
	$(CC) $(LDFLAGS) irtester.o -L. -lmyfttt -lcurl -o irtester

irtester.o: irtester.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $< 

tester: tester.o libmyifttt.a
	$(CC) tester.o -L. -lmyifttt -lcurl -o tester

libmyifttt.a:	ifttt.o
	ar -rcs libmyifttt.a ifttt.o

ifttt.o:	ifttt.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

tester.o:	tester.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<

clean:
	rm tester *.o
