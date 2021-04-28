#ifndef _POINT_H_
#define _POINT_H_

#include<stdlib.h>
#include<stdio.h>

typedef struct point{
  double x;
  double y;
  int class;
}point;

struct point * newPoint(double, double, int);

int setX(struct point*, double);

int setY(struct point*, double);

void setClass(struct point *, int);

double getDistance(struct point *, struct point *);

void deletePoint(struct point *);

#endif
