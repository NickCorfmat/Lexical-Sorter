// --------------------------------------------------------------
// Nicolas Corfmat
// CruzID: ncorfmat
// Assignment: pa1
// --------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "List.h"

#define FORMAT "%d"

int main(int argc, char* argv[]) {

	FILE* out = stdout;

	printf("\n");
	
	List L = newList();
	List L2 = newList();

	printf("\n");

	for (int i = 1; i < 10; i++) {
		append(L, i);
	}

	fprintf(stdout, "append 1-9\n");
	printList(out, L);

        moveFront(L);

	fprintf(out, "move front\n");
        printList(out, L);
	fprintf(out, "index = %d\n", index(L));

	moveNext(L);

        fprintf(out, "move next\n");
        printList(out, L);
        fprintf(out, "index = %d\n", index(L));

	for (int i = 1; i < 5; i++) {
		deleteBack(L);
	}

	fprintf(stdout, "delete back 4 times\n");
	printList(out, L);

	prepend(L, 69);
	fprintf(stdout, "prepend 69\n");
	printList(out, L);

	moveBack(L);

        fprintf(out, "move back\n");
        printList(out, L);
        fprintf(out, "index = %d\n", index(L));

	movePrev(L);

        fprintf(out, "move previous\n");
        printList(out, L);

        fprintf(out, "index = %d\n", index(L));

	fprintf(out, "get = %d\n", get(L));

	insertBefore(L, 100);

        fprintf(out, "insert before 100\n");
        printList(out, L);

        insertAfter(L, 420);

        fprintf(out, "insert after 420\n");
        printList(out, L);

	for (int i = 11; i <= 15; i++) {
		append(L, i);
	}

	fprintf(stdout, "append 11-15\n");
	printList(out, L);

	for (int i = 16; i <= 19; i++) {
                append(L, i);
        }

	fprintf(stdout, "append 16-19\n");
        printList(out, L);
	printf("\n");

	fprintf(stdout, "front = %d\n", front(L));
	fprintf(stdout, "back = %d\n", back(L));
	fprintf(stdout, "length = %d\n", length(L));

	deleteFront(L);
	deleteBack(L);

	fprintf(stdout, "front = %d\n", front(L));
        fprintf(stdout, "back = %d\n", back(L));

	fprintf(stdout, "delete back L 7 times\n");
	fprintf(stdout, "append L2 13-19\n");
	for (int i = 13; i <= 19; i++) {
		deleteBack(L);
		append(L2, i);
	}

	printList(out, L);
	printList(out, L2);
	printf("Q == R is %s\n\n", equals(L, L2)?"true":"false");

	fprintf(stdout, "append L 20\n");
	append(L, 20);

	fprintf(stdout, "append L2 200\n");
	append(L2, 200);

	printList(out, L);
	printList(out, L2);

	printf("Q == R is %s\n\n", equals(L, L2)?"true":"false");
	
	List L3 = newList();

	append(L3, 2);
	moveFront(L3);
	prepend(L3, 1);
	append(L3, 3);

	printList(out, L3);

	delete(L3);
	printList(out, L3);

	deleteFront(L3);
	printList(out, L3);

	deleteBack(L3);
	printList(out, L3);

	List L4 = newList();

	for (int i = 1; i <= 10; i++) {
		append(L4, i);
	}

	List L5 = copyList(L4);

	printList(out, L4);
	printList(out, L5);

	freeList(&L4);
	freeList(&L5);
	freeList(&L3);
	freeList(&L);
	freeList(&L2);

	return(EXIT_SUCCESS);
}
