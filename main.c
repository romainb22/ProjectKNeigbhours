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
/*  srand(time(NULL));
  pile tab;
  tab = loadFromfile("./example/ex1.txt"); */

MLV_create_window("test","iconetest",1000,1000);
/*MLV_draw_rectangle(50,100,400,450,MLV_COLOR_BLUE);*/
mode_creation(1000,1000);
mode_kppv(1000,1000);
vakeur_k(1000, 1000,"lourd");
rein_fenetre(1000, 1000);
zone_affichage(1000, 1000);
efface_dernier_point(1000, 1000);
classe_manuel(1000, 1000);
option_affichage(1000, 1000);
voisinage(1000, 1000);
avec_prise_decision(1000, 1000);
save_donnees(1000, 1000);
charge_fichier(1000,1000);

MLV_actualise_window();
MLV_wait_seconds(20);
MLV_free_window();


exit(EXIT_SUCCESS);
}
