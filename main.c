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
  int done;
  x=y=click=done=1;
  srand(time(NULL));
  pile * tab;
  point * myPoint;
  char * path = malloc(sizeof(char *));
  mode = 0;
  if (path == NULL){
    printf("malloc mal passé\n");
  }
  tab = loadFromfile("example/ex1.txt");

general_window(LARGEUR,HAUTEUR,"mode creation","valeur de k");
MLV_actualise_window();

while (done == 1) {
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
      done = 0;
      break;
    case 6:
      MLV_free_window();
      general_window(LARGEUR,HAUTEUR,"mode creation","valeur de k");
      break;
    default:
      break;

    }
  }
  MLV_wait_seconds(5);
  MLV_free_window();


exit(EXIT_SUCCESS);
}
