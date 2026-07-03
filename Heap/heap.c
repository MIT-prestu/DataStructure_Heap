#include "heap.h"


void HeapInit(Heap* php) {
	assert(php);
	
	php->arr = NULL;
	php->size = php->capacity = 0;
}


void HeapDestroy(Heap* php) {
	assert(php);
	
	free(php->arr);
	php->arr = NULL;
	php->size = php->capacity = 0;
}

void Swap(HPDatatype* p1, HPDatatype* p2) {
	assert(p1 && p2);
	
	HPDatatype tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void HeapAdjustUp(HPDatatype* arr, int child) {
	assert(arr);

	//Big: >
	//Small: <
	while (child > 0) {
		int parent = (child - 1) / 2;


		if (arr[child] > arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			child = parent;
		}
		else {
			break;
		}
	}
	
}



void HeapPush(Heap* php, HPDatatype x) {
	assert(php);

	 
	if (php->size == php->capacity) {
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDatatype* tmp = (HPDatatype*)realloc(php->arr, newcapacity * sizeof(HPDatatype));
		if (tmp == NULL) {
			perror("realloc fail");
			exit(-1);
		}
		php->arr = tmp;
		php->capacity = newcapacity;
	}
	

	php->arr[php->size] = x;
	HeapAdjustUp(php->arr, php->size);
	php->size++;
}


void HeapAdjustDown(HPDatatype* arr, int parent, int size) {
	assert(arr);

	int child = parent * 2 + 1;

	while (child < size) {
		//Big: <
		//Small: >
		if (child + 1 < size && arr[child] < arr[child + 1]) {
			child++;
		}

		//Big: <
		//Small: >
		if (arr[parent] < arr[child]) {
			Swap(&arr[parent], &arr[child]);

			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void HeapPop(Heap* php) {
	assert(php && php->size > 0);

	if (php->size == 1) {
		--php->size;
		return;
	}
	else {
		Swap(&php->arr[0], &php->arr[php->size - 1]);
		--php->size;
		HeapAdjustDown(php->arr, 0, php->size);
	}
}


HPDatatype HeapTop(Heap* php) {
	assert(php && php->size > 0);
	return php->arr[0];
}


// This solution uses the HeapAdjustDown function to create a heap.
// O(N) heap building, which has better constant-factor performance than HeapSort2.
void HeapSort1(HPDatatype* arr, int n) {
	assert(arr);

	for (int i = (n - 2) / 2; i >= 0; i--) {
		HeapAdjustDown(arr, i, n);
	}

	int end = n - 1;
	while (end > 0) {
		Swap(&arr[0], &arr[end]);
		HeapAdjustDown(arr, 0, end);
		end--;
	}

}


// This solution uses the HeapAdjustUp function to create a heap.
// O(N*logN) heap building.
void HeapSort2(HPDatatype* arr, int n) {
	assert(arr);

	for (int i = 0; i < n; i++) {
		HeapAdjustUp(arr, i);
	}

	int end = n - 1;
	while (end > 0) {
		Swap(&arr[0], &arr[end]);
		HeapAdjustDown(arr, 0, end);
		end--;
	}
}