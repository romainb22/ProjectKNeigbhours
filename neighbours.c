#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include "point.h"
#include "neighbours.h"

pile kNearestNeighbours(pile myTab, int k, point * p){
  pile res, trans, myTabPtr, transPtr, nearestPtr;
  res = pile_vide();
  trans = pile_vide();
  myTabPtr = pile_vide();
  transPtr = pile_vide();
  nearestPtr = pile_vide();
  myTabPtr = myTab;
  double dMin;
  point * nearest;

  if(k>=taille_pile(myTab)){
    return myTab;
  }

  while(myTab->suivant != NULL){
    trans = empiler(trans, myTab->objet);
    myTab = myTab->suivant;
  }

  while(taille_pile(res)<=k){
    while(getDistance(trans->objet, p)==0.0){
      if(trans->suivant != NULL){
          trans = trans->suivant;
      }
      else{
        break;
      }
    }
    dMin = getDistance(trans->objet, p);
    nearest = trans->objet;
    while(trans->suivant != NULL){
      trans = trans->suivant;
      if(getDistance(trans->objet, p) < dMin){
        dMin = getDistance(trans->objet, p);
        nearest = trans->objet;
      }
    }
    while(trans->suivant->objet != nearest){
      trans = trans->suivant;
    }
    res=empiler(res, nearest);
    trans->suivant = trans->suivant->suivant; //supression du point le plus proche dans la liste de transition.
    trans = depiler(trans); // faut-t'il dépiler pour correspondre ?
  }
  return res;
}
