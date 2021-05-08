#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include "point.h"
#include "load.h"
#define MAX_LINE_LENGTH 15

pile * loadFromfile(char * path){
  FILE *f = NULL;
  char c[MAX_LINE_LENGTH];
  int i,classe;
  float x,y;
  pile * myTab = pile_vide();
  point * p;

  p=newPoint();
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
        if(!setX(p, x) || !setY(p, y)){
          /* Do nothing */
        }
        else{
          myTab = empiler(myTab,newPoint());
          if(initPoint(myTab->maPile->objet, x, y, classe)==0){
            printf("Erreur d'initialisation !");
          }
        }
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
