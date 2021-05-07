#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<time.h>
#include "liste.h"
#include "pile.h"
#include "load.h"
#include "affichage.h"
#include "save.h"
#include <MLV/MLV_all.h>
#define LARGEUR 1300
#define HAUTEUR 720
#define MAX_LINE_LENGTH 15

int main(){
  int x,y;
  int click=1;
  srand(time(NULL));
  pile tab;
  tab = loadFromfile("./example/ex1.txt");
  saveFromTab("./saves/save1.txt", tab, 2,2);

MLV_create_window("KPPV","iconetest",LARGEUR,HAUTEUR);
MLV_clear_window( MLV_COLOR_GREY20);
mode_creation(LARGEUR,HAUTEUR);
mode_kppv(LARGEUR,HAUTEUR);
vakeur_k(LARGEUR, HAUTEUR,"valeur de K");
reinitialisation_fenetre(LARGEUR,HAUTEUR);
zone_affichage(LARGEUR,HAUTEUR);
efface_dernier_point(LARGEUR,HAUTEUR);
classe_manuel(LARGEUR,HAUTEUR);
option_affichage(LARGEUR,HAUTEUR);
voisinage(LARGEUR,HAUTEUR);
avec_prise_decision(LARGEUR,HAUTEUR);
save_donnees(LARGEUR,HAUTEUR);
charge_fichier(LARGEUR,HAUTEUR);
MLV_actualise_window();
while(click == 1){
  verif_position(x,y);
  ajouter_point(x,y);
  MLV_actualise_window();
}
MLV_wait_seconds(360);
MLV_free_window();


exit(EXIT_SUCCESS);
}
