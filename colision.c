#include "colision.h"

void init_colision(){
    int i,j;
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            tab[i][j]=VIDE;
        }
    }

}


void affiche_colision(){
    int i,j;
    for(i=0;i<HEIGHT;i++){
        for(j=0;j<WIDTH;j++){
            fprintf(stdout,"%d ",tab[i][j]);
        }
        fprintf(stdout,"\n");
    }
}

    
void add_obstacle(point p1,int taille){
    //fprintf(stdout,"Ajout d'obstacle en %lf,%lf",p1.x,p1.z);
    int i,j;
    point temp;
    temp.x=p1.x+(taille/2);
    temp.z=p1.z+(taille/2);
    
    if(is_accessible(p1) && is_accessible(temp)){
       
        for(i=p1.x-(taille/2);i<temp.x;i++){
            for(j=p1.z-(taille/2);j<temp.z;j++){
                //fprintf(stdout,"YO %d,%d\n",i,j);
                if(i<HEIGHT && j<WIDTH){
                    //fprintf(stdout,"YO %d,%d\n",i,j);
                    tab[i][j]=PLEIN;
                }
            }
        } 
        //fprintf(stdout,"Ajout d'obstacle en %lf,%lf\n",p1.x,p1.z);
        //return;
    }
    //fprintf(stdout,"END\n");
           
}

int is_accessible(point p1){
    // fprintf(stdout,"IS ACCESSIBLE %d,%d\n",p1.x,p1.z);
    //affiche_colision();

    if((p1.x < HEIGHT) && (p1.z < WIDTH)
       && (p1.x > 0) && (p1.z > 0)){

        
        //fprintf(stdout,"IF %d\n",(tab[(int)p1.x][(int)p1.z]==VIDE));

        
        return (tab[(int)p1.x][(int)p1.z]==VIDE);
    }
    //fprintf(stdout,"ELSE\n");

    return 0;
}

