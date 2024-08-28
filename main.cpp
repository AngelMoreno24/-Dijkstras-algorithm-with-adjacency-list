//Name: Angel Moreno
//ASU ID: 1219993034

#include "util.h"
#include "heap.h"
#include "graph.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;

int main(int argc, char *argv[]){
  
  if (argc < 3){

    cout << "./PJ3 <GraphType> <InputFile>" << endl;

    exit (1);
  }

  string arg =std::string(argv[1]);
  string arg2 =std::string(argv[2]);

  int ADT;
  int f;

  if(arg == "Directed" || arg=="Undirected"){
    if(arg == "Directed")
      ADT=1;

    if(arg == "Undirected")
      ADT=2;

    
  }else{
    cout << "./PJ3 <GraphType> <InputFile>" << endl;

    return 0;
  }

if(arg2 == "network01.txt" || arg2=="network02.txt" || arg2=="network03.txt"){
  if(arg2 == "network01.txt")
    f=1;

  if(arg2 == "network02.txt")
    f=2;

  if(arg2 == "network03.txt")
    f=3;

 
 }else{
  cout << "./PJ3 <GraphType> <InputFile>" << endl;

   return 0;
 }

 int m,n;
 if(f==3){
   return 0;
 }
 n= 8;
 m= 14;

 NODE * A = new NODE[n];

 
 for(int i=0; i< n; i++){
   A[i].index=i+1;
   A[i].next=NULL;
 
 }
 if(f==3){
   return 0;
 }
 if(f==1){
   read2(1,A,m,f);
 }
 if(f==2 || f==3){
   readU(1,A,m,f);
 }

   //----------------------------------------------------------------------------

   VERTEX * V = new VERTEX[n];

   HEAP *H = new HEAP[n];
   H[0].capacity=n;
   H[0].size=0;

   STACK * S = new STACK[1];



   char word[50];
   int source;
   while (1){
     scanf("%s", word);
     if (strcmp(word, "PrintADJ")==0){
       printADJ(A,n);

     }else if(strcmp(word, "Stop")==0){
       return 0;
     }
     else if(strcmp(word, "SinglePair")==0){

       int s;
       scanf("%d", &s);
       source = s;
       int t;
       scanf("%d", &t);

       D(V, s, t, H, A);

     }else if(strcmp(word, "PrintPath")==0){

       int s;
       scanf("%d", &s);
       int t;
       scanf("%d", &t);

       if(source == s){
	 int check = stack(S, V, t);

	 if(check == 0){
	   printS(S, s, t, V);
	 }else{
	   fprintf(stdout, "There is no path from %d to %d.\n", s, t);
	 }
       }
     }else if(strcmp(word, "SingleSource")==0){

       int s;
       scanf("%d", &s);
       source = s;
       SingleSource( V, s, H, A);
     }else if(strcmp(word, "PrintLength")==0){
       int s;
       scanf("%d", &s);
       int t;
       scanf("%d", &t);

       if(source == s){
         int check = stack(S, V, t);
	 
         if(check == 0){
	   printLength(S, s, t, V);
	 }else{
           fprintf(stdout, "There is no path from %d to %d.\n", s, t);
         }
       }
     }else{

       cerr << "Invalid command\n" << endl;

     }
   }
 }
