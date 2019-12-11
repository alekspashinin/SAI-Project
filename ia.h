#ifndef _IA_H_
#define _IA_H_

#include "dessiner.h"



extern liste_perso liste_good;
extern liste_perso liste_bad;
extern int nb_pers;



void kill_the_bastard(liste_perso perso);

void deplacement(liste_perso perso, point target);

void chase_move(liste_perso perso);

point random_pos(liste_perso perso);

void random_move(liste_perso perso);

void move_persos();

#endif