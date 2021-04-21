#include <stdlib.h>
#include <stdio.h>
#include "point.h"

int main(){
point *p1;
point *p2;
double x=0.5;
double y=0.2;
int class=2;
double x2=y;
double y2=x;
int c=class;
p1=newPoint(x,y,class);
p2=newPoint(x2,y2,c);
getDistance(p1,p2);
printf("%f\n",getDistance(p1,p2));

exit(EXIT_SUCCESS);
}
