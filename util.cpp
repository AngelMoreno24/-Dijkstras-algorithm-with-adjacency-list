//Name: Angel Moreno
//ASU ID: 1219993034


#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;


void read(int* n, int* m, int title){
  FILE *file;
  if(title == 1 || title == 2 || title == 3){
    if(title == 1){
      file= fopen("network01.txt", "r");
    }
    if(title == 2){
      file= fopen("network02.txt", "r");
    }
    if(title == 3){
      file= fopen("network03.txt", "r");
    }

    if(file == NULL) {
      cout << "Error: Cannot open file\n" << endl;
      exit (1);
    }

    if(!file){
      cout << "Error: Cannot open file\n" << endl;
      exit (1);
    }

    int c;
    fscanf(file, "%d", &c);
    *n =c;

    fscanf(file, "%d", &c);
    *m =c;

    fclose(file);
  }else{
    

  }
}
