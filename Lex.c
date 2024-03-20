// --------------------------------------------------------------
// Nicolas Corfmat
// CruzID: ncorfmat
// Assignment: pa1
// --------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "List.h"

#define MAX_LEN 300

int main(int argc, char * argv[]) {

	// BEGIN code adapted from Patrick Tantalo.
	
	FILE *in, *out;
	char lines[MAX_LEN];

	int n = 0, line = 0;

	// CHECK that there are exactly two command line arguments.
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// OPEN files for reading and writing.
	in = fopen(argv[1], "r");

	if (in == NULL) {
		fprintf(stderr, "Unable to open file %s for reading.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	out = fopen(argv[2], "w");

        if (out == NULL) {
                fprintf(stderr, "Unable to open file %s for writing.\n", argv[2]);
                exit(EXIT_FAILURE);
        }

	// COUNT number of lines in input file.
	while (fgets(lines, MAX_LEN, in) != NULL) {
		n++;
	}

	// END code adapted from Patrick Tantalo.

	// ALLOCATE memory for string array.
	char **array = calloc(n, sizeof(char *));

	for (int i = 0; i < n; i++) {
		array[i] = calloc(MAX_LEN, sizeof(char));
	}

	fseek(in, 0, SEEK_SET);

	// COPY input data into array.
	while (fgets(lines, MAX_LEN, in) != NULL) {
		strcpy(array[line], lines);
		line++;
	}

	List L = newList();

	append(L, 0);

	// PERFORM sorting based on lexicographical order.
	for (int i = 1; i < n; i++) {

		// MOVE cursor to front of List.
		moveFront(L);

		int j = i;

		while (j > 0 && strcmp(array[i], array[get(L)]) >= 0) {
			moveNext(L);
			j -= 1;
		}	

		if (index(L) >= 0) {
			insertBefore(L, i);
		} else {
			append(L, i);
		}
	}

	moveFront(L);

	// PRINT elements to outfile.
	while (index(L) >= 0) {
		fprintf(out, "%s", array[get(L)]);
		moveNext(L);
	}

	// CLOSE files and DEALLOCATE variables.
	fclose(in);
	fclose(out);

	for (int i = 0; i < n; i++) {
		free(array[i]);
	}

	free(array);
	freeList(&L);

	return EXIT_SUCCESS;
}
