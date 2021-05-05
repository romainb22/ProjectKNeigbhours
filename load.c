#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include "point.h"
#include "load.h"
#define MAX_LINE_LENGTH 15

pile loadFromfile(char * path){
  FILE *f = NULL;
  char c[MAX_LINE_LENGTH];
  int nbPoints, dimension, nbClasses,i,classe;
  float x,y;
  pile * myTab = pile_vide();

  /*i = -1;
  f = fopen(path,"r");
  if (f==NULL){
    perror("ERROR");
  }
  else {
    while (fgets(c,MAX_LINE_LENGTH, f)!=NULL){
      if(i==-1){
        sscanf(c,"%d %d %d", &nbPoints, &dimension, &nbClasses);
      }
    }
    i++;
  }
  fclose(f);
  myTab = newTable(nbPoints);*/
  f=fopen(path,"r");
  i = -1;
  if (f!=NULL){
    while (fgets(c, MAX_LINE_LENGTH, f)!=NULL){
      if(i==-1){
        /* Do nothing */
      }
      else{
        sscanf(c,"%d %f %f\n", &classe, &x, &y);
        printf("%d %f %f\n", classe, x, y);
        myTab = empiler(myTab,newPoint(x, y, classe)); /* SIGSEV from here */
      }
      i++;
    }
    fclose(f);
  }
  printf("n\n");
  /*for(i=1;i<nbPoints;i++){
    printf("%f\n",getDistance(myTab->element[i-1],myTab->element[i]));
  }*/
  return myTab;
}
