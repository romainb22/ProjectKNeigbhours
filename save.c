
#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include "point.h"

void saveFromTab(char * path, pile myTab, int nbDim, int nbClass){
  FILE *f = NULL;
  point *p;
  f=fopen(path,"w+");
  if(f!=NULL){
    fprintf(f,"%d %d %d\n", taille_pile(myTab), nbDim, nbClass);
    while(!est_pile_vide(myTab)){
      p = sommet_pile(myTab);
      myTab = depiler(myTab);
      fprintf(f, "%d %f %f\n", p->class, p->x, p->y );
    }
  }
  fclose(f);
}
