#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <math.h>
#include "initialiser_objets.h"
#include "fonctions.h"
#include "map.h"
void initialiser_item(item i[],int nbre_blocs_actuel)
{
    int j;
    int n=1;
    for(j=1;j<=nbre_blocs_actuel;j++)
    {
        i[j].id=j;
        i[j].nbre_blocs_actuel=nbre_blocs_actuel;
        i[j].enleve_tempo=0;
        if(j==1 || j==5 || (j>=6 && j<=8) || j==10)
            i[j].soumis_a_la_gravite=1;
        else
            i[j].soumis_a_la_gravite=0;
        if(j==4 || j==9)
        {
            i[j].soumis_a_la_gravite=3;
        }
        if(j==1 || j==4 || j==5 || j==5 || j==6 || (j>=7 && j<=10 && j!=9))
        {
            i[j].placable=1;
            i[j].n_placable=n;
            n+=1;
        }
        else
        {
            i[j].placable=0;
        }
        if(j==1)
        {
            i[j].pv=200;
            i[j].prix=20;
        }
        if(j==2)
        {
            i[j].pv=300;
        }
        if(j==3)
        {
            i[j].pv=350;
        }
        if(j==4)
        {
            i[j].pv=300;
            i[j].prix=30;
        }
        if(j==5)
        {
            i[j].pv=PV_CANON;
            i[j].prix=0;
        }
        if(j==6)
        {
            i[j].pv=1500;
            i[j].prix=0;
        }
        if(j==7)
        {
            i[j].pv=200;
            i[j].prix=40;
        }
        if(j==8)
        {
            i[j].pv=1500;
            i[j].prix=150;
        }
        if(j==9)
        {
            i[j].pv=500;
        }
        if(j==10)
        {
            i[j].pv=15;
            i[j].prix=10;
        }
    }
    i[1].nbre_item_placable=n-1;
}
void initialiser_blocs(fenetre f,carre c[NBRE_CASES_Y][NBRE_CASES_X],item it[])
{
    int i=0;
    int j=0;
    int k=0;
    for(i=0;i<f.cases_x;i++)
    {
        for(j=0;j<f.cases_y;j++)
        {
            c[j][i].xi=i;
            c[j][i].yi=j;
            c[j][i].x=i*(f.Xfenetre/f.cases_x);
            c[j][i].y=j*(f.Yfenetre/f.cases_y);
            c[j][i].id=MAP_ID[0][j][i];
            c[j][i].pv=1;
            c[j][i].compteur_gravite=1;
            c[j][i].au_joueur=-1;
            c[j][i].pv=it[c[j][i].id].pv;
            c[j][i].pv_initiaux=it[c[j][i].id].pv;
            c[j][i].enleve_tempo=0;
        }
    }
}
void initialiser_map(fenetre f[],double Xfen,double Yfen,int cases_max_x,int cases_map_y)
{
    f[0].cases_x=cases_max_x;
    f[0].cases_y=cases_map_y;
    f[0].Xfenetre=Xfen;
    f[0].Yfenetre=Yfen;
}
void initialiser_joueur(joueur j[],int jmax,canon canon_j[],double taille_explosion_init,fusee_missile* missile_initiaux,objet_fixe* avion)
{
    int i;
    int k;
    for(i=0;i<=jmax;i++)
    {
        j[i].missile_selectione=missile_initiaux;
        j[i].id_selectionee=1;
        j[i].n_item_placable_sel=1;
        j[i].n_joueur=i;
        j[i].bombardier=canon_j[i];
        j[i].bombardier.pv=PV_CANON;
        j[i].canon_place=0;
        j[i].taille_explosion=taille_explosion_init;
        j[i].portee_tir=1;
        j[i].puissance_tir=1;
        j[i].puissance_tir_cannon=PUISSANCE_CANON_INITIALE;
        j[i].vx_fusee=0;
        j[i].vy_fusee=0;
        j[i].points_destruction=0+MOD_CHEAT()*500;
        j[i].xp=0;
        j[i].coef_xp=1;
        j[i].coef_points=1;
        j[i].tune=3200+MOD_CHEAT()*100000;
        j[i].points_destruction_debut_tour=0+MOD_CHEAT()*500;
        j[i].id_missile_selectione=0;
        j[i].nbre_tirs=0;
        j[i].nbre_tirs_max=1;
        j[i].coef_gain_tune=1;
        j[i].xp_pour_lvlup=1800;
        j[i].pts_competences=1+MOD_CHEAT()*100 + MOD_CHEAT_JUSTE_POUR_COMPETENCE*100;
        j[i].niveau=1;
        j[i].coef_xp_lvl_sup=1.6;
        j[i].coeur_xi=0;
        j[i].coeur_yi=0;
        j[i].coeur_pose=0;
        j[i].avion=avion;
        j[i].avion->flag=1-i;
        j[i].largueur_lance=0;
        for(k=1;k<=NBRE_CASES_INVENTAIRE*2;k++)
        {
            j[i].inventaire[k]=0;
        }
        j[i].inventaire[1]=1;
        j[i].n_competence_ocupee=1;
        for(k=1;k<=NBRE_COMPETENCES_EXPLO;k++)
        {
            j[i].explosion_debloques[k]=0;
        }
        for(k=1;k<=NBRE_COMPETENCES_SCIENCE;k++)
        {
            j[i].science_debloques[k]=0;
        }
        for(k=1;k<=NBRE_COMPETENCES_PRECISION;k++)
        {
            j[i].precision_debloques[k]=0;
        }
        j[i].explosion_debloques[1]=1;
        j[i].science_debloques[1]=1;
        j[i].precision_debloques[1]=1;
    }
    j[0].angle_tir=-PI/4;
    j[1].angle_tir=-3*PI/4;
    j[0].fini_de_jouer=0;
    j[1].fini_de_jouer=1;
}

void initialiser_objet_anime(objet_anime* o,int images_max,ALLEGRO_BITMAP* images_animees[],double vitesse_animation,double taille,double x,double y,int taille_x,int taille_y,int existence)
{
    o->taille_x=taille_x;
    o->taille_y=taille_y;
    o->etat_animation=1;
    o->taille=taille;
    o->vitesse_animation=vitesse_animation;
    o->x=x;
    o->y=y;
    o->nbre_images_max=images_max;
    o->compteur_animation=1;
    o->angle=0;
    o->existence=existence;
    int i;
    for(i=0;i<=3;i++)
    {
        o->animation[i]=0;
    }
    for(i=1;i<=images_max;i++)
    {
        o->bitmap[i]=images_animees[i];
    }
}
void initialiser_objet_fixe(objet_fixe* o,ALLEGRO_BITMAP* image,double tailleX,double tailleY,double x,double y,int taille_x,int taille_y,int existence)
{
    o->taille_x=taille_x;
    o->taille_y=taille_y;
    o->tailleX=tailleX;
    o->tailleY=tailleY;
    o->x=x;
    o->y=y;
    o->bitmap=image;
    o->angle=0;
    o->existence=existence;
    o->flag=0;
}
void initialiser_objet_fixe_en_masse(objet_fixe o[],ALLEGRO_BITMAP* image,double tailleX,double tailleY,double x,double y,int taille_x,int taille_y,int nbre_objets)
{
    int i;
    for(i=0;i<=nbre_objets;i++)
    {
        o[i].taille_x=taille_x;
        o[i].taille_y=taille_y;
        o[i].tailleX=tailleX;
        o[i].tailleY=tailleY;
        o[i].x=x;
        o[i].y=y;
        o[i].bitmap=image;
        o[i].angle=0;
        o[i].existence=0;
        o[i].vitesse_x=0;
        o[i].vitesse_y=0;
        o[i].flag=0;
    }
}
void mettre_id(objet_fixe o[],int id)
{
    int k;
    for(k=0;k<=NBRE_COMPETENCES_EXPLO;k++)
    {
        o[k].id=id;
    }
}
void initialiser_objet_fixe_c(objet_fixe o[],ALLEGRO_BITMAP* image[],double taille,int taille_xy,double x,int id)
{
    int k;
    int i;
    int n;
    for(k=1;k<=NBRE_COMPETENCES_EXPLO;k++)
        {
        mettre_id(o,id);
        o[k].taille_x=taille_xy;
        o[k].taille_y=taille_xy;
        o[k].tailleX=taille;
        o[k].tailleY=taille;
        o[k].angle=0;
        o[k].existence=1;
        for(i=1;i<=4;i++){o[k].utile2[i]=0;}
        if(k==1)
        {
            o[k].y=YFENETRE/(NBRE_COLONE_COMPETENCE+1);
            o[k].x=x;
            o[k].utile2[1]=2;
            o[k].utile2[2]=3;
        }
        if(k>=2 && k<=3)
        {
            o[k].y=(YFENETRE/(NBRE_COLONE_COMPETENCE+1))*2;
            n=k-2;
            o[k].utile2[1]=6-2*n;
            o[k].utile2[2]=7-2*n;
            o[k].x=x+(2*(k-2)-1)*(taille_xy*o[k].tailleX);
        }
        if(k>=4 && k<=7)
        {
            if(k>=5 && k<=6)
            {
                o[k].utile2[1]=8;
            }
            o[k].y=(YFENETRE/(NBRE_COLONE_COMPETENCE+1))*3;
            n=k-5;
            if(n<=0){n-=1;}
            o[k].x=x+(n/(abs(n)))*(taille_xy*o[k].tailleX/2)-(n)*(taille_xy*o[k].tailleX*1.2);
        }
        if(k==8)
        {
            o[k].y=(YFENETRE/(NBRE_COLONE_COMPETENCE+1))*4;
            o[k].x=x;
        }
        o[k].bitmap=image[k];
    }
}
void initialiser_fusees(fusee_missile f[],int nbre_fusees,ALLEGRO_BITMAP* image_fusee,double taille_fusees,int nbre_explosion,ALLEGRO_BITMAP* explosions[],double vitesse_anim_explosion,double taille_explosion,double puissance,double portee,item_missile it[],double coef_xp,double taille_x_y_explosion)
{
    int i;
    static int id=1;
    for(i=0;i<=nbre_fusees;i++)
    {
        f[i].fusee.existence=0;
        f[i].inclinaison=0;
        initialiser_objet_fixe(&f[i].fusee,image_fusee,taille_fusees,taille_fusees,0,0,TAILLE_FUSEE_X_Y,TAILLE_FUSEE_X_Y,0);
        initialiser_objet_anime(&f[i].explosion,nbre_explosion,explosions,vitesse_anim_explosion,taille_explosion,0,0,taille_x_y_explosion,taille_x_y_explosion,1);
        f[i].vx=0;
        f[i].vy=0;
        f[i].explosion_en_cours=0;
        f[i].compteur_fumee=0;
        f[i].portee_explosion=portee;
        f[i].puissance_explosion=puissance;
        f[i].puissance_explosion_initiale=puissance;
        f[i].portee_explosion_initiale=portee;
        f[i].chrono=0;
        f[i].taille_initiale=taille_explosion;
        f[i].id=id;
        f[i].utile1=0;
        f[i].utile2=0;
        f[i].coef_xp=coef_xp;
        f[i].compteur_depuis_tir=0;
    }
    int* p_fusee=&f;
    it[id].missile=*p_fusee;
    id+=1;
}
void initialiser_fumee(objet_anime o[],int nbre_fumee,ALLEGRO_BITMAP* fumees[],double vitesse_anim,double taille)
{
    int i;
    for(i=0;i<=NBRE_FUMEE;i++)
    {
        initialiser_objet_anime(&o[i],nbre_fumee,fumees,vitesse_anim,taille,0,0,TAILLE_FUMEE_XY,TAILLE_FUMEE_XY,0);
    }
}
void initialiser_items_missiles(item_missile it[])
{
    int i;
    for(i=1;i<=NBRE_TYPES_MISSILES;i++)
    {
        it[i].id=i;
    }
    it[1].prix=0;
    it[2].prix=4;
    it[3].prix=100;
    it[4].prix=20;
    it[5].prix=10;
    it[6].prix=30;
    it[7].prix=5;
    it[8].prix=15;
    it[9].prix=PRIX_MISSILES_CIBLE;
    it[10].prix=18;
    it[11].prix=PRIX_CONTOURNEUR;
}
void base_auto_j1(CLAVIER,joueur* j,carre blocs[NBRE_CASES_Y][NBRE_CASES_X],item it[],int n_tour,int joueur_qui_joue)
{
    int x;
    int y;
    static int c=0;
    if(al_key_down(ALLEGRO_KEYBOARD_STATE,ALLEGRO_KEY_T) && c==0 && n_tour==0 && joueur_qui_joue==0)
    {
        c=1;
        for(x=1;x<=NBRE_CASES_X-1;x++)
        {
            for(y=1;y<=NBRE_CASES_Y-1;y++)
            {
                placer_bloc_sel(BASE_RAPIDE_J1[y][x],j,blocs,x,y,it);
            }
        }
    }
}

void base_auto_j2(CLAVIER,joueur* j,carre blocs[NBRE_CASES_Y][NBRE_CASES_X],item it[],int n_tour,int joueur_qui_joue)
{
    int x;
    int y;
    static int ca=0;
    if(al_key_down(ALLEGRO_KEYBOARD_STATE,ALLEGRO_KEY_T) && ca==0 && n_tour==0 && joueur_qui_joue==1)
    {
        ca=1;
        for(x=1;x<=NBRE_CASES_X-1;x++)
        {
            for(y=1;y<=NBRE_CASES_Y-1;y++)
            {
                placer_bloc_sel(BASE_RAPIDE_J2[y][x],j,blocs,x,y,it);
            }
        }
    }
}
