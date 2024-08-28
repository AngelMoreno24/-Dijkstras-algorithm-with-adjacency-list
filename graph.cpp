//Name: Angel Moreno
//ASU ID: 1219993034

#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
#include <cfloat>

using namespace std;

void read2(int type, NODE A[], int m, int title){
  FILE *file = fopen("network01.txt", "r");

  int n;
  int af;
  int c;

  fscanf(file, "%d", &n);
  fscanf(file, "%d", &m);
  int qwe;
  NODE * q = new NODE[m];

  for(int i=0; i<m;i++){

    fscanf(file, "%d", &qwe);
    fscanf(file, "%d", &q[i].u);
    fscanf(file, "%d", &q[i].v);
    fscanf(file, "%f", &q[i].w);
  }
  for(int j=0;j<n;j++){
    for(int i=0; i<m;i++){
      
      NODE * node = new NODE();
      
      node->u = q[i].u;
      node->v = q[i].v;
      node->w = q[i].w;
      node->next = NULL;

      if(A[j].index == node->u){
	node->next = A[j].next;
	A[j].next = node;

      }
    }
  }
  fclose(file);

}

void readU(int type, NODE A[], int m, int title){
  FILE *file;;
  if(title == 1){
    file= fopen("network01.txt", "r");
  }
  if(title == 2){
    file= fopen("network02.txt", "r");
  }
  if(title == 3){
    file= fopen("network03.txt", "r");

  }

  int n;
  int af;
  fscanf(file, "%d", &n);
  fscanf(file, "%d", &af);
  int qwe;

  NODE * q = new NODE[m];

  for(int i=0; i<m;i++){

    fscanf(file, "%d", &qwe);
    fscanf(file, "%d", &q[i].u);
    fscanf(file, "%d", &q[i].v);
    fscanf(file, "%f", &q[i].w);
  }

  for(int j=0;j<n;j++){
    for(int i=0; i<m;i++){

      NODE * node = new NODE();
      NODE * node2 = new NODE();
      node->u = q[i].u;
      node->v = q[i].v;
      node->w = q[i].w;

      node2->v = q[i].u;
      node2->u = q[i].v;
      node2->w = q[i].w;


      node->next = NULL;
      node2->next = NULL;


      if(A[j].index == node->u){
        node->next = A[j].next;
        A[j].next = node;

	node2->next = A[q[i].v-1].next;
        A[q[i].v-1].next = node2;

      }
    }
  }
  fclose(file);
}

void printADJ(NODE A[], int n){

  NODE * b = new NODE[n];

  for(int i=0;i<n;i++){
    b = A[i].next;
    fprintf(stdout, "ADJ[%d]:", i+1);
    while(b != NULL){
      fprintf(stdout, "-->[%d %d: %4.2f]", b->u, b->v, b->w);
      b = b->next;
    }
    fprintf(stdout,"\n");
  }
}
