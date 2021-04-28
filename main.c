#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<time.h>
#include "point.h"
#include "tableau.h"
#include "load.h"
#define MAX_LINE_LENGTH 15

int main(){
  srand(time(NULL));
  point *p1;
  point *p2;
  double x=0.5;
  double y=0.2;
  int class=2,c;
  double x2=y;
  double y2=x;
  tableau *tab;

  c=class-1;
  p1=newPoint(x,y,class);
  p2=newPoint(x2,y2,c);
  getDistance(p1,p2);
  printf("%f\n",getDistance(p1,p2));
  tab = loadFromfile("/example/ex1.txt");

exit(EXIT_SUCCESS);
}
