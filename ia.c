#include"ia.h"



void kill_the_bastard(liste_perso perso){

    //liste_perso bad=search_bad_by_id(id_bad);
    liste_perso good=search_good_by_id(perso->p.id_target);
    
    if(good->p.id !=1){
  
        if(good->p.vie > 0){
            good->p.vie--;

        }

        //case of death
        if(good->p.vie == 0){
            //remove from list
            supprimer_good(good->p.id);

            perso->p.mode=RANDOM;
            perso->p.direction=random_pos(perso);
        
        }

        if(est_liste_vide(liste_good)){

            fprintf(stdout,"Mechants on gagner\n");
            exit(0);
        }
    }
    

}

void deplacement(liste_perso perso, point target){


  
    point point;
    
   
   
    
    if(perso->p.id != 1){

         
        if(!is_accessible(perso->p.position)){
            perso->p.position=position_alea_perso();
            //fprintf(stdout,"WTF\n");
         
        }
        
        if(perso->p.type == BAD){
            point.x = perso->p.position.x + (target.x- perso->p.position.x)*perso->p.vitesse;
            point.z = perso->p.position.z + (target.z- perso->p.position.z)*perso->p.vitesse;

        //fprintf(stdout,"la position de deplacement %d : %lf,%lf pos act : %lf,%lf ,vitesse %lf, target %lf,%lf, destination %lf,%lf, en mode %d\n",perso->p.id, point.x, point.z,perso->p.position.x,perso->p.position.z,perso->p.vitesse,target.x,target.z,perso->p.direction.x,perso->p.direction.z,perso->p.mode);


        if(is_accessible(point) && is_accessible(target)){
            //fprintf(stdout,"bad %lf,%lf\n",point.x,point.z);
            perso->p.position=point;
            //xpos1=perso->p.position.x;
            //zpos1=perso->p.position.z;
            //cas ou target-pos==1 || pos-target==-1
            if(abs(target.x-perso->p.position.x) < 0.5){
                perso->p.position.x=target.x;
            }
            if(abs(target.z-perso->p.position.z) < 0.5){
                perso->p.position.z=target.z;
            }
        
      
             
            
        }else{
            //fprintf(stdout,"NOT ACCC id=%d pos=%lf,%lf target=%lf,%lf\n",perso->p.id,perso->p.position.x,perso->p.position.z,target.x,target.z,perso->p.direction.x,perso->p.direction.z );
            perso->p.direction=random_pos(perso);
            perso->p.mode=RANDOM;
          
        }

        if(perso->p.mode==CHASE){
            if(distance(perso->p.position, search_good_by_id(perso->p.id_target)->p.position) <= 3){

                
                fprintf(stdout,"KILL THE BASTARD\n");

                kill_the_bastard(perso);
                
            }
        }
    }else{

//if chased ou pas

        if(perso->p.mode==CHASE){
            
            point.x = perso->p.position.x - (target.x- perso->p.position.x)*perso->p.vitesse;
            point.z = perso->p.position.z - (target.z- perso->p.position.z)*perso->p.vitesse;

            if(is_accessible(point)){
                //fprintf(stdout,"IS ACCESSIBLE %d,%d\n",point.x,point.z);
                //fprintf(stdout,"ddeplaaaace %lf,%lf point %lf,%lf\n",perso->p.position.x,perso->p.position.z,point.x,point.z);
                perso->p.position=point;
                //xpos2=perso->p.position.x;
                //zpos2=perso->p.position.z;
                
            }else{
                //fprintf(stdout,"NOT ACCC id=%d pos=%lf,%lf target=%lf,%lf\n",perso->p.id,perso->p.position.x,perso->p.position.z,target.x,target.z);
                perso->p.direction=random_pos(perso);
                perso->p.mode=RANDOM;
          
            }

            
            
            ///ERROROROROROORORORO
        }else{

            point.x = perso->p.position.x + (target.x- perso->p.position.x)*perso->p.vitesse;
            point.z = perso->p.position.z + (target.z- perso->p.position.z)*perso->p.vitesse;

            if(is_accessible(point) && is_accessible(target)){
                //fprintf(stdout,"IS ACCESSIBLE %d,%d\n",point.x,point.z);

                perso->p.position=point;
                //xpos2=perso->p.position.x;
                //zpos2=perso->p.position.z;
                
                if(abs(target.x-perso->p.position.x) < 0.5){
                    perso->p.position.x=target.x;
                }
                if(abs(target.z-perso->p.position.z) < 0.5){
                    perso->p.position.z=target.z;
                }
            }else{
                //fprintf(stdout,"NOT ACCC id=%d pos=%lf,%lf target=%lf,%lf\n",perso->p.id,perso->p.position.x,perso->p.position.z,target.x,target.z);
                perso->p.direction=random_pos(perso);
                perso->p.mode=RANDOM;
          
            }
        }
        //fprintf(stdout,"la position de deplacement %d : %lf,%lf pos act : %lf,%lf ,vitesse %lf, target %lf,%lf, destination %lf,%lf, en mode %d\n",perso->p.id, point.x, point.z,perso->p.position.x,perso->p.position.z,perso->p.vitesse,target.x,target.z,perso->p.direction.x,perso->p.direction.z,perso->p.mode);

        //fprintf(stdout,"la position de deplacement goood: %d,%d ,vitesse %lf, target %d\n", point.x, point.z,perso->p.vitesse,target.x);
 
    }
    }
        
        
}

void chase_move(liste_perso perso){
    //fprintf(stdout,"CHASE!\n");
    liste_perso p;
    point point;
    if(perso->p.stamina > 0){
        //while(1);
        if(perso->p.type == GOOD){
            p=search_bad_by_id(perso->p.id_target);
           
            //while(1);
        }else{
            
            p=search_good_by_id(perso->p.id_target);
            
        }
        if(p != NULL){
            
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            point=p->p.position;
            perso->p.direction=point;
            //fprintf(stdout,"la pos du chase move %d,%d la pose act %d,%d\n",point.x,point.z,perso->p.position.x,perso->p.position.z);
            //verification dans deplacement s'il s agit d'un good || bad
            deplacement(perso,point);
        }
    }else{
        perso->p.mode=RANDOM;
        perso->p.direction=random_pos(perso);
        //fprintf(stdout,"I M TIRED\n");
    }
}



point random_pos(liste_perso perso){
    point nv;
   
    nv.x = (rand() % ((((int)perso->p.position.x) + 20) - (((int)perso->p.position.x)-20)+1))+(((int)perso->p.position.x) -20);
    
    nv.z = (rand() % ((((int)perso->p.position.z) + 20) - (((int)perso->p.position.z)-20)+1))+(((int)perso->p.position.z) - 20);

    // fprintf(stdout,"//////////Nouveau point pour %d, %d,%d\n",perso->p.id,nv.x,nv.z);
     
    if(nv.x < perso->p.position.x)
        nv.x = nv.x - 4;
    if(nv.x > perso->p.position.x)
        nv.x = nv.x + 4;
    
    if(nv.z < perso->p.position.z)
        nv.z = nv.z - 4;
    if(nv.z > perso->p.position.z)
        nv.z = nv.z + 4;
   
    
    //fprintf(stdout,"Nouveau point pour %d %lf,%lf, %lf,%lf\n",perso->p.id,perso->p.position.x,perso->p.position.z,nv.x,nv.z);

    return nv;

}



int scan_target_bis(liste_perso bad){

    liste_perso good=liste_good;

    //fprintf(stdout,"!!!!!!!! %d x %d\n",liste_good->p.id,liste_good->p.position.x);

        
    while(!est_liste_vide(good)){
        //fprintf(stdout,"LE AVANT IF");
        if(distance(good->p.position,bad->p.position) <= bad->p.range){
            //fprintf(stdout,"Le %d chase le %d\n",bad->p.id,good->p.id);
            /*pour les bad*/
            bad->p.id_target=good->p.id;
            bad->p.mode=CHASE;

            bad->p.vitesse=0.03;

            /*pour les good */
            good->p.id_target=bad->p.id;
            good->p.mode=CHASE;

            good->p.vitesse=0.03;
            

            return 1;
        }
        good=good->suivant;     
    }
    return 0;
    
}

void random_move(liste_perso perso){
    //fprintf(stdout,"RANDOM!!\n");
    //fprintf(stdout,"RANDOM_MOVE\n");
    if((perso->p.direction.x == -1) &&
       (perso->p.direction.z == -1) ){
        
        perso->p.direction = random_pos(perso);
        deplacement(perso, perso->p.direction);
        // fprintf(stdout,"INIT\n");
        
    }
    //incrementation du stamina
    if(perso->p.stamina < 500){
        //fprintf(stdout,"I AM %d and RESTING\n",perso->p.id);
        perso->p.stamina += 1;
  
            
    }
    if(perso->p.vie < 100){
        //fprintf(stdout,"I AM %d and HEALING\n",perso->p.id);
        perso->p.vie += 1;
        
    }
    // verification si on a atteint la posision voulu
    int x1,y1,x2,y2;
    x1=(int)perso->p.direction.x;
    x2=(int)perso->p.position.x;
    y1=(int)perso->p.direction.z;
    y2=(int)perso->p.position.z;
    //fprintf(stdout,"!!!!!!!!!!!!!!!!!! %d %d==%d %d==%d \n",(x1 == x2) && (y1==y2),x1,x2,y1,y2);
    if((x1 == x2) && (y1 == y2) && (perso->p.stamina >= 500)){
        //fprintf(stdout,"ATTEINT, id=%d, mode=%d, stamina=%d, \n",perso->p.id,perso->p.mode,perso->p.stamina);
              

        
        //si le stamina est em max
        if(perso->p.stamina >= 500){
            //if bad alors on cherche une cible
            if(perso->p.type==BAD){
                //fprintf(stdout,"BAD\n");
                
                if(scan_target_bis(perso)){
                    fprintf(stdout,"target found \n");
                    //while(1);
                    chase_move(perso);
                }else{
                    fprintf(stdout,"target not found \n");
                    perso->p.direction = random_pos(perso);
                    deplacement(perso, perso->p.direction);
                    // random
                }
            }else{
                
                perso->p.direction = random_pos(perso);
                deplacement(perso, perso->p.direction);
                //fprintf(stdout,"I AM MOVING RANDOMLY %d to %d,%d\n",perso->p.id,perso->p.direction.x,perso->p.direction.z);

                //random
            }
            
        }  
    }else{
        
        //////////////PROBL
        //fprintf(stdout,"delpaceee je suis %d en %lf,%lf je vais vers %lf,%lf\n",perso->p.id,perso->p.position.x,perso->p.position.z,perso->p.direction.x,perso->p.direction.z);
        if((x1 == x2) && (y1 == y2)){
            perso->p.direction = random_pos(perso);
            fprintf(stdout,"WTF\n");
        }
        deplacement(perso, perso->p.direction);
        //fprintf(stdout,"MOOOVE\n");
    }
}


void move_persos(){
    //fprintf(stdout,"MAIN\n");

    liste_perso bad=liste_bad;
    liste_perso good=liste_good;

    // pour tout les bad perso
    while(!est_liste_vide(bad)){
        
        //si ils sont en mode chase
        if(bad->p.stamina == 0){
            bad->p.mode=RANDOM;
            bad->p.vitesse=0.01;
    
        }
        
        if(bad->p.mode == CHASE){
            fprintf(stdout,"I AM BAD AND CHASING %lf,%lf my stamina is %d\n",bad->p.position.x,bad->p.position.z,bad->p.stamina);

            switch(bad->p.stamina){
            case 400:
                bad->p.vitesse=0.02;
                break;
            case 200:
                bad->p.vitesse=0.01;
                break;
            default:
                break;
            }
            bad->p.stamina-=1;
            chase_move(bad);

            //si ils sont en mode random
        }else if(bad->p.mode == RANDOM){
            random_move(bad);
        }

        bad=bad->suivant;
        
    }

    // pour tout les goo persos
    while(!est_liste_vide(good)){
        //si ils sont en mode chase
        if(good->p.id!=1){
        if(good->p.stamina == 0){
            // fprintf(stdout,"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            good->p.mode=RANDOM;
            good->p.vitesse=0.01;
    
        }
        if(good->p.mode == CHASE){
            fprintf(stdout,"I AM GOOD AND BEING CHASED %lf,%lf my stamina is %d my speed is %lf my life is %d\n",good->p.position.x,good->p.position.z,good->p.stamina,good->p.vitesse, good->p.vie);
            switch(good->p.stamina){
            case 400:
                good->p.vitesse=0.02;
                break;
            case 200:
                good->p.vitesse=0.01;
                break;
            default:
                break;
            }
            good->p.stamina-=1;
            chase_move(good);

            //si ils sont en mode random
        }else if(good->p.mode == RANDOM){
            random_move(good);
        }
        }
        good=good->suivant;
    }
   
}



    

