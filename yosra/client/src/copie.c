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
GtkWidget *windowinscription;
GtkWidget *output;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
char empty[]="\0";

GtkWidget *windowfelecitations;
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
inscription(c);
windowinscription=lookup_widget(objet,"windowinscription");

gtk_widget_destroy(windowinscription);
windowfelecitations=create_windowfelecitations();
gtk_widget_show(windowfelecitations);
}

}


void
on_buttonretour_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowacceuil, *windowinscription;
windowinscription=lookup_widget(objet,"windowinscription");

gtk_widget_destroy(windowinscription);
windowacceuil=create_windowacceuil();
gtk_widget_show(windowacceuil);
}



void
on_buttoninscription1_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowacceuil, *windowinscription;
windowacceuil=lookup_widget(objet,"windowacceuil");

gtk_widget_destroy(windowacceuil);
windowinscription=create_windowinscription();
gtk_widget_show(windowinscription);
}


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *windowacceuil;
window1=lookup_widget(objet,"window1");

gtk_widget_destroy(window1);
windowacceuil=create_windowacceuil();
gtk_widget_show(windowacceuil);
}


void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window1;
GtkWidget *windowacceuil;
windowacceuil=lookup_widget(objet,"windowacceuil");

gtk_widget_destroy(windowacceuil);
window1=create_window1();
gtk_widget_show(window1);

}






void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *window1;
GtkWidget *windowfelecitations;
GtkWidget *windowinscription;

windowfelecitations=lookup_widget(objet,"windowfelecitations");
windowinscription=lookup_widget(objet,"windowinscription");
gtk_widget_destroy(windowfelecitations);

gtk_widget_destroy(windowinscription);
window1=create_window1();
gtk_widget_show(window1);

}












void
on_meconnecter_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *windowespaceclient;
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
window1=lookup_widget(objet,"window1");
gtk_widget_destroy(window1);
windowespaceclient=create_windowespaceclient();
gtk_widget_show(windowespaceclient);
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
GtkWidget *windowespaceclient;
GtkWidget *windowacceuil;
windowespaceclient=lookup_widget(objet,"windowespaceclient");

gtk_widget_destroy(windowespaceclient);
windowacceuil=create_windowacceuil();
gtk_widget_show(windowacceuil);
}








void
on_buttonsupprimer_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowespaceclient;
GtkWidget *windowdesactivercompte;
windowespaceclient=lookup_widget(objet,"windowespaceclient");

gtk_widget_destroy(windowespaceclient);
windowdesactivercompte=create_windowdesactivercompte();
gtk_widget_show(windowdesactivercompte);

}





void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowespaceclient;
GtkWidget *windowdesactivercompte;
windowdesactivercompte=lookup_widget(objet,"windowdesactivercompte");

gtk_widget_destroy(windowdesactivercompte);
windowespaceclient=create_windowespaceclient();
gtk_widget_show(windowespaceclient);

}


void
on_buttondesactivercompte1_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowdesactivercompte;
GtkWidget *windowacceuil;
GtkWidget *input;
GtkWidget *input1;
GtkWidget *output;
char cin1[100];
char motdepasse1[100];
int y;
client c;
input=lookup_widget(objet,"entrycin1");
input1=lookup_widget(objet,"entrymotdepasse1");
output=lookup_widget(objet,"label500");
strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(motdepasse1,gtk_entry_get_text(GTK_ENTRY(input1)));
y=verifier(cin1,motdepasse1);
if(y!=-1)
{
supprimer(cin1);
supprimer1(cin1);
windowdesactivercompte=lookup_widget(objet,"windowdesactivercompte");

gtk_widget_destroy(windowdesactivercompte);
windowacceuil=create_windowacceuil();
gtk_widget_show(windowacceuil);
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
GtkWidget *windowespaceclient;
GtkWidget *windowmodifierclients;
windowespaceclient=lookup_widget(objet,"windowespaceclient");

gtk_widget_destroy(windowespaceclient);
windowmodifierclients=create_windowmodifierclients();
gtk_widget_show(windowmodifierclients);


}


void
on_button999_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowespaceclient;
GtkWidget *windowmodifierclients;
windowmodifierclients=lookup_widget(objet,"windowmodifierclients");

gtk_widget_destroy(windowmodifierclients);
windowespaceclient=create_windowespaceclient();
gtk_widget_show(windowespaceclient);




}


void
on_buttonmodifierclients_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10;
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
modifier_clients(nom,prenom,sexe,j,m,a,pays,adresse,cin,motdepasse);
modifier_users(cin,motdepasse);

}






void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
{
GtkWidget *window2;
GtkWidget *windowespaceclient;
GtkWidget *treeview2;

windowespaceclient=lookup_widget(objet,"windowespaceclient");
window2=create_window2();
gtk_widget_destroy(windowespaceclient);



gtk_widget_show(window2);

treeview2=lookup_widget(window2,"treeview2");

afficher_client(treeview2);
}

}

