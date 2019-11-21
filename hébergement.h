#ifndef HERBERGEMENT_H_INCLUDED
#define HERBERGEMENT_H_INCLUDED

#include<stdio.h>

struct Hebergement
{
    int referencee;
    int periode;
    int nbr_Etoile_Hotel;
    float prix_nuitee;
    int chambre;
    char  nom_hotel[20];
    char type_pension[20];
};
typedef struct Hebergement heberge;



void ajouter(heberge h, char nomf[]);
void afficher(char nomf[]);
void recherche(char nomf[], int refer);
void modifier(char nomf[]);
void supprimer(char nomf[],char nomf1[]);



#endif // HERBERGEMENT_H_INCLUDED
