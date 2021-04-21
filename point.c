#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "point.h"
#define MAX 1
#define MIN -1

struct point * newPoint(double x, double y, int class){
  struct point * this;

  this = malloc(sizeof(struct point));
  if(p == NULL){
    printf("Erreur d'allocation !\n");
  }
  else{
    if(!setX(this, x) || !setY(this, y)){
      return NULL;
    }
    setClass(this, class);
  }
  return this;
}

int setX(struct point * this, int x){
  if(x>MAX || x<MIN){
    printf("Coordonées non recevables");
    return 0;
  }
  this->x = x;
  return 1;
}

int setY(struct point * this, int y){
  if(y>MAX || y<MIN){
    printf("Coordonées non recevables");
    return 0;
  }
  this->y = y;
  return 1;
}

void setClass(struct point * this, int class){
  this->class = class;
}

double getDistance(struct point * p1, struct point * p2){
  double d,x1,x2,y1,y2;

  x1 = p1->x;
  x2 = p2->x;
  y1 = p1->y;
  y2 = p2->y;
  d = sqrt( (x1-x2)*(x1-x2) +  (y1-y2)*(y1-y2));
  return d;
}

void deletePoint(struct point * this){
  if(this != NULL){
    free(this);
  }
}
