#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	char ime[1024];
	char prezime[1024];
	int bodovi;
}_student;

int citajdatoteku();
int citajizdatoteke(_student*, int);

int main() {
	int test, counter, i;
	_student* stud;

	counter = citajdatoteku();

	stud = (_student*)malloc(counter * sizeof(_student));

	if (stud == NULL) {
		printf("Greska!\n");
		return 1;
	}

	test = citajizdatoteke(stud, counter);

	if (test == 0) {
		for (i = 0; i < counter; i++) {
			printf("Ime: %s\nPrezime %s\nBodovi: %d\n\n", stud->ime, stud->prezime, stud->bodovi);
			stud++;
		}
	}
	return 0;
}

int citajdatoteku() {
	FILE* file;
	int counter = 0;
	char popis[1024];

	file = fopen("Text.txt", "r");

	if (file == NULL) {
		printf("Greska!\n");
		return 1;
	}

	while (!feof(file)) {
		fgets(popis, 1024, file);
		counter++;
	}

	fclose(file);
	return counter;
}

int citajizdatoteke(_student* stud, int counter) {
	int i = 0;

	FILE* file;

	file = fopen("Text.txt", "r");

	if (file == NULL) {
		printf("Nije ocitan file!\n");
		return 1;
	}

	for (i = 0; i < counter; i++) {
		fscanf(file, " %s %s %d", stud->ime, stud->prezime, &stud->bodovi);
		stud++;
	}

	fclose(file);
	return 0;
}