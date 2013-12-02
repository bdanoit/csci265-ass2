INC = ../include

XCFLAGS = -I$(INC) ## extra C flags

CC = gcc -pg -g $(XCFLAGS)

SD = ../../CewDir

runtest: tb.cew
	./tb.cew

tb.cew: tb.cew.o LineStorage.o Exceptions.o
	$(CC) -o tb.cew tb.cew.o LineStorage.o Exceptions.o

gcov: tb.cew.o LineStorage.o Exceptions.o
	$(CC) -fprofile-arcs -ftest-coverage -c LineStorage.c
	$(CC) -fprofile-arcs -ftest-coverage -o driver tb.cew.o LineStorage.o Exceptions.o
	./driver
	gcov LineStorage.c
	rm -f list.o # gcov version is dangerous to leave around

gprof: driver
	./driver
	gprof -b ./driver gmon.out


export: LineStorage.o

tb.cew.c: tb.c
	rm -f $(SD)/tmp/tb.num
	rm -f ./tb.cew.c
	awk -f $(SD)/bin/addLineNums.awk tb.c > $(SD)/tmp/tb.num
	m4 -B20000 $(SD)/tmp/tb.num | $(INDENT) > tb.cew.c


tb.cew.o: $(INC)/kwic.h $(INC)/LineStorage.h tb.cew.c $(INC)/Exceptions.h
	$(CC) -c $(CFLAGS) tb.cew.c
	rm -f tb.cew.c

LineStorage.o: $(INC)/kwic.h $(INC)/LineStorage.h LineStorage.c $(INC)/Exceptions.h
	$(CC) -c $(CFLAGS) LineStorage.c

Exceptions.o: $(INC)/Exceptions.c $(INC)/Exceptions.h
	$(CC) -c $(CFLAGS) $(INC)/Exceptions.c

clean:
	rm -f *.o act/* driver *.gcov *.gcda *.gcno gmon.out tb.cew*
