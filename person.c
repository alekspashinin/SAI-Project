#include"person.h"


/* VAR GLOBALES */
liste_perso liste_good=NULL;
liste_perso liste_bad=NULL;
int nb_pers=1;


int est_liste_vide(liste_perso p){
    
    //fprintf(stdout,"EST VIDE? %d\n",p==NULL);
    
    return p==NULL;
}

int distance(point p1, point p2){
    
    // fprintf(stdout,"distance called %lf, point1 %d,%d point2 %d,%d\n", sqrt(pow(p1.x-p2.x,2)+pow(p1.z-p2.z,2)),p1.x,p1.z,p2.x,p2.z);
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.z-p2.z,2));
    
}

point position_alea_perso(){

    point pnt;
    pnt.x=rand() % WIDTH+1;
    pnt.z=rand() % HEIGHT+1;

    return pnt;
}

liste_perso search_bad_by_id(int id){
    //fprintf(stdout,"Search by id bad ");
    liste_perso perso=liste_bad;
    while((!est_liste_vide(perso)) && (perso->p.id != id)){
        perso=perso->suivant;
        //fprintf(stdout,"!!!!\n");

    }
    //while(1);
    return perso;
}

liste_perso search_good_by_id(int id){
    
    
    liste_perso perso=liste_good;
    while((!est_liste_vide(perso)) && (perso->p.id != id)){
        //fprintf(stdout,"!!!!!!!!!!! %d",perso->p.id);
        
        perso=perso->suivant;

    }
    
    
    return perso;
}


liste_perso inserer_good_perso(perso p){
    liste_perso lnew=(liste_perso)malloc(1*sizeof(cellule));
    lnew->p=p;
    lnew->suivant=liste_good;
    return lnew;
}

liste_perso supprimer_good(int valeur){
    liste_perso tmp;
    liste_perso previous;
 
    if (liste_good == NULL) // si la liste est NULL on s'arrete tout de suite
        return (liste_good);
    previous = liste_good;
    if (previous->p.id == valeur) // Verifie la tete de liste, cas particulier
    {
        liste_good = previous->suivant;
        free(previous);
        return (liste_good);
    }
    tmp = previous->suivant; // le cas n est gere on se place donc sur le cas n+1
    while(tmp != NULL) // On Mouline est on supprime si on trouve l'element
    {
        if (tmp->p.id == valeur)
        {
            previous->suivant = tmp->suivant;
            free(tmp);
            return (liste_good);
        }
        previous = tmp; // pour ce souvenir dans la prochaine iteration du precedent
        tmp = tmp->suivant;
    }
    return liste_good;
}



liste_perso inserer_bad_perso(perso p){
    liste_perso lnew=(liste_perso)malloc(1*sizeof(cellule));
    lnew->p=p;
    lnew->suivant=liste_bad;
    return lnew;
}

liste_perso supprimer_bad(int valeur){
    liste_perso tmp;
    liste_perso previous;
 
    if (liste_bad == NULL) // si la liste est NULL on s'arrete tout de suite
        return (liste_bad);
    previous = liste_bad;
    if (previous->p.id == valeur) // Verifie la tete de liste, cas particulier
    {
        liste_bad = previous->suivant;
        free(previous);
        return (liste_bad);
    }
    tmp = previous->suivant; // le cas n est gere on se place donc sur le cas n+1
    while(tmp != NULL) // On Mouline est on supprime si on trouve l'element
    {
        if (tmp->p.id == valeur)
        {
            previous->suivant = tmp->suivant;
            free(tmp);
            return (liste_bad);
        }
        previous = tmp; // pour ce souvenir dans la prochaine iteration du precedent
        tmp = tmp->suivant;
    }
    return liste_bad;
}

perso creer_good(point pos){
    perso p;
    nb_pers++;
    p.id=nb_pers;
    p.position=pos;
    p.direction.x=-1;
    p.direction.z=-1;
    p.vie=500;
    p.vitesse=0.01;
    p.range=10;
    p.stamina=100;
    p.type=GOOD;
    p.mode=RANDOM;
    p.id_target=-1;

    return p;
}

perso creer_bad(point pos){
    perso p;
    nb_pers++;
    p.id=nb_pers;
    p.position=pos;
    p.direction.x=-1;
    p.direction.z=-1;
    p.vie=100;
    p.vitesse=0.01;
    p.range=10;
    p.stamina=500;
    p.type=BAD;
    p.mode=RANDOM;
    p.id_target=-1;


    return p;
}

