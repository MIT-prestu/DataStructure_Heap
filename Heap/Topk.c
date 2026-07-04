#include "heap.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


void Swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(HPDatatype* arr, int parent, int size) {
	assert(arr);

	int child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size && arr[child] > arr[child + 1]) {
			child++;
		}

		if (arr[parent] > arr[child]) {
			Swap(&arr[parent], &arr[child]);

			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void Topk(const char* filename, int k) {
	assert(filename);

	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("file open fail");
		return;
	}

	HPDatatype* minHeap = (HPDatatype*)malloc(sizeof(HPDatatype) * k);
	if (minHeap == NULL) {
		perror("malloc fail");
		fclose(fp);
		return;
	}

	for (int i = 0; i < k; i++) {
		if (fscanf(fp, "%d", &minHeap[i]) == EOF) {
			break; 
		}
	}

	for (int i = (k - 2) / 2; i >= 0; i--) {
		AdjustDown(minHeap, i, k);
	}

	HPDatatype val = 0;
	while (fscanf(fp, "%d", &val) != EOF) {
		if (val > minHeap[0]) {
			minHeap[0] = val;
			AdjustDown(minHeap, 0, k); 
		}
	}

	printf("the top %d largest numbers:\n", k);
	for (int i = 0; i < k; i++) {
		printf("%d ", minHeap[i]);
	}
	printf("\n");


	free(minHeap);
	fclose(fp);
}



void CreateDataFile(const char* filename, int n) {
	assert(filename);
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		perror("fail open file");
		return;
	}

	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		int val = rand() % 1000000;
		fprintf(fp, "%d\n", val);
	}

	fclose(fp);

}

int main() {
	const char* filename = "data.txt";
	int  n = 1000000;
	int  k = 10;

	CreateDataFile(filename, n);

	Topk(filename, n, k);
	return 0;
}

