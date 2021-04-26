#include<stdlib.h>
#include<stdio.h>
#include"point.h"

typedef struct tableau{
  point ** element;
  int nbElem;
  int max;
}tableau;

struct tableau * newTable(int);

int addPoint(struct tableau*, struct point*);

int addPointFull(struct tableau*, struct point*);

int removePoint(struct tableau*);

void deleteTable(struct tableau*);
