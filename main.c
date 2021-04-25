#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<time.h>
#include "point.h"
#define MAX_LINE_LENGTH 15

point ** loadFromfile(char * path){
  FILE *f = NULL;
  char c[MAX_LINE_LENGTH];
  int nbPoints, dimension, nbClasses,i,classe;
  float x,y;
  point * tab[nbPoints];


  i = -1;
  f = fopen(path,"r");
  if (f!=NULL){
    while (fgets(c,MAX_LINE_LENGTH, f)!=NULL){
      if(i==-1){
        sscanf(c,"%d %d %d", &nbPoints, &dimension, &nbClasses);
      }
      else{
        /* Do nothing */
      }
      i++;
    }
    fclose(f);
  }
  f=fopen(path,"r");
  i = -1;
  if (f!=NULL){
    while (fgets(c, MAX_LINE_LENGTH, f)!=NULL){
      if(i==-1){
        /* Do nothing */
      }
      else{
        sscanf(c,"%d %f %f", &classe, &x, &y);
        tab[i]= newPoint(x, y, classe);
      }
      i++;
    }
    fclose(f);
  }
  for(i=1;i<nbPoints;i++){
    printf("%f\n",getDistance(tab[i-1],tab[i]));
  }
  return tab;
}

int main(){
  srand(time(NULL));
  point ** tableau;
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
  /*for(i=0;i<50;i++){
  x = (double) rand()/RAND_MAX*2.0-1.0;
  y = (double) rand()/RAND_MAX*2.0-1.0;
  tableau[i] = newPoint(x,y,i%2+1);
}
for(i=0;i<49;i++){
printf("%f\n",getDistance(tableau[i],tableau[i+1]));
}*/
tableau = loadFromfile("/example/ex1.txt");

exit(EXIT_SUCCESS);
}
