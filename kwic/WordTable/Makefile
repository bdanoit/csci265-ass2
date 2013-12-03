
	
# NEW MAKE FILE
INC = ../include

XCFLAGS = -I$(INC) ## extra C flags

SD=../../CewDir


INDENT=cat

CC = gcc $(XCFLAGS)


bats: tb.o WordTable.o Exceptions.o
	$(CC) -o tb tb.o WordTable.o Exceptions.o

tb.c :  tb.cew
	rm -f $(SD)/tmp/tb.num
	rm -f ./tb.c
	awk -f $(SD)/bin/addLineNums.awk tb.cew > $(SD)/tmp/tb.num
	m4 -B20000 $(SD)/tmp/tb.num | $(INDENT) > tb.c


runtest: tb
	./tb

gcov: tb.o WordTable.o Exceptions.o
	$(CC) -fprofile-arcs -ftest-coverage -c WordTable.c
	$(CC) -fprofile-arcs -ftest-coverage -o tb tb.o WordTable.o Exceptions.o
	./tb
	gcov WordTable.c
	rm -f list.o # gcov version is dangerous to leave around

export: WordTable.o

Exceptions.o:
	gcc -c $(INC)/Exceptions.c

tb.o: $(INC)/kwic.h $(INC)/WordTable.h $(INC)/Exceptions.h tb.c
	$(CC) -c $(CFLAGS) tb.c

WordTable.o: $(INC)/kwic.h $(INC)/WordTable.h WordTable.c
	$(CC) -c $(CFLAGS) WordTable.c

clean:
	rm -f *.o act/* tb *.gcov *.gcda *.gcno
