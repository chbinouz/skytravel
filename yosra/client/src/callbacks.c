#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include<gtk/gtkclist.h>
#include<gdk/gdkkeysyms.h>


void
on_buttoninscription_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
char motdepasse1[100];

GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*input11;
GtkWidget *fenetre_inscription;
GtkWidget *output;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
char empty[]="\0";

GtkWidget *felecitations;
output5=lookup_widget(objet,"erreur5");
output4=lookup_widget(objet,"erreur4");
output3=lookup_widget(objet,"erreur3");
output2=lookup_widget(objet,"erreur2");
output1=lookup_widget(objet,"erreur1");
output=lookup_widget(objet,"erreur");
input1=lookup_widget(objet,"entrynom");
input2=lookup_widget(objet,"entryprenom");
input3=lookup_widget(objet,"combobox1");
input4=lookup_widget(objet,"jour");
input5=lookup_widget(objet,"mois");
input6=lookup_widget(objet,"annee");
input7=lookup_widget(objet,"combobox2");
input8=lookup_widget(objet,"entryadresse");
input9=lookup_widget(objet,"entrycin");
input10=lookup_widget(objet,"entrymotdepasse");
input11=lookup_widget(objet,"entrymotdepasse1");
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
c.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
c.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
c.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(c.motdepasse,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(motdepasse1,gtk_entry_get_text(GTK_ENTRY(input11)));
if(strcmp(c.nom,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output1),"Ce champ est obligatoire.");
}
else if(strcmp(c.prenom,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output2),"Ce champ est obligatoire.");
}
else if(strcmp(c.adresse,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output3),"Ce champ est obligatoire.");
}
else if(strcmp(c.cin,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output4),"Ce champ est obligatoire.");
}
else if(strcmp(c.motdepasse,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output5),"Ce champ est obligatoire.");
}
else if(strcmp(motdepasse1,c.motdepasse)!=0)
{
gtk_label_set_text(GTK_LABEL(output),"Les mots de passe saisis ne sont pas identiques.");
}

else
{
creation_compte(c);
fenetre_inscription=lookup_widget(objet,"fenetre_inscription");

gtk_widget_destroy(fenetre_inscription);
felecitations=create_felecitations();
gtk_widget_show(felecitations);
}

}


void
on_buttonretour_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_acceuil, *fenetre_inscription;
fenetre_inscription=lookup_widget(objet,"fenetre_inscription");

gtk_widget_destroy(fenetre_inscription);
fenetre_acceuil=create_fenetre_acceuil();
gtk_widget_show(fenetre_acceuil);
}



void
on_buttoninscription1_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_acceuil, *fenetre_inscription;
fenetre_acceuil=lookup_widget(objet,"fenetre_acceuil");

gtk_widget_destroy(fenetre_acceuil);
fenetre_inscription=create_fenetre_inscription();
gtk_widget_show(fenetre_inscription);
}


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *authentification;
GtkWidget *fenetre_acceuil;
authentification=lookup_widget(objet,"authentification");

gtk_widget_destroy(authentification);
fenetre_acceuil=create_fenetre_acceuil();
gtk_widget_show(fenetre_acceuil);
}


void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *authentification;
GtkWidget *fenetre_acceuil;
fenetre_acceuil=lookup_widget(objet,"fenetre_acceuil");

gtk_widget_destroy(fenetre_acceuil);
authentification=create_authentification();
gtk_widget_show(authentification);

}






void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *authentification;
GtkWidget *felecitations;
GtkWidget *fenetre_inscription;

felecitations=lookup_widget(objet,"felecitations");
fenetre_inscription=lookup_widget(objet,"fenetre_inscription");
gtk_widget_destroy(felecitations);

gtk_widget_destroy(fenetre_inscription);
authentification=create_authentification();
gtk_widget_show(authentification);

}












void
on_meconnecter_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *authentification;
GtkWidget *espace_client;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *output;
char id[100];
char mdp[100];
int x;
input1=lookup_widget(objet,"entrycin");
input2=lookup_widget(objet,"entrypassword");
output=lookup_widget(objet,"label25");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(mdp,gtk_entry_get_text(GTK_ENTRY(input2)));
x=verifier(id,mdp);
if (x!=-1)
{
authentification=lookup_widget(objet,"authentification");
gtk_widget_destroy(authentification);
espace_client=create_espace_client();
gtk_widget_show(espace_client);
}



else
{
gtk_label_set_text(GTK_LABEL(output),"CIN ou mot de passe invalide");
}

}


void
on_deconnexion_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_client;
GtkWidget *fenetre_acceuil;
espace_client=lookup_widget(objet,"espace_client");

gtk_widget_destroy(espace_client);
fenetre_acceuil=create_fenetre_acceuil();
gtk_widget_show(fenetre_acceuil);
}








void
on_buttonsupprimer_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_client;
GtkWidget *fenetre_suppcompte;
espace_client=lookup_widget(objet,"espace_client");

gtk_widget_destroy(espace_client);
fenetre_suppcompte=create_fenetre_suppcompte();
gtk_widget_show(fenetre_suppcompte);

}





void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_client;
GtkWidget *fenetre_suppcompte;
fenetre_suppcompte=lookup_widget(objet,"fenetre_suppcompte");

gtk_widget_destroy(fenetre_suppcompte);
espace_client=create_espace_client();
gtk_widget_show(espace_client);

}


void
on_buttondesactivercompte1_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_suppcompte;
GtkWidget *fenetre_acceuil;
GtkWidget *input;
GtkWidget *input1;
GtkWidget *output;
char cin1[100];
char motdepasse1[100];
int y;
client c;
input=lookup_widget(objet,"entrycin1");
input1=lookup_widget(objet,"entrymotdepasse1");
output=lookup_widget(objet,"desactlabel");
strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(motdepasse1,gtk_entry_get_text(GTK_ENTRY(input1)));
y=verifier(cin1,motdepasse1);
if(y!=-1)
{
//supprimer_fclient(cin1);
supprimer_fuser(cin1);
fenetre_suppcompte=lookup_widget(objet,"fenetre_suppcompte");

gtk_widget_destroy(fenetre_suppcompte);
fenetre_acceuil=create_fenetre_acceuil();
gtk_widget_show(fenetre_acceuil);
}
else
{
gtk_label_set_text(GTK_LABEL(output),"cin ou mot de passe invalide.");
}

}


void
on_button777_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_client;
GtkWidget *fenetre_modifier;
espace_client=lookup_widget(objet,"espace_client");

gtk_widget_destroy(espace_client);
fenetre_modifier=create_fenetre_modifier();
gtk_widget_show(fenetre_modifier);


}


void
on_button999_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_client;
GtkWidget *fenetre_modifier;
fenetre_modifier=lookup_widget(objet,"fenetre_modifier");

gtk_widget_destroy(fenetre_modifier);
espace_client=create_espace_client();
gtk_widget_show(espace_client);




}


void
on_buttonmodifierclients_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10;
GtkWidget *fenetre_acceuil,*fenetre_modifier;
char nom[100];
char prenom[1000];
char sexe[100];
int j;
int m;
int a;
char pays[100];
char adresse[100];
char cin[100];
char motdepasse[100];
input1=lookup_widget(objet,"entrynom10");
input2=lookup_widget(objet,"entryprenom100");
input3=lookup_widget(objet,"combobox333");
input4=lookup_widget(objet,"jour10");
input5=lookup_widget(objet,"mois10");
input6=lookup_widget(objet,"annee10");
input7=lookup_widget(objet,"combobox444");
input8=lookup_widget(objet,"entryadresse10");
input9=lookup_widget(objet,"entrycin10");
input10=lookup_widget(objet,"entrymotdepasse10");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
strcpy(pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
strcpy(adresse,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(motdepasse,gtk_entry_get_text(GTK_ENTRY(input10)));

modifier_clients(nom,prenom,pays,j,m,a,sexe,adresse,cin,motdepasse);
modifier_users(cin,motdepasse);


fenetre_modifier=lookup_widget(objet,"fenetre_modifier");
gtk_widget_destroy(fenetre_modifier);
fenetre_acceuil=create_fenetre_acceuil();
gtk_widget_show(fenetre_acceuil);


}






void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
{
GtkWidget *fenetre_affich;
GtkWidget *espace_client;
GtkWidget *treeview2;

espace_client=lookup_widget(objet,"espace_client");

gtk_widget_destroy(espace_client);

fenetre_affich=create_fenetre_affich();
fenetre_affich=lookup_widget(fenetre_affich,"fenetre_affich");
gtk_widget_show(fenetre_affich);

treeview2=lookup_widget(fenetre_affich,"treeview2");

afficher_client(treeview2);
}

}


void
on_buttonretoureclient_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_client;
GtkWidget *fenetre_affich;
fenetre_affich=lookup_widget(objet,"fenetre_affich");

gtk_widget_destroy(fenetre_affich);
espace_client=create_espace_client();
gtk_widget_show(espace_client);
}

