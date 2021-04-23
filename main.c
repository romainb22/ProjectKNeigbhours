#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<time.h>
#include "point.h"

int main(){
srand(time(NULL));
point * tableau[50];
point *p1;
point *p2;
double x=0.5;
double y=0.2;
int class=2,i,c;
double x2=y;
double y2=x;
c=class-1;
p1=newPoint(x,y,class);
p2=newPoint(x2,y2,c);
getDistance(p1,p2);
printf("%f\n",getDistance(p1,p2));
for(i=0;i<50;i++){
  x = (double) rand()/RAND_MAX*2.0-1.0;
  y = (double) rand()/RAND_MAX*2.0-1.0;
  tableau[i] = newPoint(x,y,i%2+1);
}
for(i=0;i<49;i++){
  printf("%f\n",getDistance(tableau[i],tableau[i+1]));
}

exit(EXIT_SUCCESS);
}
