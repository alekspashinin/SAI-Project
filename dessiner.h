/**
 *
 *            L'Université Jean Monnet
 *
 *         Dimitrios Soupilas * Riad Lazli
 *                Aleksei Pashinin
 *
 *                  Projet SAI
 *
 */

#ifndef _DESSINER_H_
#define _DESSINER_H_

#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"person.h"
#include "eau.h"



#define PI 3.14159
#define BASE_HEIGHT 4.0/6
#define BASE_RADIUS 1.0/6
#define HEAD_HEIGHT 1.25/6
#define HEAD_RADIUS 0.75/6
#define NECK_HEIGHT 0.5/6
#define LOWER_ARM_HEIGHT 2.0/6
#define LOWER_ARM_WIDTH 0.5/6
#define UPPER_ARM_HEIGHT 1.25/6
#define UPPER_ARM_WIDTH 0.5/6
#define ARM_TRANSLATION 0.22/6
#define HUMAN 1
#define ALIEN 2


extern liste_perso liste_good;
extern liste_perso liste_bad;
extern int nb_pers;

/* dessinage des chars */
void corps(int unit);

void cou(int unit);

void tete(int unit);

void lower_rmain(int unit);

void lower_lmain(int unit);

void upper_rmain(int unit);

void upper_lmain(int unit);

void DessinerChar(int unit);

void DessinerCharCoordonees(int unit, int x , int y, int z);

/* affichage principale */
void display(void);

/* initialisation des textures */
void initTexture(void);

/* redessinage */
void redisplayAll(void);

void DessinerSkybox(double D);

void displayInit(void);

/* dessinage des obstacles */
void DessinerMaison(void);

void DessinerCylinder();

void DessinerPyramide(float yval, float scale, GLuint texture);

void DessinerTree();

void DessinerBilboard(void);

void changeSize(int w, int h);

void DessinerScene(void);


void ClavierCamera(int key, int xx, int yy);

void ClavierChar(unsigned char key, int x, int y);
void ClavierChar2(unsigned char key, int x, int y);

int RandomCoord(int min, int max);


#endif