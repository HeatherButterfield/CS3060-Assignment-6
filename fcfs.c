#include <stdio.h>
#include <stdlib.h>

void fcfs(int blockList[], int count) {
	printf("FCFS Total Seek: ");
	int deltas[count-1];
	int total = 0;
	for (int i = 0; i < count - 1; i++) {
		deltas[i] = blockList[i] - blockList[i+1];
		total += abs(deltas[i]);
	}	
	printf("%d", total);
	printf("\n");
}
