#include <string.h>
#include "affichage.h"
#include <MLV/MLV_all.h>
#define WINDOW_WIDTH 1300
#define WINDOW_HEIGHT 720

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

void reinitialisation_fenetre(int x, int y){
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

char * charge_fichier(int x, int y){
    MLV_Input_box *input_box;
    MLV_Keyboard_button touche;
    char * text;
    char c[50]="chargement d'un fichier mode creation";
    int width_text,height_text,positionX;
    MLV_get_size_of_text( c, &width_text,&height_text);
    positionX = (x*0.975)-width_text;
    input_box=MLV_create_input_box(positionX,y*0.9,300,25,MLV_COLOR_WHITE,MLV_COLOR_RED,MLV_COLOR_BLACK,c);
    MLV_draw_all_input_boxes();
    if( MLV_get_event (&touche, NULL, NULL,NULL, NULL,NULL, NULL, NULL,NULL) == MLV_NONE || touche == MLV_KEYBOARD_RETURN){
      return text;
      //MLV_draw_adapted_text_box(positionX,y*0.9,c,MLV_COLOR_WHITE,0,MLV_COLOR_RED,MLV_COLOR_BLACK,MLV_TEXT_CENTER);
    }
    MLV_actualise_window();
    return "/";
}

int creer_boutton(int x,int y,int x_zone,int y_zone,int largeur_boutton,int hauteur_boutton){
  if ((x > x_zone)&&(x < (x_zone+largeur_boutton))) {
    if ((y > y_zone)&&(y < (y_zone+hauteur_boutton))){
      return 1;
    }
  }
  return 0;
}





double * ajouter_point(int x,int y){
  double * d;
  d = malloc(sizeof(double)*2);
  d[0] = 5.0;
  d[1] = 5.0;
  if (creer_boutton(x,y,WINDOW_WIDTH/50,WINDOW_HEIGHT/20,650,650)){
    MLV_draw_filled_circle(x,y,2,MLV_COLOR_RED);
    MLV_actualise_window();
    d[0] = convert_X(x);
    d[1] = convert_Y(y);
  }
  return d;
}

double * verif_position(int x,int y){
  MLV_wait_mouse(&x,&y);
  double * def;
  def = malloc(sizeof(double)*2);
  def[0] = 5.0;
  def[1] = 5.0;
  if(x>25 && y>36){
    if (creer_boutton(x,y,WINDOW_WIDTH/50,WINDOW_HEIGHT/20,650,650)){
      return ajouter_point(x,y);
    }
  }
  else{
    /* on est en dehors de la zone */
  }
  return def;
}

double convert_X(int x){
  return (x-351)/325.0;
}


double convert_Y(int y){
  return (351-y)/325.0;
}
