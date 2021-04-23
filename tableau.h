#include<stdlib.h>
#include<stdio.h>
#include"point.h"

typedef struct tableau{
  point ** element;
  int avoir;
}tableau;

struct point * newPoint(double, double, int);

int setX(struct point*, double);

int setY(struct point*, double);

void setClass(struct point *, int);

double getDistance(struct point *, struct point *);

void deletePoint(struct point *);
