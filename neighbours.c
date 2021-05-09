#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include "point.h"
#include "neighbours.h"

pile * sortByDistance(pile * Pi, point * p){
  pile * res;
  double dMax;
  int i,j=-1;

  res = pile_vide();
  while(taille_pile(res)!=taille_pile(Pi)){
    Pi->maPile = Pi->premier;
    i=0;
    dMax = 0.0;
    while(Pi->maPile->suivant != NULL){
      if (getDistance(p,Pi->maPile->objet)>dMax && j<i){
        dMax = getDistance(p,Pi->maPile->objet);
      }
      i++;
    }
    Pi->maPile = Pi->premier;
    j=i;
    for(i=0;i<=j;i++){
      Pi->maPile->objet = Pi->maPile->suivant;
    }
    res = empiler(res,Pi->maPile->objet);
  }
  return res;
}

pile * removePoint(pile * Pi, point * p){
  pile * res;
  Pi->maPile = Pi->premier;
  while(Pi->maPile->suivant != NULL){
    if((Pi->maPile->objet->x != p->x) && (Pi->maPile->objet->y != p->y) && (Pi->maPile->objet->class != p->class)){
      res = empiler(res, Pi->maPile->objet);
    }
    Pi->maPile->objet = Pi->maPile->suivant;
  }
  return res;
}


pile * kNearestNeighbours(pile * myTab, int k, point * p){
  pile * res, * trans;
  int i;
  trans = pile_vide();
  res = pile_vide();

  trans = sortByDistance(removePoint(myTab,p),p);
  while(!est_pile_vide(trans)){
    res = empiler(res, sommet_pile(trans));
    trans = depiler(trans);
  }
  for(i=0;i<k;i++){
    res->maPile->objet = res->maPile->suivant;
  }
  res->maPile->suivant = NULL;
  return res;
}
