/*
 *
 * Assignment 6
 * CS 3060 section 601
 *
 * Promise of Originality
 * I promise that this source code file has, in its entirety, been
 * written by myself and by no other person or persons. If at any time an
 * exact copy of this source code is found to be used by another person in
 * this term, I understand that both myself and the student that submitted
 * the copy will receive a zero on this assignment.
 *
 * @author Myron Burton, Heather Hyer, Mariah Bleak, Daniel Asay
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "fcfs.c"
#include "sstf.c"
#include "look.c"
#include "clook.c"

int main(int argc, char *argv[]) {
	FILE *fp = stdin;

	if (argc > 1) {
		fp = fopen(argv[1], "r");
	} else {
		printf("You need to provide a filename\n");
	}

	if (fp == NULL) {
		printf("Unable to open the file %s\n", argv[1]);
		perror("Trying to open file");
		return -1;
	}

	int blockList[100];
	int num;
	int i = 0;
	int count = 0;
	while (fscanf(fp, "%d", &num) == 1) {
		blockList[i] = num;
		count++;
		i++;
	}

	fcfs(blockList, count);
	sstf(blockList, count);
	look(blockList, count);
	clook(blockList, count);
}
