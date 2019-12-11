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

#include "dessiner.h"

/* l'ongle de rotation de camera */
float angle = 0.0;
int cam=1;
/* direction de camera */
float lx = 0.0f, lz = -1.0f, ly = 1.0f;
/* X et Z position de camera */
float x = 0.0f, z = 5.0f, y=1.0f, w=0.0f;

/*liste des testures principale*/
GLuint texture_list[20];
/*liste des testures Skybox*/
GLuint skybox[6];
/* GLUquadricObj pour les textures */
GLUquadricObj *p;



int param1 = 1;
int param2 = 1;
double dim = 50;
double fov = 100;
double asp = 1;
static GLfloat theta_human[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
static GLfloat theta_alien[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};



/*
 *  Dessiner Le Corps de personnage
 */
void corps(int unit) {
    glEnable(GL_TEXTURE_2D);
    if (unit == 1) {
        glColor3f(1.0, 1.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, texture_list[2]);
        glPushMatrix();
        gluQuadricTexture(p, 1);
        gluQuadricNormals(p, GLU_SMOOTH);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        gluQuadricDrawStyle(p, GLU_FILL);
        gluCylinder(p, BASE_RADIUS, BASE_RADIUS, BASE_HEIGHT, 20, 20);
        glPopMatrix();

        glPushMatrix();
        gluQuadricDrawStyle(p, GLU_FILL);
        glTranslatef(0.0, BASE_HEIGHT, 0.0);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        gluDisk(p, 0.0, BASE_RADIUS, 20, 20);
        glTranslatef(0.0, 0.0, -BASE_HEIGHT);
        gluDisk(p, 0.0, BASE_RADIUS, 20, 20);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    } else {
        glColor3f(1.0, 1.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, texture_list[5]);
        glPushMatrix();
        gluQuadricTexture(p, 1);
        gluQuadricNormals(p, GLU_SMOOTH);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        gluQuadricDrawStyle(p, GLU_FILL);
        gluCylinder(p, BASE_RADIUS, BASE_RADIUS, BASE_HEIGHT, 20, 20);
        glPopMatrix();

        glPushMatrix();
        gluQuadricDrawStyle(p, GLU_FILL);
        glTranslatef(0.0, BASE_HEIGHT, 0.0);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        gluDisk(p, 0.0, BASE_RADIUS, 20, 20);
        glTranslatef(0.0, 0.0, -BASE_HEIGHT);
        gluDisk(p, 0.0, BASE_RADIUS, 20, 20);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
    }
}

/*
 *  Dessiner le Cou de personnage
 */
void cou(int unit) {
    glPushMatrix();
    p = gluNewQuadric();
    if (unit == 1) {
        glColor3f(1.0, 1.5, 0.0);
        glTranslatef(0.0, BASE_HEIGHT, 0.0);
    } else {
        glColor3f(0.0, 1.0, 0.0);
        glTranslatef(0.0, BASE_HEIGHT, 0.0);
    }
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluQuadricDrawStyle(p, GLU_FILL);
    gluCylinder(p, HEAD_RADIUS / 2, HEAD_RADIUS / 2, HEAD_HEIGHT / 2, 8, 6);
    glPopMatrix();
}

/*
 *  Dessiner La Tete
 */
void tete(int unit) {
    glEnable(GL_TEXTURE_2D);
    if (unit == 1) {
        glColor3f(1.0, 1.0, 0.0);
        glBindTexture(GL_TEXTURE_2D, texture_list[1]);
    } else {
        glColor3f(0.0, 1.0, 0.0);
        glBindTexture(GL_TEXTURE_2D, texture_list[4]);
    }
    glPushMatrix();
    gluQuadricTexture(p, 1);
    gluQuadricNormals(p, GLU_SMOOTH);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluQuadricDrawStyle(p, GLU_FILL);
    gluCylinder(p, HEAD_RADIUS, HEAD_RADIUS, HEAD_HEIGHT, 20, 20);

    glPushMatrix();
    gluDisk(p, 0.0, HEAD_RADIUS, 20, 20);
    glTranslatef(0.0, 0.0, HEAD_HEIGHT);
    gluDisk(p, 0.0, HEAD_RADIUS, 20, 20);
    glPopMatrix();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

/*
 *  Dessiner Main Droite Bas
 */
void lower_rmain(int unit) {
    glPushMatrix();
    if (unit == 1) {
        glColor3f(1.0, 1.0, 0.0);
    } else {
        glColor3f(0.0, 1.0, 0.0);
    }
    glTranslatef(0.0, 0.5 * LOWER_ARM_HEIGHT, ARM_TRANSLATION);
    glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
    glutSolidCube(1.0);
    glPopMatrix();
}

/*
 *  Dessiner Main Gauche Bas
 */
void lower_lmain(int unit) {
    glPushMatrix();
    if (unit == 1) {
        glColor3f(1.0, 1.0, 0.0);
    } else {
        glColor3f(0.0, 1.0, 0.0);
    }
    glTranslatef(0.0, 0.5 * LOWER_ARM_HEIGHT, -ARM_TRANSLATION);
    glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
    glutSolidCube(1.0);
    glPopMatrix();
}

/*
 *  Dessiner Main Droite Haut
 */
void upper_rmain(int unit) {
    glPushMatrix();
    if (unit == 1) {
        glColor3f(1.0, 0.5, 0.0);
    } else {
        glColor3f(0.0, 1.0, 0.0);
    }
    glTranslatef(0.0, 0.5 * UPPER_ARM_HEIGHT, ARM_TRANSLATION);
    glScalef(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT, UPPER_ARM_WIDTH);
    glutSolidCube(1.0);
    glPopMatrix();
}

/*
 *  Dessiner Main Gauche Haut
 */
void upper_lmain(int unit) {
    glPushMatrix();
    if (unit == 1) {
        glColor3f(1.0, 0.5, 0.0);
    } else {
        glColor3f(0.0, 1.0, 0.0);
    }
    glTranslatef(0.0, 0.5 * UPPER_ARM_HEIGHT, -ARM_TRANSLATION);
    glScalef(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT, UPPER_ARM_WIDTH);
    glutSolidCube(1.0);
    glPopMatrix();
}

/*
 *  Dessiner Pied Droite Bas
 */
void lower_rpied(int unit) {
    glPushMatrix();
    if (unit == 1) {
        glColor3f(0.0, 0.0, 0.0);
    } else {
        glColor3f(0.0, 1.0, 0.0);
    }
    glTranslatef(0.0, 0.5 * LOWER_ARM_HEIGHT + 0.5, ARM_TRANSLATION - 0.1);
    glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
    glutSolidCube(1.0);
    glPopMatrix();
}

/*
 *  Dessiner Pied Gauche Bas
 */
void lower_lpied(int unit) {
    glPushMatrix();
    if (unit == 1) {
        glColor3f(0.0, 0.0, 0.0);
    } else {
        glColor3f(0.0, 1.0, 0.0);
    }
    glTranslatef(0.0, 0.5 * LOWER_ARM_HEIGHT + 0.5, -ARM_TRANSLATION + 0.1);
    glScalef(LOWER_ARM_WIDTH, LOWER_ARM_HEIGHT, LOWER_ARM_WIDTH);
    glutSolidCube(1.0);
    glPopMatrix();
}

/*
 *  Dessiner Pied Droite Haut
 */
void upper_rpied(int unit) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_list[3]);
    glPushMatrix();
    if (unit == 1) {
        glColor3f(1.0, 1.0, 1.0);
    } else {
        glColor3f(0.0, 1.0, 0.0);
    }
    gluQuadricTexture(p, 1);
    gluQuadricNormals(p, GLU_SMOOTH);
    glTranslatef(0.0, 0.5 * UPPER_ARM_HEIGHT + 0.5, ARM_TRANSLATION - 0.1);
    glScalef(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT, UPPER_ARM_WIDTH);
    glutSolidCube(1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

/*
 *  Dessiner Pied Gauche Haut
 */
void upper_lpied(int unit) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_list[3]);
    glPushMatrix();
    if (unit == 1) {
        glColor3f(1.0, 1.0, 1.0);
    } else {
        glColor3f(0.0, 1.0, 0.0);
    }
    gluQuadricTexture(p, 1);
    gluQuadricNormals(p, GLU_SMOOTH);
    glTranslatef(0.0, 0.5 * UPPER_ARM_HEIGHT + 0.5, -ARM_TRANSLATION + 0.1);
    glScalef(UPPER_ARM_WIDTH, UPPER_ARM_HEIGHT, UPPER_ARM_WIDTH);
    glutSolidCube(1.0);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void DessinerCharCoordonees(int unit, int x, int y, int z) {
    if (unit == 1) {
        //xpos=x;
        //ypos=y;
        //zpos=z;
        glTranslatef(x, 0.5, z);
    }
    if (unit == 2) {
        //xpos2=x;
        //ypos2=y;
        //zpos2=z;
        glTranslatef(x, 0.5, z);
    }
    DessinerChar(unit);
}

/*
 *  Dessiner Char Complet
 */
void DessinerChar(int unit) {
    p = gluNewQuadric();
    if (unit == 1) {
        glRotatef(theta_human[0], 0.0, 1.0, 0.0);
        corps(unit);  //body
        cou(unit);   //cou

        glPushMatrix();
        glTranslatef(0.0, BASE_HEIGHT + HEAD_HEIGHT / 2, 0.0);
        glRotatef(theta_human[2], 1.0, 0.0, 0.0);
        glRotatef(theta_human[1], 0.0, 1.0, 0.0);
        tete(unit);
        glPopMatrix();


        glPushMatrix();
        glTranslatef(BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
        glRotatef(180.0, 0.0, 0.0, 1.0);
        glRotatef(270.0, 0.0, 1.0, 0.0);
        glRotatef(theta_human[4], 0.0, 0.0, 1.0);
        lower_rmain(unit);
        glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
        glRotatef(0.0, 0.0, 0.0, 180.0);
        glRotatef(theta_human[6], 0.0, 0.0, 1.0);
        upper_rmain(unit);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
        glRotatef(180.0, 0.0, 0.0, 1.0);
        glRotatef(270.0, 0.0, 1.0, 0.0);
        glRotatef(theta_human[3], 0.0, 0.0, 1.0);
        lower_lmain(unit);
        glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
        glRotatef(0.0, 0.0, 0.0, 180.0);
        glRotatef(theta_human[5], 0.0, 0.0, 1.0);
        upper_lmain(unit);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
        glRotatef(180.0, 0.0, 0.0, 1.0);
        glRotatef(270.0, 0.0, 1.0, 0.0);
        glRotatef(theta_human[8], 0.0, 0.0, 1.0);
        lower_rpied(unit);
        glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
        glRotatef(0.0, 0.0, 0.0, 180.0);
        glRotatef(theta_human[6], 0.0, 0.0, 1.0);
        upper_rpied(unit);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
        glRotatef(180.0, 0.0, 0.0, 1.0);
        glRotatef(270.0, 0.0, 1.0, 0.0);
        glRotatef(theta_human[7], 0.0, 0.0, 1.0);
        lower_lpied(unit);
        glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
        glRotatef(0.0, 0.0, 0.0, 180.0);
        glRotatef(theta_human[5], 0.0, 0.0, 1.0);
        upper_lpied(unit);
        glPopMatrix();
    }
    if (unit == 2) {
        glRotatef(theta_alien[0], 0.0, 1.0, 0.0);
        corps(unit);  //body
        cou(unit);   //cou

        glPushMatrix();
        glTranslatef(0.0, BASE_HEIGHT + HEAD_HEIGHT / 2, 0.0);
        glRotatef(theta_alien[2], 1.0, 0.0, 0.0);
        glRotatef(theta_alien[1], 0.0, 1.0, 0.0);
        tete(unit);
        glPopMatrix();


        glPushMatrix();
        glTranslatef(BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
        glRotatef(180.0, 0.0, 0.0, 1.0);
        glRotatef(270.0, 0.0, 1.0, 0.0);
        glRotatef(theta_alien[4], 0.0, 0.0, 1.0);
        lower_rmain(unit);
        glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
        glRotatef(0.0, 0.0, 0.0, 180.0);
        glRotatef(theta_alien[6], 0.0, 0.0, 1.0);
        upper_rmain(unit);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
        glRotatef(180.0, 0.0, 0.0, 1.0);
        glRotatef(270.0, 0.0, 1.0, 0.0);
        glRotatef(theta_alien[3], 0.0, 0.0, 1.0);
        lower_lmain(unit);
        glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
        glRotatef(0.0, 0.0, 0.0, 180.0);
        glRotatef(theta_alien[5], 0.0, 0.0, 1.0);
        upper_lmain(unit);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
        glRotatef(180.0, 0.0, 0.0, 1.0);
        glRotatef(270.0, 0.0, 1.0, 0.0);
        glRotatef(theta_alien[8], 0.0, 0.0, 1.0);
        lower_rpied(unit);
        glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
        glRotatef(0.0, 0.0, 0.0, 180.0);
        glRotatef(theta_alien[6], 0.0, 0.0, 1.0);
        upper_rpied(unit);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-BASE_RADIUS, BASE_HEIGHT - BASE_RADIUS / 2, 0.0);
        glRotatef(180.0, 0.0, 0.0, 1.0);
        glRotatef(270.0, 0.0, 1.0, 0.0);
        glRotatef(theta_alien[7], 0.0, 0.0, 1.0);
        lower_lpied(unit);
        glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
        glRotatef(0.0, 0.0, 0.0, 180.0);
        glRotatef(theta_alien[5], 0.0, 0.0, 1.0);
        upper_lpied(unit);
        glPopMatrix();
    }

}

void displayProject(double fov, double asp, double dim) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, asp, dim / 75, 75 * dim);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*
 *  Random
 */
int RandomCoord(int min, int max) {
    srand(time(NULL));
    int res = rand() % max + min;
    return res;
}


/*
 *  Reaffichage
 */
void redisplayAll(void) {
    displayProject(fov, asp, dim);
    glutPostRedisplay();
}

static void reverse(void *x, const int n) {
    int k;
    char *ch = (char *) x;
    for (k = 0; k < n / 2; k++) {
        char tmp = ch[k];
        ch[k] = ch[n - 1 - k];
        ch[n - 1 - k] = tmp;
    }
}


/*
 *  Load texture from BMP file
 */
unsigned int loadTexBMP(char *file) {
    unsigned int texture;    /* Texture name */
    FILE *f;          /* File pointer */
    unsigned short magic;      /* Image magic */
    unsigned int dx, dy, size; /* Image dimensions */
    unsigned short nbp, bpp;    /* Planes and bits per pixel */
    unsigned char *image;      /* Image data */
    unsigned int k;          /* Counter */

    /*  Open file */
    f = fopen(file, "rb");
    if (!f) printf("Cannot open file %s\n", file);
    /*  Check image magic */
    if (fread(&magic, 2, 1, f) != 1) printf("Cannot read magic from %s\n", file);
    if (magic != 0x4D42 && magic != 0x424D) printf("Image magic not BMP in %s\n", file);
    /*  Seek to and read header */
    if (fseek(f, 16, SEEK_CUR) || fread(&dx, 4, 1, f) != 1 || fread(&dy, 4, 1, f) != 1 ||
        fread(&nbp, 2, 1, f) != 1 || fread(&bpp, 2, 1, f) != 1 || fread(&k, 4, 1, f) != 1)
        printf("Cannot read header from %s\n", file);
    /*  Reverse bytes on big endian hardware (detected by backwards magic) */
    if (magic == 0x424D) {
        reverse(&dx, 4);
        reverse(&dy, 4);
        reverse(&nbp, 2);
        reverse(&bpp, 2);
        reverse(&k, 4);
    }
    /*  Check image parameters */
    if (dx < 1 || dx > 65536) printf("%s image width out of range: %d\n", file, dx);
    if (dy < 1 || dy > 65536) printf("%s image height out of range: %d\n", file, dy);
    if (nbp != 1) printf("%s bit planes is not 1: %d\n", file, nbp);
    if (bpp != 24) printf("%s bits per pixel is not 24: %d\n", file, bpp);
    if (k != 0) printf("%s compressed files not supported\n", file);
#ifndef GL_VERSION_2_0
    /*  OpenGL 2.0 lifts the restriction that texture size must be a power of two */
  for (k=1;k<dx;k*=2);
  if (k!=dx) printf("%s image width not a power of two: %d\n",file,dx);
  for (k=1;k<dy;k*=2);
  if (k!=dy) printf("%s image height not a power of two: %d\n",file,dy);
#endif

    /*  Allocation de la memoire */
    size = 3 * dx * dy;
    image = (unsigned char *) malloc(size);
    if (!image)
        printf("Cannot allocate %d bytes of memory for image %s\n", size, file);
    /*  Seek to and read image */
    if (fseek(f, 20, SEEK_CUR) || fread(image, size, 1, f) != 1)
        printf("Error reading data from image %s\n", file);
    fclose(f);
    /*  Reverse colors (BGR -> RGB) */
    for (k = 0; k < size; k += 3) {
        unsigned char temp = image[k];
        image[k] = image[k + 2];
        image[k + 2] = temp;
    }

    /*  Generate 2D texture */
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    /*  Copy image */
    glTexImage2D(GL_TEXTURE_2D, 0, 3, dx, dy, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    if (glGetError()) printf("Error in glTexImage2D %s %dx%d\n", file, dx, dy);
    /*  Scale linearly when image size doesn't match */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    free(image);
    return texture;
}


void displayInit(void) {
    glClearColor(1, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();
}

void initTexture(void) {
    skybox[0] = loadTexBMP("textures/front.bmp");
    skybox[1] = loadTexBMP("textures/right.bmp");
    skybox[2] = loadTexBMP("textures/left.bmp");
    skybox[3] = loadTexBMP("textures/back.bmp");
    skybox[4] = loadTexBMP("textures/top.bmp");
    skybox[5] = loadTexBMP("textures/bottom.bmp");
    texture_list[0] = loadTexBMP("textures/grass.bmp");
    texture_list[1] = loadTexBMP("textures/legoface.bmp");
    texture_list[2] = loadTexBMP("textures/ganjubas.bmp");
    texture_list[3] = loadTexBMP("textures/jeans.bmp");
    texture_list[4] = loadTexBMP("textures/alien.bmp");
    texture_list[5] = loadTexBMP("textures/bender.bmp");
    texture_list[6] = loadTexBMP("textures/arbre.bmp");
    texture_list[7] = loadTexBMP("textures/tree.bmp");
    texture_list[8] = loadTexBMP("textures/roof.bmp");
    texture_list[9] = loadTexBMP("textures/wall.bmp");
    texture_list[10] = loadTexBMP("textures/alpha.bmp");
    texture_list[11] = loadTexBMP("textures/reflection.bmp");
    texture_list[12] = loadTexBMP("textures/pub.bmp");
}

/*
 *  Affichage principale
 */
void display(void) {
    /* position de camera */
    displayInit();
    /* position de camera */
    gluLookAt(x, y, z, x + lx, ly, z + lz, 0.0f, 1.0f, 0.0f);
    //glPushMatrix();
    //glTranslatef(100, 0, 100);
    DessinerSkybox(3.5 * dim);
    //glPopMatrix();
    DessinerScene();
    glFlush();
    glutSwapBuffers();
    redisplayAll();
}


/*
 *  Dessiner Skybox
 */
void DessinerSkybox(double D) {
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_TEXTURE_2D);

    /* Droite */
    glBindTexture(GL_TEXTURE_2D, skybox[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-D + 100, -D, -D + 100);
    glTexCoord2f(1, 0);
    glVertex3f(+D + 100, -D, -D + 100);
    glTexCoord2f(1, 1);
    glVertex3f(+D + 100, +D, -D + 100);
    glTexCoord2f(0, 1);
    glVertex3f(-D + 100, +D, -D + 100);
    glEnd();
    /* Haute */
    glBindTexture(GL_TEXTURE_2D, skybox[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(+D + 100, -D, -D + 100);
    glTexCoord2f(1, 0);
    glVertex3f(+D + 100, -D, +D + 100);
    glTexCoord2f(1, 1);
    glVertex3f(+D + 100, +D, +D + 100);
    glTexCoord2f(0, 1);
    glVertex3f(+D + 100, +D, -D + 100);
    glEnd();
    /* Gauche */
    glBindTexture(GL_TEXTURE_2D, skybox[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(+D + 100, -D, +D + 100);
    glTexCoord2f(1, 0);
    glVertex3f(-D + 100, -D, +D + 100);
    glTexCoord2f(1, 1);
    glVertex3f(-D + 100, +D, +D + 100);
    glTexCoord2f(0, 1);
    glVertex3f(+D + 100, +D, +D + 100);
    glEnd();
    /* Derriere */
    glBindTexture(GL_TEXTURE_2D, skybox[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-D + 100, -D, +D + 100);
    glTexCoord2f(1, 0);
    glVertex3f(-D + 100, -D, -D + 100);
    glTexCoord2f(1, 1);
    glVertex3f(-D + 100, +D, -D + 100);
    glTexCoord2f(0, 1);
    glVertex3f(-D + 100, +D, +D + 100);
    glEnd();

    /* Haut */
    glBindTexture(GL_TEXTURE_2D, skybox[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-D + 100, +D, -D + 100);
    glTexCoord2f(1, 0);
    glVertex3f(+D + 100, +D, -D + 100);
    glTexCoord2f(1, 1);
    glVertex3f(+D + 100, +D, +D + 100);
    glTexCoord2f(0, 1);
    glVertex3f(-D + 100, +D, +D + 100);
    glEnd();
    /* Bas */
    glBindTexture(GL_TEXTURE_2D, skybox[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(1, 1);
    glVertex3f(+D + 100, -D, -D + 100);
    glTexCoord2f(0, 1);
    glVertex3f(-D + 100, -D, -D + 100);
    glTexCoord2f(0, 0);
    glVertex3f(-D + 100, -D, +D + 100);
    glTexCoord2f(1, 0);
    glVertex3f(+D + 100, -D, +D + 100);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}

/*
 *  Dessiner Maison
 */
void DessinerMaison(void) {
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glTranslatef(0, 1, 0);
    glColor3f(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, texture_list[9]);
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(1.0, -1.0, -1.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(-1.25, 0.5, -1.25);
    glPushMatrix();
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, texture_list[8]);
    DessinerPyramide(0.5, 2.5, texture_list[8]);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glTranslatef(.75, 1.0, .55);
    glPushMatrix();
    glScalef(1, 3, 1);
    glColor3f(0.2, 0.2, 0.2);
    glutSolidCube(.25);
    glPopMatrix();
    glPopMatrix();
}

/*
 *  Dessiner Cylinder
 */
void DessinerCylinder() {
    glEnable(GL_TEXTURE_2D);
    glTranslatef(0.5f, 0.0f, 0.5f);
    glColor3f(0.647059, 0.164706, 0.164706);
    glBindTexture(GL_TEXTURE_2D, texture_list[6]);
    glPushMatrix();
    gluQuadricTexture(p, 1);
    gluQuadricNormals(p, GLU_SMOOTH);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluQuadricDrawStyle(p, GLU_FILL);
    gluCylinder(p, 0.1, 0.1, 0.5, 20, 20);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glTranslatef(-0.5f, 0.0f, -0.5f);
}

/*
 *  Dessiner Pyramide
 */
void DessinerPyramide(float yval, float scale, GLuint texture) {

    glColor3f(0.0, 1.0, 0.0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3f(0 * scale, yval, 1 * scale);
    glTexCoord2d(0, 1);
    glVertex3f(1 * scale, yval, 1 * scale);
    glTexCoord2d(1, 1);
    glVertex3f(1 * scale, yval, 0 * scale);
    glTexCoord2d(1, 0);
    glVertex3f(0 * scale, yval, 0 * scale);
    glEnd();

    glBegin(GL_TRIANGLES);
    glTexCoord3d(0, 0, 0);
    glColor3f(0.0, yval, 0.0);
    glVertex3f(0 * scale, yval, 0 * scale);
    glTexCoord3d(0.5, yval + 1.0, 0.5);
    glVertex3f(0.5 * scale, yval + 1.0, 0.5 * scale);
    glTexCoord3d(0.0, yval, 1.0);
    glVertex3f(0 * scale, yval, 1 * scale);

    glColor3f(0.0, 0.75, 0.0);
    glTexCoord3d(1, yval, 0);
    glVertex3f(1 * scale, yval, 0 * scale);
    glTexCoord3d(0.5, yval + 1.0, 0.5);
    glVertex3f(0.5 * scale, yval + 1.0, 0.5 * scale);
    glTexCoord3d(1, yval, 1);
    glVertex3f(1 * scale, yval, 1 * scale);

    glColor3f(0.0, 0.5, 0.0);
    glTexCoord3d(0, yval, 1);
    glVertex3f(0 * scale, yval, 1 * scale);
    glTexCoord3d(0.5, yval + 1.0, 0.5);
    glVertex3f(0.5 * scale, yval + 1.0, 0.5 * scale);
    glTexCoord3d(1, yval, 1);
    glVertex3f(1 * scale, yval, 1 * scale);

    glColor3f(0.0, 0.25, 0.0);
    glTexCoord3d(0, yval, 0);
    glVertex3f(0 * scale, yval, 0 * scale);
    glTexCoord3d(0.5, yval + 1.0, 0.5);
    glVertex3f(0.5 * scale, yval + 1.0, 0.5 * scale);
    glTexCoord3d(1, yval, 0);
    glVertex3f(1 * scale, yval, 0 * scale);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}


/*
 *  Dessiner Arbre
 */
void DessinerTree() {
    DessinerCylinder();
    DessinerPyramide(0.5, 1, texture_list[7]);
    glTranslatef(0.125, 0, 0.125);
    DessinerPyramide(1.0, 0.75, texture_list[7]);
    glTranslatef(0.125, 0, 0.125);
    DessinerPyramide(1.5, 0.5, texture_list[7]);
}

/*
 *  Dessiner Bilboard
 */
void DessinerBilboard(void) {
    glEnable(GL_TEXTURE_2D);
    glTranslatef(100.0f, 0.0f, 100.0f);
    glColor3f(0.5, 0.5, 0.5);
    glBindTexture(GL_TEXTURE_2D, texture_list[6]);
    glPushMatrix();
    gluQuadricTexture(p, 1);
    gluQuadricNormals(p, GLU_SMOOTH);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    gluQuadricDrawStyle(p, GLU_FILL);
    gluCylinder(p, 0.2, 0.2, 20.0, 20, 20);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_2D);
    glTranslatef(0, 20, 0);
    glColor3f(1.0, 1.0, 1.0);
    glBindTexture(GL_TEXTURE_2D, texture_list[12]);
    glBegin(GL_QUADS);
    glColor3f(1.0, 2.0, 1.0);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(-8.0, -3.0, 0.25);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(8.0, -3.0, 0.25);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(8.0, 3.0, 0.25);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(-8.0, 3.0, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0, 2.0, 1.0);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-8.0, -3.0, -0.25);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-8.0, 3.0, -0.25);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(8.0, 3.0, -0.25);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(8.0, -3.0, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(-8.0, 3.0, -0.25);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(-8.0, 3.0, 0.25);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(8.0, 3.0, 0.25);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(8.0, 3.0, -0.25);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-8.0, -3.0, -0.25);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(8.0, -3.0, -0.25);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(8.0, -3.0, 0.25);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-8.0, -3.0, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(8.0, -3.0, -0.25);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(8.0, 3.0, -0.25);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(8.0, 3.0, 0.25);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(8.0, -3.0, 0.25);
    glEnd();

    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 0.0);
    glVertex3f(-8.0, -3.0, -0.25);
    glTexCoord2d(1.0, 0.0);
    glVertex3f(-8.0, -3.0, 0.25);
    glTexCoord2d(1.0, 1.0);
    glVertex3f(-8.0, 3.0, 0.25);
    glTexCoord2d(0.0, 1.0);
    glVertex3f(-8.0, 3.0, -0.25);
    glEnd();
    glDisable(GL_TEXTURE_2D);

};


void changeSize(int w, int h) {

    /* le cas de heuteur 0 */
    if (h == 0)
        h = 1;
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);

    /* on choisit perspective correct */
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    /*on retourne au modele view */
    glMatrixMode(GL_MODELVIEW);
}

/*
 *  Dessiner Scene principale
 */
void DessinerScene(void) {

    //DessinerOcean();
    /* la terre */
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture_list[0]);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 1);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2d(100, 0);
    glVertex3f(0.0f, 0.0f, 200.0f);
    glTexCoord2d(100, 100);
    glVertex3f(200.0f, 0.0f, 200.0f);
    glTexCoord2d(0, 100);
    glVertex3f(200.0f, 0.0f, 0.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    /* l'ocean */
    /*
    glPushMatrix();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1, 0.9, 0.7);
    glBegin(GL_QUADS);
    glTexCoord2d(0, 1);
    glVertex3f(-75.0f, -1.0f, -75.0f);
    glTexCoord2d(100, 0);
    glVertex3f(-75.0f, -1.0f, 275.0f);
    glTexCoord2d(100, 100);
    glVertex3f(275.0f, -1.0f, 275.0f);
    glTexCoord2d(0, 100);
    glVertex3f(275.0f, -1.0f, -75.0f);
    glEnd();
    glPopMatrix();
    */
    glDisable(GL_TEXTURE_2D);



    //affichage de tt les persos
    //pour tout les gentils
    liste_perso good = liste_good;
    while (!est_liste_vide(good)) {
        if (good->p.id != 1 || cam!=1) {
            //fprintf(stdout,"cam %d\n",cam);
            //fprintf(stdout,"!!!!!!! %d\n",good->p.id);
            glPushMatrix();
            DessinerCharCoordonees(HUMAN, good->p.position.x, 0.5, good->p.position.z);
            glPopMatrix();
/*
            if (theta_human[7] <= 20 && param1 == 1) {
                param1 = 1;
                theta_human[7] += 1;
                theta_human[8] -= 1;
            } else {
                param1 = 2;
                theta_human[7] -= 1;
                theta_human[8] += 1;
                if (theta_human[8] >= 20) {
                    param1 = 1;
                    break;
                }
            }
*/

        }
        good = good->suivant;
    }
    //pour tt les bad
    liste_perso bad = liste_bad;
    while (!est_liste_vide(bad)) {
        glPushMatrix();
        DessinerCharCoordonees(ALIEN, bad->p.position.x, 0.5, bad->p.position.z);
        glPopMatrix();
/*
        if (theta_alien[7] <= 20 && param2 == 1) {
            param2 = 1;
            theta_alien[7] += 1;
            theta_alien[8] -= 1;
        } else {
            param2 = 2;
            theta_alien[7] -= 1;
            theta_alien[8] += 1;
            if (theta_alien[8] >= 20) {
                param2 = 1;
                break;
            }
        }
*/

        bad = bad->suivant;
    }


    point p_coords1;
    point p_coords2;
    //fprintf(stdout,"BAAAM");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {


            glPushMatrix();
            glTranslatef(i * 20.0, 0, j * 20.0);
            p_coords1.x = i * 20.0;
            p_coords1.y = 0;
            p_coords1.z = j * 20.0;
            //fprintf(stdout,"COORds1 %lf,%lf\n",p_coords1.x,p_coords1.z);
            if (is_accessible(p_coords1)) {

                add_obstacle(p_coords1, 2);
                //fprintf(stdout,"DRAW\n");

            }
            DessinerTree();
            glPopMatrix();
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            glPushMatrix();
            glTranslatef(10.0, 0, 10.0);
            glTranslatef(i * 20.0, 0, j * 20.0);
            p_coords2.x = i * 20.0 - 10.0;
            p_coords2.y = 0;
            p_coords2.z = j * 20.0 - 10.0;
            if (is_accessible(p_coords2)) {

                add_obstacle(p_coords2, 4);


            }
            DessinerMaison();

            glPopMatrix();
        }

    }


    glPushMatrix();
    DessinerBilboard();
    glPopMatrix();
    //fprintf(stdout,"BOOOM");

}

/*
 *  Camera d'utilisateur
 */
void ClavierCamera(int key, int xx, int yy) {
 ;
    float fraction = 0.5f;
    point p;
    //affiche_colision();
    liste_perso camera;
    switch (key) {
        case GLUT_KEY_LEFT :
            angle -= 0.04f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_RIGHT :
            angle += 0.04f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_UP :

            p.x = x + lx * fraction;
            p.z = z + lz * fraction;
            if (cam==1) {
                //verification de colision
                if (is_accessible(p)) {


                    x += lx * fraction;
                    z += lz * fraction;
                    camera = search_good_by_id(1);
                    camera->p.position.x = x;
                    camera->p.position.z = z;
                }
            }
            else{
                angle += 0.01f;
                ly=ly +tan(angle);
            }
            break;
        case GLUT_KEY_DOWN :

            p.x = x - lx * fraction;
            p.z = z - lz * fraction;
            if (cam==1) {
                //verification de colision
                if (is_accessible(p)) {

                    x -= lx * fraction;
                    z -= lz * fraction;

                    camera = search_good_by_id(1);
                    camera->p.position.x = x;
                    camera->p.position.z = z;
                }
            }
            else{
                angle -= 0.01f;
                ly=ly -tan(angle);
            }
            break;
        case GLUT_KEY_F2:
            cam=2;
            x=100.0f;
            y=30.0f;
            z=100.0f;
            ly=28.5f;
            //gluLookAt(0, 30.0f, 0, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
            break;
        case GLUT_KEY_F1:
            cam=1;
            liste_perso camera=liste_good;
            x = camera->p.position.x;
            z = camera->p.position.z;
            y=1.0f;
            w=0.0f;
            ly=1.0f;
            //gluLookAt(x, 30.0f, z, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
            break;
        case GLUT_KEY_F3:
            cam=2;
            x=-70.0f;
            y=40.0f;
            z=-70.0f;
            ly=38.5f;
            lx=70.f;
            lz=70.0f;
            //gluLookAt(0, 30.0f, 0, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
            break;
        case GLUT_KEY_F4:
            cam=4;
            
            liste_perso good = liste_good;
            if(!est_liste_vide(good->suivant)){
                x=good->suivant->p.position.x;
                y=2;
                z=good->suivant->p.position.z;
            }
            ly=1.0f;
            //gluLookAt(0, 30.0f, 0, x + lx, 1.0f, z + lz, 0.0f, 1.0f, 0.0f);
            break;
    }
    glLoadIdentity();
    redisplayAll();
}


/*
 *  Gerer Char - temporaire
 */
void ClavierChar(unsigned char key, int x, int y) {
    liste_perso bad;
    liste_perso camera;

    switch (key) {
        case 'x':
            camera = search_good_by_id(1);


            bad = liste_bad;

            while (!est_liste_vide(bad)) {

                if (distance(camera->p.position, bad->p.position) < 2) {
                    bad->p.vie -= 5;
                }
                if (bad->p.vie == 0) {
                    //remove from list
                    supprimer_bad(bad->p.id);

                }

                if (est_liste_vide(liste_bad)) {

                    fprintf(stdout, "Les gentils on gagner\n");
                    exit(0);
                }

                bad = bad->suivant;
            }

            break;

    }
    //redisplayAll();
}


