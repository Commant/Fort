#ifndef DIMENSIONS_H_INCLUDED
#define DIMENSIONS_H_INCLUDED
//POUR PC LYCEE: 1200*800
#define XFENETRE 1662.5
#define YFENETRE 950

#define COEF_PIXEL_X XFENETRE/1662.5
#define COEF_PIXEL_Y YFENETRE/950
#define NBRE_BLOCS_ACTUEL 10

#define NBRE_CASES_X 70
#define NBRE_CASES_Y 40

#define NBRE_ANIM_MAXIMAL 60

#define NBRE_COLONE_COMPETENCE 4

#define NBRE_LIAISONS_COMPTENCES_MAX 4

#define NBRE_COMPETENCES_EXPLO 8
#define NBRE_COMPETENCES_SCIENCE 8
#define NBRE_COMPETENCES_PRECISION 8
#define TAILLE_COMPETENCE 100

#define TAILLE_EXPLOSION_X_Y 1000

#define TAILLE_FUSEE_X_Y 200
#define TAILLE_FUMEE_XY 50
#define FREQUENCE_APPARITION_FUMEE 0.7
#define COEF_FUSEE_FUMEE_TAILLE 2;

#define NBRE_FUSEES 20
#define NBRE_MISSILE_NUCLAIRES 10;
#define NBRE_FUMEE 500

#define COEF_REDUC_DEGAT_EXPLOSION 0.3

#define PUISSANCE_TIR_INITIALE 6000
#define PUISSANCE_CANON_INITIALE 900
#define TAILLE_EXPLOSION_INIT 0.12
#define COEF_TAILLE_EXPLO_DEGATS 90
#define PORTEE_INITIALE 4*XFENETRE/NBRE_CASES_X

#define NBRE_PARTICULES_EXPLOSION_MAX 200
#define NBRE_PARTICULE_POP 30
#define VITESSE_PARTICULE 30
#define NBRE_FUMEE_EXPLOSION 10

#define PRECISION_EXPLOSION_PARTICULE 200

#define LONGEUR_LIGNE_TIR 100
#define LARGEUR_LIGNE_TIR 5


//PALIER_COMPETENCE EXPLO
#define PUISSANCE_TIR_n1 14000
#define PUISSANCE_TIR_n2 18000
#define PUISSANCE_TIR_n3 30000
#define PUISSANCE_TIR_NUCLEAIRE 8000000
#define PORTEE_TIR_n1 6*XFENETRE/NBRE_CASES_X
#define PORTEE_TIR_n2 8*XFENETRE/NBRE_CASES_X
#define PORTEE_TIR_n3 10*XFENETRE/NBRE_CASES_X

#define PORTEE_TIR_NSUP 40*XFENETRE/NBRE_CASES_X



#define PI 3.14159265358979323846264338327950288419716939937510
#endif // DIMENSIONS_H_INCLUDED
