#ifndef _PERSON_H_
#define _PERSON_H_

#include"colision.h"

#define GOOD 1
#define BAD 2

#define CHASE 1
#define RANDOM 2



//les infos du perso : position,vie, vitesse de mouvement, range de vision autour, type :0->mechant 1->gentil
typedef struct{
    int id;
    point position; //poisition du perso
    point direction; //position de l'enemy
    int vie;
    double vitesse;
    int range;
    int stamina; 
    int type; //good || bad
    int id_target; 
    int mode; //chase or random
    
}perso;


typedef struct cellule{
    perso p;
    struct cellule * suivant;
}cellule;


//int nb_perso=0;
//perso tab_pers[6];
typedef cellule * liste_perso;



int est_liste_vide(liste_perso p);

int distance(point p1, point p2);

point position_alea_perso();

liste_perso search_bad_by_id(int id);

liste_perso search_good_by_id(int id);

liste_perso inserer_good_perso(perso p);

liste_perso supprimer_good(int valeur);

liste_perso inserer_bad_perso(perso p);

liste_perso supprimer_bad(int valeur);

perso creer_good(point pos);

perso creer_bad(point pos);

#endif