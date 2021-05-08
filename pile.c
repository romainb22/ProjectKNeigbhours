#include<stdlib.h>
#include<stdio.h>
#include"pile.h"

pile * pile_vide(){
  pile * myPile;
  myPile = malloc(sizeof(pile));
  myPile->maPile = liste_vide();
  myPile->premier = NULL;
  return myPile;
}

int est_pile_vide(pile * p){
  return est_liste_vide(p->maPile);
}

pile * empiler(pile * p,element e){
  if(est_pile_vide(p)){
    p->premier = &e;
  }
  p->maPile = inserer_element_liste(p->maPile,e);
  return p;
}

element sommet_pile(pile * p){
  return renvoie_premier_liste(p->maPile);
}

pile * depiler(pile * p){
  if(taille_pile(p)==1){
    p->premier = NULL;
  }
  p->maPile = supprimer_premier_liste(p->maPile);
  return p;
}

int taille_pile(pile * p){
  int nb=0;
  p->maPile->objet = *p->premier;
  while(p->maPile->suivant != NULL){
    nb++;
    p->maPile=p->maPile->suivant;
  }
  return nb;
}
