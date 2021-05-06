#include "affichage.h"
#include <MLV/MLV_all.h>

void mode_creation(int x, int y){
    char c[20]="mode creation";
    int width_text,height_text,positionX;
    MLV_get_size_of_text( c, &width_text, &height_text );
    positionX = x/50;
    MLV_draw_adapted_text_box(positionX,y/100,c,MLV_COLOR_WHITE,0,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
}

void mode_kppv(int x, int y){
    char c[20]="mode KPPV";
    int width_text,height_text,positionX;
    MLV_get_size_of_text( c, &width_text, &height_text );
    positionX = (x-width_text)/9+width_text;
    MLV_draw_adapted_text_box(positionX,y/100,c,MLV_COLOR_WHITE,0,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);

}

void vakeur_k(int x, int y,char * s){
    int width_text,height_text,positionX;
    MLV_get_size_of_text( s,&width_text,&height_text );
    positionX = (x-width_text)/2-width_text;
    MLV_draw_adapted_text_box(positionX,y/100,s,MLV_COLOR_WHITE,0,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);

}

void rein_fenetre(int x, int y){
    char c[40]="reinitialisation de la fenetre";
    int width_text,height_text,positionX;
    MLV_get_size_of_text( c,&width_text,&height_text );
    positionX = (x-width_text-20);
    MLV_draw_adapted_text_box(positionX,y%3,c,MLV_COLOR_WHITE,0,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);

}

void zone_affichage(int x, int y){


    MLV_draw_rectangle(x/50,y/20,650,650,MLV_COLOR_WHITE);
    MLV_draw_line(x/50+325,y/20,x/50+325,y/20+650,MLV_COLOR_WHITE);
    MLV_draw_line(x/50,y/20+325,x/50+650,y/20+325,MLV_COLOR_WHITE);

}

void efface_dernier_point(int x, int y){
    char c[50]="Effacement du dernier point en mode decision";
    MLV_draw_adapted_text_box(x/50+650,y/10,c,MLV_COLOR_WHITE,0,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);

}

void classe_manuel(int x, int y){
    char c[50]="classer mauellement mode creation";
    MLV_draw_adapted_text_box(x/50+650,y/20,c,MLV_COLOR_WHITE,0,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
}

void option_affichage(int x, int y){
    char c[20]="Options d'affichage";
    int width_text,height_text,positionX;
    MLV_get_size_of_text( c, &width_text, &height_text );
    positionX = (x*0.78);
    MLV_draw_adapted_text_box(positionX,y/3,c,MLV_COLOR_WHITE,0,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);

}

void voisinage(int x, int y){
    char c[20]=" voisinage";
    int width_text,height_text,positionX;
    MLV_get_size_of_text( c,&width_text,&height_text );
    positionX = (x*0.75);
    MLV_draw_adapted_text_box(positionX,y/2.6,c,MLV_COLOR_WHITE,0,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
}

void avec_prise_decision(int x, int y){
    char c[25]=" avec prise de decision";
    int width_text,height_text,positionX;
    MLV_get_size_of_text( c,&width_text,&height_text );
    positionX = (x*0.75);
    MLV_draw_adapted_text_box(positionX,y/2.3,c,MLV_COLOR_WHITE,0,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
}

void save_donnees(int x, int y){
    char c[50]="sauvegarde de donnees entrees";
    int width_text,height_text,positionX;
    MLV_get_size_of_text( c,&width_text,&height_text );
    positionX = (x*0.975)-width_text;
    MLV_draw_adapted_text_box(positionX,y*0.95,c,MLV_COLOR_WHITE,0,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
}

void charge_fichier(int x, int y){
    char c[50]="chargement d'un fichier mode creation";
    int width_text,height_text,positionX;
    MLV_get_size_of_text( c, &width_text,&height_text );
    positionX = (x*0.975)-width_text;
    MLV_draw_adapted_text_box(positionX,y*0.9,c,MLV_COLOR_WHITE,0,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
}

/*void test_mouse(int x, int y, int largeur, int hauteur){

    if ( (x>=(largeur/50) && x<=(largeur/50)+100) &&
         (y>=(hauteur/100) && y<=(hauteur/100)+15)){
        MLV_draw_text(largeur/2,hauteur/2,"mode creation pressed",MLV_COLOR_BLUE);
    }
    else if ( (x>=(largeur-75)/9+75 && x<=(((largeur-75)/9+75) + 75) &&
               (y>=hauteur/100 && y<=(hauteur/100)+15))){
        MLV_draw_text(largeur/2,hauteur/2,"mode kppv pressed",MLV_COLOR_CYAN);
    }
}*/

int creer_boutton(int x,int y,int x_zone,int y_zone,int largeur_boutton,int hauteur_boutton){
  if ((x > x_zone)&&(x < (x_zone+largeur_boutton))) {
    if ((y > x_zone)&&(y < (y_zone+hauteur_boutton))){
      return 1;
    }
  }
  return 0;
}

void ajouter_point(int x,int y,){
  if (creer_boutton(x,y,x/50),y/20,650,650) {
    /* code */
  }
}
