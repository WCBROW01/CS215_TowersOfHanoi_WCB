#include <stdio.h>
#include <stdlib.h>

void moveOneDisk(int start, int end) {
	printf("Move one disk from %d to %d\n", start, end);
}

void moveTower(int numDisks, int start, int end, int temp) {
	if (numDisks == 1) {
		moveOneDisk(start, end);
	} else {
		moveTower(numDisks - 1, start, temp, end);
		moveOneDisk(start, end);
		moveTower(numDisks - 1, temp, end, start);
	}
}

void solve(int numDisks) {
	moveTower(numDisks, 1, 3, 2);
}

int main(int argc, char *argv[]) {
	if (argc >= 2) {
		solve(atoi(argv[1]));
		return 0;
	} else {
		printf("Quantity of disks to solve not provided.\n");
		return 1;
	}
}
