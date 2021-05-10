#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include "point.h"

void saveFromTab(char * path, pile * myTab, int nbDim, int nbClass){
  FILE *f = NULL;
  f=fopen(path,"w+");
  myTab->maPile->objet = *myTab->premier;
  if(f!=NULL){
    fprintf(f,"%d %d %d\n", taille_pile(myTab), nbDim, nbClass);
    while(!est_pile_vide(myTab)){
      printf("Point from Tab : (%f,%f)\n", sommet_pile(myTab)->x, sommet_pile(myTab)->y);
      fprintf(f, "%d %f %f\n", sommet_pile(myTab)->class, sommet_pile(myTab)->x, sommet_pile(myTab)->y );
      myTab = depiler(myTab);
    }
  }
  fclose(f);
}
