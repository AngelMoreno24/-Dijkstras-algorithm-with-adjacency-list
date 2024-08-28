//Name: Angel Moreno
//ASU ID: 1219993034

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
#include <cfloat>

using namespace std;


int stack(STACK S[], VERTEX V[], int t){
  

  if(V[t-1].pi == NULL && V[t-1].pi != 0 || V[t-1].key == FLT_MAX){
   
    
    return 1;
  }
  
  
  
  int q = t-1;
  
  
  
  q =  V[q].index;
  
  while(V[q].key != NULL){

    if(V[t-1].pi == NULL && V[t-1].pi != 0 ){
   
      
    return 1;
  }

    STACK * node = new STACK();
    
    node->vertex = q+1;    
    node->next = NULL;
    

    node->next = S[0].next;
    S[0].next = node;
    
    
    q= V[q].pi;
    
  }
  STACK * node = new STACK();
  node->vertex = q+1;
  node->next = NULL;

  node->next = S[0].next;
  S[0].next = node;
  return 0;
}
void printS(STACK S[], int s, int t, VERTEX V[]){

  STACK * b = new STACK();


  fprintf(stdout, "The shortest path from %d to %d is:\n", s, t);
  b = S[0].next;

  while(b != NULL){

    if(b->vertex == t)
      break;

    fprintf(stdout, "[%d:%8.2f]-->", b->vertex, V[b->vertex-1].key);
    b = b->next;
  }
  fprintf(stdout, "[%d:%8.2f].", b->vertex, V[b->vertex-1].key);
  cout << endl;
}
 
void printLength(STACK S[], int s, int t, VERTEX V[]){

  fprintf(stdout, "The length of the shortest path from %d to %d is: %8.2f\n", s, t, V[t-1].key);

}
