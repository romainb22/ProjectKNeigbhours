#include<stdlib.h>
#include<stdio.h>
#include"tableau.h"
#include"point.h"

struct tableau * newTable(int max){
  tableau * tab;
  tab = malloc(sizeof(point)*max+sizeof(int)*2);
  if(tab==NULL){
    printf("Erreur d'allocation !\n");
  }
  tab->nbElem = 0;
  tab->max = max;
  return tab;
}

int addPoint(struct tableau* myTab, struct point* myPoint){
  if(myTab->nbElem < myTab->max){
    myTab->element[nbElem-1] = myPoint;
    myTab->nbElem++;
    return 1;
  }
  else if(myTab->nbElem == myTab->max){
    addPointFull(myTab,myPoint);
    return 1;
  }
  else{
    return 0;
  }
}

int addPointFull(struct tableau* myTab, struct point* myPoint){
  myTab = realloc(myTab,sizeof(point)*((myTab->max)+1)+sizeof(int)*2);
  myTab->max++;
  return addPoint(myTab,myPoint);
}
int removePoint(struct tableau * myTab){
  if(myTab->nbElem==0){
    return 0;
  }
  else{
    deletePoint(myTab[myTab->nbElem]);
    myTab->nbElem--;
    return 1;
  }
}

void deleteTable(struct tableau* myTab){
  if(myTab!=NULL){
    free(myTab);
  }
}
