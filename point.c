#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"point.h"
#define MAX 1
#define MIN -1

struct point * newPoint(){
  struct point * this;
  this = malloc(sizeof(struct point));

  if(this == NULL){
    printf("Erreur d'allocation !\n");
  }
  return this;
}

int initPoint(point * myPoint, double x, double y, int class){
  if((!setX(myPoint,x)) || !setY(myPoint, y)){
    return 0;
  }
  setClass(myPoint, class);
  return 1;
}


int initPointFromClick(point* myPoint, double * coord){
  if(!setX(myPoint, coord[0]) || !setY(myPoint, coord[1])){
    return 0;
  }
  setClass(myPoint, -1);
  return 1;
}


int setX(struct point * this, double x){
  if(x>MAX || x<MIN){
    printf("Coordonées non recevables !\n");
    return 0;
  }
  this->x = x;
  return 1;
}

int setY(struct point * this, double y){
  if(y>MAX || y<MIN){
    printf("Coordonées non recevables !\n");
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
