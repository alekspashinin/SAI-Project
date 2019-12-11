#ifndef _EAU_H_
#define _EAU_H_

/**
 *
 *            L'Université Jean Monnet
 *
 *         Dimitrios Soupilas * Riad Lazli
 *                Aleksei Pashinin
 *
 *                  Projet SAI
 *
 *          made by Zavie (Julien Guertault)
 *
 */
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdio.h>
#include <jpeglib.h>
#include <jerror.h>
#include <math.h>

#define		RESOLUTION 64

void		InitNoise (void);
float		Noise (const float, const float, const float, const float);
void DessinerOcean(void);
int load_texture(const char *filename, unsigned char *dest, const int format, const unsigned int size);

#endif		// NOISE_HH
