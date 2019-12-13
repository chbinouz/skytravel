#include <stdio.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>

void modifier_clients(char nom[],char prenom[], char pays[],int jour,int mois,int annee,char sexe[],char adresse[],char cin[], char motdepasse[]) 

{
client c;
FILE*f;
FILE*tmp; 
 
f=fopen("client.txt","r");
tmp=fopen("tmp.txt","w");
 if(f!=NULL) 
{ 
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s \n",c.nom,c.prenom,c.pays,&c.d.jour,&c.d.mois,&c.d.annee,c.sexe,c.adresse,c.cin,c.motdepasse)!=EOF)	
{ 
if(strcmp(cin,c.cin)==0)
{fprintf(tmp,"%s %s %s %d %d %d %s %s %s %s \n",nom,prenom,pays,jour,mois,annee,sexe,adresse,cin,motdepasse);}
else
fprintf(tmp,"%s %s %s %d %d %d %s %s %s %s \n",c.nom,c.prenom,c.pays,c.d.jour,c.d.mois,c.d.annee,c.sexe,c.adresse,c.cin,c.motdepasse);
} 
}
fclose(f) ; 
fclose(tmp);
remove("client.txt");
rename("tmp.txt","client.txt");
}





enum
{
	 CIN,
	 NOM,
	 PRENOM,
	 JOUR,
         MOIS,
         ANNEE,
         SEXE,
	 ADRESSE,
         MOTDEPASSE,
         PAYS,
	 COLUMNS
};







void afficher_client(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


char cin[30];
char nom [30];
char prenom [30];
char  jour[50];
 char mois[50] ;
 char annee[50];
char sexe[300];
char adresse [30];
char pays[500];
char motdepasse[50];
store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",PAYS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
  
        renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
   
        renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("pays",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
        

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column); 

       	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("motdepasse",renderer,"text",MOTDEPASSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column); 
	
	}


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("client.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{
	f=fopen("client.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",nom,prenom,sexe,jour,mois,annee,pays,adresse,cin,motdepasse)!=EOF)
		{
			gtk_list_store_append(store,&iter);	gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,SEXE,sexe,JOUR,jour,MOIS,mois,ANNEE,annee,PAYS,pays,ADRESSE,adresse,CIN,cin,MOTDEPASSE,motdepasse,-1);
		}
	   fclose(f);}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
}
















void modifier_users(char cin[], char motdepasse[]) 

{
client c;
FILE*f;
FILE*tmp;
int role=1; 
 
f=fopen("user.txt","r");
tmp=fopen("tmp.txt","w");
 if(f!=NULL) 
{ 
while(fscanf(f,"%s %s %d\n",c.cin,c.motdepasse,&role)!=EOF)	
{ 
if(strcmp(cin,c.cin)==0)
{fprintf(tmp,"%s %s %d\n",cin,motdepasse,role);}
else
fprintf(tmp,"%s %s %d\n",c.cin,c.motdepasse,role);
} 
}
fclose(f) ; 
fclose(tmp);
remove("user.txt");
rename("tmp.txt","user.txt");
}





























void creation_compte(client a)
{
 FILE *f,*f1;
 int role=1;
 f=fopen("client.txt","a+");
 if(f!=NULL)
 {
 
 fprintf(f,"%s %s %s %d %d %d %s %s %s %s \n",a.nom,a.prenom,a.pays,a.d.jour,a.d.mois,a.d.annee,a.sexe,a.adresse,a.cin,a.motdepasse);
 fclose(f);
 }
 f1=fopen("user.txt","a+");
if(f1!=NULL)
  {fprintf(f1,"%s %s %d\n",a.cin,a.motdepasse,role);
 fclose(f1);
 }
}


int verifier (char login[], char password[])
{
	FILE *f;
	char nom[30];
	char motdepasse[30];
	int role;
	f=fopen("user.txt","r");
	if(f !=NULL)
	{
		while(fscanf(f,"%s %s %d\n",nom,motdepasse,&role)!=EOF)
		{
			if(strcmp(login,nom)==0)
			{
				if(strcmp(password,motdepasse)==0)
					{
						fclose(f);
						return(role);
					}
			}
		}
		fclose(f);
		return(-1);
	}
}









void supprimer_fuser(char cin1[])
{
client c;
int role=1;
FILE *f;
FILE *tmp;
int r;
f=fopen("user.txt","r");
tmp=fopen("tmp.txt","w");
if(f!=NULL) {
if (tmp!=NULL){
while(fscanf(f,"%s %s %d\n",c.cin,c.motdepasse,&role)!=EOF){
if(strcmp(cin1,c.cin)!=0){
fprintf(tmp,"%s %s %d\n",c.cin,c.motdepasse,role);

}}
fclose(tmp);}
fclose(f);}

remove("user.txt");
rename("tmp.txt","user.txt");

}


void supprimer_fclient(char cin1[])
{
char role[3];
int r;
client c;
FILE *f;
FILE *tmp1;
f=fopen("client.txt","r");
tmp1=fopen("tmp1.txt","w");
if(f!=NULL){
 if (tmp1!=NULL)
{
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s \n",c.nom,c.prenom,c.pays,&c.d.jour,&c.d.mois,&c.d.annee,c.sexe,c.adresse,c.cin,c.motdepasse)!=EOF)
{
if(strcmp(cin1,c.cin)!=0)
{
fprintf(tmp1,"%s %s %s %d %d %d %s %s %s %s \n",c.nom,c.prenom,c.pays,c.d.jour,c.d.mois,c.d.annee,c.sexe,c.adresse,c.cin,c.motdepasse);
r=1;
}}
fclose(f);}
fclose(tmp1);}
if(r){
remove("client.txt");
rename("tmp1.txt","client.txt");
}
}



