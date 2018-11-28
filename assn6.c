/**
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
 * @author Heather Hyer, Mariah Bleak, Daniel Asay
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
  while (fscanf(fp, "%d", &num) {
    printf("num: %d\n", num);
  }

  fcfs();
  sstf();
  look();
  clook();
}
