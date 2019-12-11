#ifndef _COLISION_H_
#define _COLISION_H_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define VIDE 0
#define PLEIN 1
#define WIDTH 200
#define HEIGHT 200

int tab[200][200];

typedef struct{
    double x; 
    double y;//hauteur
    double z;
}point;



void init_colision();

void affiche_colision();

void add_obstacle(point p1,int taille);

int is_accessible(point p1);

#endif