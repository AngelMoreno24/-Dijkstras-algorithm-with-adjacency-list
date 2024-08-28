typedef struct VERTEX{
  int index;
  char * color;
  float key;
  int pi;
  int position;
  VERTEX  *next;
}VERTEX;
typedef VERTEX *pVERTEX;


typedef struct NODE{
  int index;
  int u;
  int v;
  float w;
  NODE *next;
}NODE;
typedef NODE *pNODE;

typedef struct HEAP{
  int capacity;
  int size;
  int vertex;
  float key;
}HEAP;

typedef struct STACK{
  int vertex;
  STACK *next;
  float w;
}STACK;
