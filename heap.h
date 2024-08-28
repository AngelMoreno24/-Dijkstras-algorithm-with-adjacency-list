//Name: Angel Moreno
//ASU ID: 1219993034

#ifndef DEFNS
#define DEFNS
#include "defns.h"
#endif

void MinHeapify(HEAP t[], int i, VERTEX V[]);

void BuildMinHeap(HEAP t[], VERTEX V[]);

void printMin(HEAP  t[]);

int ExtractMin(HEAP t[], int ADT, VERTEX V[]);

int DecreaseKey(HEAP t[], int pos, int  newKey, int ADT, VERTEX V[]);

int DeleteMin(HEAP t[], int pos, int ADT, VERTEX V[]);

void Insert(HEAP t[], int key, int ADT, VERTEX V[]);

void exchangeMin(HEAP  t[], int i, int largest, VERTEX V[]);

int SingleSource(VERTEX V[], int s, HEAP H[], NODE A[]);

void MoveUp(HEAP  t[], int pos, VERTEX V[]);
