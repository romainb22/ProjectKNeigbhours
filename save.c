
#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include "point.h"

void saveFromTab(char * path, pile myTab, int nbDim, int nbClass){
  FILE *f = NULL;
  point *p;
  pile tab = pile_vide();
  f=fopen(path,"w+");
  if(f!=NULL){
    fprintf(f,"%d %d %d\n", taille_pile(myTab), nbDim, nbClass);
    while(!est_pile_vide(myTab)){
      tab = empiler(tab, sommet_pile(myTab));
      myTab = depiler(myTab);
    }
    while(!est_pile_vide(tab)){
      p = sommet_pile(tab);
      tab = depiler(tab);
      fprintf(f, "%d %f %f\n", p->class, p->x, p->y );
    }
  }
  fclose(f);
}
