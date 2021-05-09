#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_
void mode_creation(int x, int y,char * c);
void mode_kppv(int x, int y);
void vakeur_k(int x, int y,char * s);
void reinitialisation_fenetre(int x, int y);
void zone_affichage(int x, int y);
void efface_dernier_point(int x, int y);
void classe_manuel(int x, int y);
void option_affichage(int x, int y);
void voisinage(int x, int y);
void avec_prise_decision(int x, int y);
void save_donnees(int x, int y);
char * charge_fichier(int x, int y);
int creer_boutton(int x,int y,int x_zone,int y_zone,int largeur_boutton,int hauteur_boutton);
double * ajouter_point(int x,int y);
double * verif_position(int x,int y);
double convert_X(int);
double convert_Y(int);
void general_window(int x ,int y,char * c,char * s);
int change_mode();
#endif
