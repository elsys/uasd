all: main.out

dLinkedList.o: dLinkedList.h dLinkedList.c
	gcc -c dLinkedList.c -o dLinkedList.o

main.out: dLinkedList.o main.c
	gcc main.c dLinkedList.o -o main.out

clean:
	rm -f *.o *.out