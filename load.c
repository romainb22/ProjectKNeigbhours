#include <stdlib.h>
#include <stdio.h>
#include "tableau.h"
#include "point.h"
#include "load.h"
#define MAX_LINE_LENGTH 15

tableau * loadFromfile(char * path){
  FILE *f = NULL;
  char c[MAX_LINE_LENGTH];
  int nbPoints, dimension, nbClasses,i,classe;
  float x,y;
  tableau * myTab;

  i = -1;
  f = fopen(path,"r");
  if (f!=NULL){
    while (fgets(c,MAX_LINE_LENGTH, f)!=NULL){
      if(i==-1){
        sscanf(c,"%d %d %d", &nbPoints, &dimension, &nbClasses);
        printf(c,"%d %d %d\n", nbPoints, dimension, nbClasses);
      }
      else{
        /* Do nothing */
      }
      i++;
    }
    fclose(f);
    myTab = newTable(nbPoints);
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
        printf("%d %f %f\n", classe, x, y);
        myTab->element[i]= newPoint(x, y, classe);
      }
      i++;
    }
    fclose(f);
  }
  for(i=1;i<nbPoints;i++){
    printf("%f\n",getDistance(myTab->element[i-1],myTab->element[i]));
  }
  return myTab;
}
