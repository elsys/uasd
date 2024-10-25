all: main.out

skiplist.o: skiplist.h skiplist.c
	gcc -c skiplist.c -o skiplist.o

main.out: skiplist.o main.c
	gcc main.c skiplist.o -o main.out

clean:
	rm -f *.o *.out