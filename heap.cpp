//Name: Angel Moreno
//ASU ID: 1219993034


#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
#include <cfloat>

using namespace std;


void MinHeapify(HEAP t[], int i, VERTEX V[]){

  int largest;
  int l = 2*i+1;
  int r = 2*i+2;

  if(l < t[0].size && t[l].key < t[i].key){
    largest = l;
  }else{
    largest = i;
  }

  if(r < t[0].size && t[r].key < t[largest].key){
    largest = r;
  }
  if(largest != i){

    exchangeMin(t, i, largest,V);
    MinHeapify(t, largest,V);

  }
}

void BuildMinHeap(HEAP t[], VERTEX V[]){

  int size = (floor(t[0].size/2-1));

  for(int i=size;i>=0;i--){
    MinHeapify(t,i,V);
  }

}

void printMin(HEAP t[]){

  cout << "MinHeap: ";
  for(int i=0;i<(t[0].size-1);i++){
    cout << "vertex = " << t[i].vertex << "key = " << t[i].key << ", ";
  }
  int last;
  last = t[0].size-1;
  cout <<"vertex = " << t[last].vertex << "key = " << t[last].key << endl;

}

int ExtractMin(HEAP t[], int ADT, VERTEX V[]){
  int element;
  if(t[0].size < 1){
    cout << "error: heap empty" << endl;

  }else{
    element =  DeleteMin(t, 0, ADT, V);
    
  }

  return element;
}

int DecreaseKey(HEAP  t[], int pos, int  newKey, int ADT, VERTEX V[]){
  int key = t[pos].key;

  if (pos < 1 || pos > t[0].size || newKey > t[pos].key){
    return 1;

  }
    
  
  t[pos].key = newKey;
  MoveUp(t,pos,V);
  return 0;
}

void MoveUp(HEAP  t[], int pos, VERTEX V[]){

  int parent, temp;

  parent = pos/2;
  if(pos>1 && t[pos].key < t[parent].key){
    temp = t[pos].vertex;
    t[pos].vertex = t[parent].vertex;
    t[parent].vertex= temp;

    V[t[pos].vertex].position = pos;
    V[t[parent].vertex].position = parent;

    MoveUp(t, parent, V);
  }

}

int DeleteMin(HEAP  t[], int pos, int ADT, VERTEX V[]){
  if(ADT == 2 || ADT == 3){

    if(pos < t[0].size ){
      int element = t[pos].vertex;
      int last = t[0].size-1;
      t[pos].vertex = t[t[0].size-1].vertex;
      t[pos].key = t[t[0].size-1].key;
      t[0].size = t[0].size-1;

      if(pos > 1 && pos < t[0].size && t[pos].vertex > t[pos/2].vertex){
        while(pos > 1 && t[pos].vertex > t[pos/2].vertex){

          exchangeMin(t, pos, (pos/2), V);
          pos = pos/2;
        }
      }else{

      }
      return element;
    }
  }
}

void Insert(HEAP t[], int key, int ADT, VERTEX V[]){

    t[0].size = t[0].size+1;
    t[t[0].size-1].key = key;
    t[t[0].size-1].vertex = ADT+1;

}

void exchangeMin(HEAP  t[], int i, int largest, VERTEX V[]){

  float tmp = t[i].key;
  t[i].key = t[largest].key;
  t[largest].key = tmp;

  int tmp1 = t[i].vertex;
  t[i].vertex = t[largest].vertex;
  t[largest].vertex = tmp1;
 
}

int D(VERTEX V[], int s, int t, HEAP H[], NODE A[]){

  for(int i=0;i<8;i++){
    V[i].index = i;
    V[i].color = "white";
    V[i].key = FLT_MAX;
    V[i].pi = NULL;
  }
  V[s-1].key=0;
  V[s-1].color = "grey";
  H[0].size=1;
  H[0].vertex= s;
  H[0].key=V[s].key;

  while(H[0].size != 0){
    int q = ExtractMin(H,2,V);

    V[q-1].color = "black";
    
    if(q == t){
      return 0;
    }
    NODE * b = new NODE[H[0].capacity];
    b = A[q-1].next;
    
    while(b != NULL){
      int v = b->v-1;
      int u = b->u-1;
      int w = b->w;
      
      
      if(V[v].color=="white"){
	V[v].key = V[u].key + w;
	V[v].pi= u;
	V[v].color= "grey";
	
	Insert(H,V[v].key,v,V);
	
	V[v].position = H[0].size-1;

      }else if(V[v].key > V[u].key + w){

	V[v].key = V[u].key + w;
	V[v].pi = u;
	DecreaseKey(H, V[v].position, V[v].key, v, V);
      }
      
      b = b->next;
    }
  }
  return 1;
}

int SingleSource(VERTEX V[], int s, HEAP H[], NODE A[]){

  for(int i=0;i<8;i++){
    V[i].index = i;
    V[i].color = "white";
    V[i].key = FLT_MAX;
    V[i].pi = NULL;
  }
  V[s-1].key=0;
  V[s-1].color = "grey";
  H[0].size=1;
  H[0].vertex= s;
  H[0].key = 0; //V[s].key;//recent change; s to s-1

  while(H[0].size != 0){
    int q = ExtractMin(H,2,V);
    V[q-1].color = "black";


    NODE * b = new NODE[H[0].capacity];
    b = A[q-1].next;

    while(b != NULL){
      int v = b->v-1;
      int u = b->u-1;
      int w = b->w;

      if(V[v].color=="white"){
        V[v].key = V[u].key + w;
        V[v].pi= u;
        V[v].color= "grey";

        Insert(H,V[v].key,v,V);

        V[v].position = H[0].size-1;

      }else if(V[v].key > V[u].key + w){

        V[v].key = V[u].key + w;
        V[v].pi = u;
        DecreaseKey(H, V[v].position, V[v].key, v, V);
      }

      b = b->next;
    }
  }
  return 1;
}


