#include <stdio.h>
#include <stdlib.h>

// Daniel Asay
void sstf(int blockList[], int count) {
	int remaining[count];
	int next = 1; // next chunk
	int time = 0; // seek time

	for (int i = 0; i< count; i ++)
	{	// deep copy on blockList
		remaining[i] = blockList[i];
	}
	// exterior loop for each set
	for ( int i = 0; next < count; i++){

		// initial comparison
		int minDelta = abs ( remaining[i] - remaining[next]);
		for( int j = next; j < count; j ++){
			// check if head is in curent location
			if ( remaining[i] != remaining[j]){

				int delta = abs (remaining[i] - remaining[j]);
				// if lower, keep
				if ( delta < minDelta){
					int temp = remaining[next];
					remaining[next] = remaining[j];
					remaining[j] = temp;
					minDelta = delta;
				}
			}
		}
	// increment next for next loop.
	next++;
	time = time + minDelta;
	}
printf("SSTF total Time: %d \n", time);
}

