#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<time.h>
#include "liste.h"
#include "pile.h"
#include "load.h"
#include "affichage.h"
#include "save.h"
#include "neighbours.h"
#include <MLV/MLV_all.h>
#define LARGEUR 1300
#define HAUTEUR 720
#define MAX_LINE_LENGTH 15

int main(){
  int mode;
  int x,y,click;
  x=y=click=1;
  srand(time(NULL));
  pile * tab;
  point * myPoint;
  char * path = malloc(sizeof(char *));
  if (path == NULL){
    printf("malloc mal passé\n");
  }
  tab = loadFromfile("example/ex1.txt");

general_window(LARGEUR,HAUTEUR,"mode creation","valeur de k");
MLV_actualise_window();
MLV_draw_rectangle(x/50+650,154,650,20,MLV_COLOR_WHITE);
//MLV_draw_rectangle(x/50+650,y/5+20,650,20,MLV_COLOR_RED);
//MLV_draw_rectangle(x/50+650,y/4+20,650,20,MLV_COLOR_GREEN);
//MLV_draw_rectangle(x/50+650,y/1.2+20,650,20,MLV_COLOR_YELLOW);
//MLV_draw_rectangle(x/50+650,y/1.1+20,650,20,MLV_COLOR_BROWN);
MLV_actualise_window();



while (1) {
  printf("%d\n",mode);
  MLV_actualise_window();
  mode = 0;
  mode=change_mode();
  switch (mode) {
    case 1 :
      //wip
      break;
    case 2:
      //wip
      break;
    case 3:
      while (1) {
        if (change_mode() == 3){
          break;
        }
        MLV_wait_mouse(&x,&y);
        ajouter_point(x,y);
        myPoint = newPoint();
        initPointFromClick(myPoint, verif_position(x,y));
        tab = empiler(tab, myPoint);
        MLV_actualise_window();
      }

    case 4:
      //wip
      break;
    case 5:
      saveFromTab("./saves/save1.txt", tab, 2, 2);
      break;
    case 6:
      MLV_free_window();
      general_window(LARGEUR,HAUTEUR,"mode creation","valeur de k");
      break;
    default:
      break;

    }
  }
  MLV_wait_seconds(360);
  MLV_free_window();


exit(EXIT_SUCCESS);
}
