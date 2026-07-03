#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>



typedef int HPDatatype;
typedef struct Heap {
	HPDatatype* arr;
	int size;
	int capacity;
}Heap;


void HeapInit(Heap* php);

void HeapDestroy(Heap* php);

void HeapPush(Heap* php, HPDatatype x);

void HeapAdjustUp(HPDatatype* arr, int child);

void HeapPop(Heap* php);

void HeapAdjustDown(HPDatatype* arr, int parent, int size);

HPDatatype HeapTop(Heap* php);

void HeapSort1(HPDatatype* arr, int n);
void HeapSort2(HPDatatype* arr, int n);


