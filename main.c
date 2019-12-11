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

#include <GL/glut.h>
#include <stdlib.h>
#include "main.h"


/*
* lancement de de la programme
*/

void usage(){

    fprintf(stderr,"ERREUR DE LANCEMENT !\n Usage: sai <int: 1 < nombre de gentils < 5>  <int: 1 < nombre de mechants < 5>\n");
    exit(-1);

}


int main(int argc, char **argv) {

    int gentils,mechants,i;
    point pos;
    perso camera;
    //init colision
    init_colision();
    srand(time(0));

    

    if(argc != 3){
        usage();
    }

    gentils=atoi(argv[1]);
    mechants=atoi(argv[2]);

    if((gentils <= 0) || (gentils > 51) || (mechants <= 0) || (mechants > 51)){
        usage();
    }

    
    //ajout des gentils
    for(i=0;i<gentils;i++){
        
        pos.x=5;//random!!
        pos.z=20;

        liste_good=inserer_good_perso(creer_good(position_alea_perso()));
     
    }
    
    //ajout du gentil camera
    camera=creer_good(pos);
    camera.id=1;
    liste_good=inserer_good_perso(camera);
    

    //ajout des mechants

    for(i=0;i<mechants;i++){
        
        pos.x=5;//random
        pos.z=20;

        liste_bad=inserer_bad_perso(creer_bad(position_alea_perso()));
    }

    


    
    // initialisation des bases 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    // taille et position 
    glutInitWindowPosition(150, 150);
    glutInitWindowSize(800, 800);
    glutCreateWindow("SAI Projet");
    // affichage 
    glutDisplayFunc(display);
    glutReshapeFunc(changeSize);
    glutKeyboardFunc(ClavierChar);
    glutIdleFunc(move_persos); 
    glutSpecialFunc(ClavierCamera);
    // initialisation des textures 
    initTexture();
    // redessinage 
    redisplayAll();
    glutMainLoop();
    return 0;
}



