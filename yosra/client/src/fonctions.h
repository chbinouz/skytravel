#include<gtk/gtk.h>
#include<string.h>
typedef struct
{
int jour;
int mois;
int annee;
}date;

typedef struct
{
char nom[100];
char prenom[100];
date d;
char adresse[100];
char cin[100];
char pays[100];
char sexe[100];
char motdepasse[100];
}client;
void modifier_clients(char nom1[],char prenom1[], char pays1[],int jour,int mois,int annee,char sexe1[],char adresse1[],char cin1[], char motdepasse1[]);
void modifier_users(char cin[], char motdepasse[]);
void creation_compte(client c);
void supprimer_fuser(char cin1[]);
void supprimer_fclient(char cin1[30]);
void afficher_client(GtkWidget *liste);
int verifier (char login[], char password[]);

