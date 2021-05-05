#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<time.h>
#include "liste.h"
#include "pile.h"
#include "load.h"
#include "affichage.h"
#include <MLV/MLV_all.h>
#define MAX_LINE_LENGTH 15

int main(){
  srand(time(NULL));
  pile tab;
  tab = loadFromfile("./example/ex1.txt");

MLV_create_window("P","iconetest",1280,720);
MLV_clear_window( MLV_COLOR_GREY20);
mode_creation(1280,720);
mode_kppv(1280,720);
vakeur_k(1280, 720,"valeur de K");
rein_fenetre(1280,720);
zone_affichage(1280,720);
efface_dernier_point(1280,720);
classe_manuel(1280,720);
option_affichage(1280,720);
voisinage(1280,720);
avec_prise_decision(1280,720);
save_donnees(1280,720);
charge_fichier(1280,720);

MLV_actualise_window();
MLV_wait_seconds(20);
MLV_free_window();


exit(EXIT_SUCCESS);
}
