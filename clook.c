#include <stdlib.h>

void clook(int blockList[], int count) {

	int visited[count];
	int goPositive = 1;
	for (int i = 0; i < count; i++) {
		visited[i] = -1;
	}

	visited[0] = blockList[0];
	int currentPos = 0;
	int distance = 0;
	int nextPos;
	for (int i = 0; i < count - 1; i++) {

		nextPos = -1;
		if (goPositive == 1) {
			for (int j = 0; j < count; j++) {
				if (blockList[j] > blockList[currentPos] && visited[j] == -1) {
					if (nextPos == -1 || blockList[j] < blockList[nextPos]) {
						nextPos = j;
					}
				}
			}
			if (nextPos == -1) {
				goPositive == 0;
			}
		}
		if (goPositive == 0) {
			int lowest = 0;
			for (int j = 0; j < count - 1; j++) {
				if (blockList[j] < blockList[lowest]) {
					lowest = j;
				}
			}
			nextPos = lowest;
			printf("%d\n\n", lowest);
		}
//		if (goPositive == 0) {
//			for (int j = 0; j < count; j++) {
//				if (blockList[j] < blockList[currentPos] && visited[j] == -1) {
//					if (nextPos == -1 || blockList[j] > blockList[nextPos]) {
//						nextPos = j;
//					}
//				}
//			}
//		}
		visited[nextPos] = blockList[nextPos];
		printf("loc1: %d, loc2: %d, distance %d\n", blockList[currentPos], blockList[nextPos],
		 goPositive != 0 ? blockList[nextPos] - blockList[currentPos] : blockList[currentPos] - blockList[nextPos]);
		distance += goPositive != 0 ? blockList[nextPos] - blockList[currentPos] : blockList[currentPos] - blockList[nextPos];
		goPositive = 1;
		currentPos = nextPos;
	}
	printf("LOOK Total Seek: %d\n", distance);

}
