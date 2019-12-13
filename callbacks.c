#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verif.h"
#include "string.h"
#include<stdio.h>
#include "hotel.h"
#include "excursion.h"

void
on_buttonLogin_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget * input, * input2,*window2;
GtkWidget * output,* output2;
char nom[10], nom2[10];

input = lookup_widget(button, "entry1") ; 
input2 = lookup_widget(button, "entry2") ;

output = lookup_widget(button, "labelErreur") ; 

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(nom2,gtk_entry_get_text(GTK_ENTRY(input2)));
if (verifier(nom, nom2)==-1)
   gtk_label_set_text(GTK_LABEL(output),"erreur");
else 
{  
   window2 = create_windowagent();
   gtk_widget_show(window2);
}


}


void
on_buttonVol_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2 = lookup_widget(button,"windowagent") ;
gtk_widget_destroy(window2);
window2 = create_windowVol();
gtk_widget_show(window2);


}


void
on_buttonExcursion_clicked             (GtkWidget	     *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2 = lookup_widget(button,"windowagent") ;
gtk_widget_destroy(window2);
window2 = create_windowExcursion();
gtk_widget_show(window2);

}


void
on_buttonInscription_clicked           (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2 = create_windowInscription();
gtk_widget_show(window2);
window2 = lookup_widget(button,"window1") ;
gtk_widget_destroy(window2);
}


void
on_buttonValiderIns_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget * input, * input2,* input3,* input4,* input5,* input6;
GtkWidget * output,* output2,*jour,*mois,*annee;
char nom[20], nom2[20], nom3[20],nom4[20], nom5[20], nom6[40];
char nom7[20], nom8[20], nom9[20],nom10[20];
char login1[20], password1[20];


int role, test=0,n,x,y,z;
FILE *f;

input = lookup_widget(button, "entryUser") ; 
input2 = lookup_widget(button, "entrymdp") ;
input3 = lookup_widget(button, "entrymdp2") ;
input4 = lookup_widget(button, "entryNom") ; 
input5 = lookup_widget(button, "entryPrenom") ;
input6 = lookup_widget(button, "entryEmail") ;
jour = lookup_widget(button, "spinbuttonJour") ; 
mois = lookup_widget(button, "spinbuttonMois") ;
annee = lookup_widget(button, "spinbuttonAnnee") ;

output = lookup_widget(button, "labelErrorUser") ; 
output2 = lookup_widget(button, "labelErrorPass") ; 

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(nom2,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(nom3,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(nom4,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(nom5,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(nom6,gtk_entry_get_text(GTK_ENTRY(input6)));
x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
z=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if (strcmp(nom2,nom3)!=0)
{
   gtk_label_set_text(GTK_LABEL(output2),"mots de passe incompatibles");
   
}
f=fopen("/home/hama/Projects/project10/src/Authentification.txt","a+");
while ((test==0) && (fscanf(f,"%s %s %s %s %s %s",login1,password1,nom7,nom8,nom9,nom10)!=EOF))
     {  
       if (strcmp(nom,login1)==0)  
          test=1;
     }
if (test==1)
     gtk_label_set_text(GTK_LABEL(output),"username deja pris");

if (strcmp(nom2,nom3)!=0)
   test=2;

if (test==0)
{
 fprintf(f,"%s %s %s %s %s %d/%d/%d \n",nom,nom2,nom4,nom5,nom6,x,y,z);

}

fclose(f);
  
}



void
on_buttonRetourIns_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2 = lookup_widget(button,"windowInscription") ;
gtk_widget_destroy(window2);
window2 = create_window5();
gtk_widget_show(window2);
}


void
on_AfficherVol_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *fenetre_ajout;
GtkWidget *treeview1;
fenetre_ajout = lookup_widget(button,"windowVol") ; 
gtk_widget_destroy(fenetre_ajout);
fenetre_afficher = lookup_widget(button,"window4") ;
fenetre_afficher = create_window4 ();
gtk_widget_show(fenetre_afficher);
treeview1 = lookup_widget(fenetre_afficher, "treeview1") ;
Afficher_Vol(treeview1);
}


void
on_button8_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget * input, * input2,* input3,* input4,* input5,* input6;
GtkWidget * heure, * min,* heure2,* min2;
char nom[20], nom2[20], nom3[20],nom4[20],nom5[20],nom6[20];
int x,y,z,t;
FILE *f;
input = lookup_widget(button, "entry12") ; 
input2 = lookup_widget(button, "entry13") ; 
input3 = lookup_widget(button, "entry15") ; 
input4 = lookup_widget(button, "entry23") ; 
input5 = lookup_widget(button, "entry24") ; 
input6 = lookup_widget(button, "entry14") ;
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(nom2,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(nom3,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(nom4,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(nom5,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(nom6,gtk_entry_get_text(GTK_ENTRY(input6)));
heure= lookup_widget(button, "spinbutton10") ;
min= lookup_widget(button, "spinbutton11") ; 
heure2 = lookup_widget(button, "spinbutton12") ;
min2= lookup_widget(button, "spinbutton13");
x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure));
y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min));
z=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure2));
t=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min2));
f=fopen("/home/hama/Projects/project10/src/vol.txt","a+");
fprintf(f,"%s %s %s %s %s %s %dh%d %dh%d \n",nom,nom2,nom3,nom4,nom5,nom6,x,y,z,t);
fclose(f);


}




void
on_button9_clicked                     (GtkWidget     *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *window2;
GtkWidget *treeview1;

window2 = lookup_widget(button,"windowVol") ;
gtk_widget_destroy(window2);
fenetre_afficher = create_window4 ();
gtk_widget_show(fenetre_afficher);
treeview1 = lookup_widget(fenetre_afficher, "treeview1") ;
Afficher_Vol(treeview1);
}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button10_clicked                    (GtkWidget     *button,
                                        gpointer         user_data)
{
GtkWidget * input, * input2,* input3,* input4,* input5,* input6;
GtkWidget * heure, * min,* heure2,* min2;
char nom[20], nom2[20], nom3[20],nom4[20],nom5[20],nom6[20];
char nom1[20], nom12[20], nom13[20],nom14[20],nom15[20],nom16[20];
int x,y,z,t;
char a[20],b[20];
FILE *f,*f2;
input = lookup_widget(button, "entry18") ; 
input2 = lookup_widget(button, "entry20") ; 
input3 = lookup_widget(button, "entry21") ; 
input4 = lookup_widget(button, "entry26") ; 
input5 = lookup_widget(button, "entry25") ; 
input6 = lookup_widget(button, "entry22") ;
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(nom2,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(nom3,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(nom4,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(nom5,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(nom6,gtk_entry_get_text(GTK_ENTRY(input6)));
heure= lookup_widget(button, "spinbutton4") ;
min= lookup_widget(button, "spinbutton8") ; 
heure2 = lookup_widget(button, "spinbutton7") ;
min2= lookup_widget(button, "spinbutton9");
x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure));
y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min));
z=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure2));
t=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min2));
f=fopen("/home/hama/Projects/project10/src/vol.txt","a+");
f2=fopen("/home/hama/Projects/project10/src/vol2.txt","a+");

while (fscanf(f,"%s %s %s %s %s %s %s %s  \n",nom1,nom12,nom13,nom14,nom15,nom16,a,b)!=EOF)
{
if (strcmp(nom1,nom)==0)
{

fprintf(f2,"%s %s %s %s %s %s %dh%d %dh%d \n",nom,nom2,nom3,nom4,nom5,nom6,x,y,z,t);
}
else
{
fprintf(f2,"%s %s %s %s %s %s %s %s \n",nom1,nom12,nom13,nom14,nom15,nom16,a,b);
}

}
fclose(f);
fclose(f2);
remove("/home/hama/Projects/project10/src/vol.txt");
rename("/home/hama/Projects/project10/src/vol2.txt","/home/hama/Projects/project10/src/vol.txt");
}


void
on_button12_clicked                    (GtkWidget    *button,
                                        gpointer         user_data)
{
GtkWidget * input, * input2,* input3,* input4,* input5,* input6;
char nom[10];
char nom1[10], nom12[10], nom13[10],nom14[10],nom15[10],nom16[10],nom17[10],nom18[10];
FILE *f,*f2;
input = lookup_widget(button, "entry27") ; 

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));

f=fopen("/home/hama/Projects/project10/src/vol.txt","a+");
f2=fopen("/home/hama/Projects/project10/src/vol2.txt","a+");
if (f!=NULL)
while (fscanf(f,"%s %s %s %s %s %s %s %s \n",nom1,nom12,nom13,nom14,nom15,nom16,nom17,nom18)!=EOF)
{
if (strcmp(nom1,nom)!=0)
{
fprintf(f2,"%s %s %s %s %s %s %s %s \n",nom1,nom12,nom13,nom14,nom15,nom16,nom17,nom18);
}

}
fclose(f);
fclose(f2);
remove("/home/hama/Projects/project10/src/vol.txt");
rename("/home/hama/Projects/project10/src/vol2.txt","/home/hama/Projects/project10/src/vol.txt");
}


void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button18_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *window2,*input;
window2 = lookup_widget(button,"window1") ;
gtk_widget_destroy(window2);
window2 = create_window1();
gtk_widget_show(window2);
input = lookup_widget(button, "image5") ;
gtk_image_set_from_file(GTK_IMAGE(input),"/home/hama/Downloads/Capture10.PNG");
 

}


void
on_button20_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button22_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2 = lookup_widget(button,"window1") ;
gtk_widget_destroy(window2);
window2 = create_windowInscription();
gtk_widget_show(window2);
}


void
on_button21_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2 = lookup_widget(button,"window1") ;
gtk_widget_destroy(window2);
window2 = create_window5();
gtk_widget_show(window2);
}


void
on_button19_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2 = lookup_widget(button,"window1") ;
gtk_widget_destroy(window2);
window2 = create_window6();
gtk_widget_show(window2);
}


void
on_button26_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2 = lookup_widget(button,"window6") ;
gtk_widget_destroy(window2);
window2 = create_window5();
gtk_widget_show(window2);
}


void
on_button27_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2 = lookup_widget(button,"window6") ;
gtk_widget_destroy(window2);
window2 = create_windowInscription();
gtk_widget_show(window2);
}


void
on_button23_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2 = lookup_widget(button,"window6") ;
gtk_widget_destroy(window2);
window2 = create_window1();
gtk_widget_show(window2);
}


void
on_button24_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2 = lookup_widget(button,"window6") ;
gtk_widget_destroy(window2);
window2 = create_window6();
gtk_widget_show(window2);
}


void
on_button25_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button28_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget * input, * input2,* input3,* input4,* input5,* input6,*window2;
GtkWidget *fenetre_afficher,*treeview1;
char nom[20], nom2[20], nom3[100],nom4[20],nom5[20],nom6[20];
char nom1[200], nom12[20], nom13[20],nom14[20],nom15[20],nom16[20];
GtkWidget * combobox2,*jour,*jour2,*mois,*mois2,*annee,*annee2;
char ch1[20],ch2[20],ch[20],ch6[20],ch3[20],ch5[20],ch4[20],ch0[20];
int a,b,x,y,z,t,s;
FILE *f,*f2;
jour= lookup_widget(button, "spinbutton14") ;
mois= lookup_widget(button, "spinbutton15") ; 
annee = lookup_widget(button, "spinbutton16") ;
jour2= lookup_widget(button, "spinbutton17");
mois2= lookup_widget(button, "spinbutton18") ;
annee2= lookup_widget(button, "spinbutton19") ; 
x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
z=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
t=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour2));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois2));
b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee2));
combobox2= lookup_widget(button, "combobox2") ;

if(strcmp("Vol",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
{
f=fopen("/home/hama/Projects/project10/src/vol.txt","r");
f2=fopen("/home/hama/Projects/project10/src/volafficher.txt","a");
while (fscanf(f,"%s %s %s %s %s %s %s %s  \n",nom1,nom12,nom13,nom14,nom15,nom16,nom5,nom6)!=EOF)
{
 sprintf (ch1,"%d",x);
 sprintf (ch2,"%d",y);
 sprintf (ch3,"%d",z);
sprintf (ch4,"%d",t); 
 sprintf (ch5,"%d",a);
sprintf (ch6,"%d",b);
strcat(ch1, "/");
strcat(ch1, ch2);
strcat(ch1, "/");
strcat(ch1, ch3);
strcat(ch4, "/");
strcat(ch4, ch5);
strcat(ch4, "/");
strcat(ch4, ch6);

if ((strcmp(ch1,nom14)==0) && (strcmp(ch4,nom15)==0))
{
fprintf(f2," %s %s %s %s %s %s %s %s \n", nom1,nom12,nom13,nom14,nom15,nom16,nom5,nom6);

}
}
}
fenetre_afficher = create_windowAfficher ();
gtk_widget_show(fenetre_afficher);
treeview1 = lookup_widget(fenetre_afficher, "treeview3") ;
Afficher_Vol2(treeview1);
fclose(f);
fclose(f2);
}


void
on_button29_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window2;
window2 = lookup_widget(button,"window5") ;
gtk_widget_destroy(window2);
window2 = create_window1();
gtk_widget_show(window2);

}





void
on_buttonTrouver_clicked               (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget * input, * input2,* input3,* input4,* input5,* input6;
GtkWidget * heure, * min,* heure2,* min2;
char nom[20], nom2[20], nom3[20],nom4[20],nom5[20],nom6[20];
char nom1[20], nom12[20], nom13[20],nom14[20],nom15[20],nom16[20];
int x,y,z,t,g,h,i,j,k,l,pos,pos2,a1,a2,a3,a4;
char a[20],b[20],ch1[20],ch2[20],ch3[20],ch4[20];
FILE *f;
input = lookup_widget(button, "entry18") ; 
input2 = lookup_widget(button, "entry20") ; 
input3 = lookup_widget(button, "entry21") ; 
input4 = lookup_widget(button, "entry26") ; 
input5 = lookup_widget(button, "entry25") ; 
input6 = lookup_widget(button, "entry22") ;
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
heure= lookup_widget(button, "spinbutton4") ;
min= lookup_widget(button, "spinbutton8") ; 
heure2 = lookup_widget(button, "spinbutton7") ;
min2= lookup_widget(button, "spinbutton9");
x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure));
y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min));
z=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure2));
t=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min2));
f=fopen("/home/hama/Projects/project10/src/vol.txt","a+");


while (fscanf(f,"%s %s %s %s %s %s %s %s  \n",nom1,nom12,nom13,nom14,nom15,nom16,nom5,nom6)!=EOF)
{
if (strcmp(nom1,nom)==0)
{
gtk_entry_set_text(GTK_ENTRY(input2),nom12);
gtk_entry_set_text(GTK_ENTRY(input3),nom13);
gtk_entry_set_text(GTK_ENTRY(input4),nom14);
gtk_entry_set_text(GTK_ENTRY(input5),nom15);
gtk_entry_set_text(GTK_ENTRY(input6),nom16);


}
}
fclose(f);
}

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{ gchar *nom;
gchar *prenom;
gchar *datea;
gchar *dated;
gchar *destination;
gchar *aeroport;
gchar *heuredepart;
gchar *heurearrivee;
GtkTreeIter iter;
GtkWidget *button,* input, * input2,* input3,* input4,* input5,* input6,* input7,* input8;
GtkWidget *window1,*window2;
window1=lookup_widget(treeview,"windowVol");
GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,0,&prenom,0,&datea,0,&dated,0,&destination,0,&aeroport,0,&heuredepart,0,&heurearrivee,0);
}
window2=create_windowafficherselection;
gtk_widget_hide(window1);
gtk_widget_show(window2);
input = lookup_widget(button, "entry44") ; 
input2 = lookup_widget(button, "entry45") ; 
input3 = lookup_widget(button, "entry46") ; 
input4 = lookup_widget(button, "entry47") ; 
input5 = lookup_widget(button, "entry48") ; 
input6 = lookup_widget(button, "entry49") ;
input7 = lookup_widget(button, "entry50") ;
input8 = lookup_widget(button, "entry51") ;
gtk_entry_set_text(GTK_ENTRY(input),nom);
gtk_entry_set_text(GTK_ENTRY(input2),prenom);
gtk_entry_set_text(GTK_ENTRY(input3),datea);
gtk_entry_set_text(GTK_ENTRY(input4),dated);
gtk_entry_set_text(GTK_ENTRY(input5),destination);
gtk_entry_set_text(GTK_ENTRY(input6),aeroport);
gtk_entry_set_text(GTK_ENTRY(input7),heuredepart);
gtk_entry_set_text(GTK_ENTRY(input8),heurearrivee);



}

void
on_button30_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *window2;
GtkWidget *treeview1;

window2 = lookup_widget(button,"windowVol") ;
gtk_widget_destroy(window2);
fenetre_afficher = create_windowVol ();
gtk_widget_show(fenetre_afficher);
treeview1 = lookup_widget(fenetre_afficher, "treeview2") ;
Afficher_Vol(treeview1);
}




void
on_button31_clicked                    (GtkWidget     *button,
                                        gpointer         user_data)
{
GtkWidget * input, * input2,* input3,* input4,* input5,* input6;
GtkWidget * heure, * min,* heure2,* min2;
char nom[20], nom2[20], nom3[20],nom4[20],nom5[20],nom6[20];
int x,y,z,t;
FILE *f;
input = lookup_widget(button, "entry28") ; 
input2 = lookup_widget(button, "entry29") ; 
input3 = lookup_widget(button, "entry31") ; 
input4 = lookup_widget(button, "entry32") ; 
input5 = lookup_widget(button, "entry33") ; 
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(nom2,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(nom3,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(nom4,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(nom5,gtk_entry_get_text(GTK_ENTRY(input5)));
heure= lookup_widget(button, "spinbutton20") ;
min= lookup_widget(button, "spinbutton21") ; 
heure2 = lookup_widget(button, "spinbutton22") ;
min2= lookup_widget(button, "spinbutton23");
x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure));
y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min));
z=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure2));
t=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min2));
f=fopen("/home/hama/Projects/project10/src/excursionagent.txt","a+");
fprintf(f,"%s %s %s %s %s  %dh%d %dh%d \n",nom,nom2,nom3,nom4,nom5,x,y,z,t);
fclose(f);

}


void
on_button32_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *window2;
GtkWidget *treeview1;

window2 = lookup_widget(button,"windowExcursion") ;
gtk_widget_destroy(window2);
fenetre_afficher = create_window4 ();
gtk_widget_show(fenetre_afficher);
treeview1 = lookup_widget(fenetre_afficher, "treeview1") ;
Afficher_Excursion(treeview1);
}



void
on_button33_clicked                    (GtkWidget       *button,
                                       gpointer         user_data)
{
GtkWidget * input, * input2,* input3,* input4,* input5,* input6;
GtkWidget * heure, * min,* heure2,* min2;
char nom[20], nom2[20], nom3[20],nom4[20],nom5[20],nom6[20];
char nom1[20], nom12[20], nom13[20],nom14[20],nom15[20],nom16[20];
int x,y,z,t;
char a[20],b[20];
FILE *f,*f2;
input = lookup_widget(button, "entry36") ; 
input2 = lookup_widget(button, "entry38") ; 
input3 = lookup_widget(button, "entry39") ; 
input4 = lookup_widget(button, "entry42") ; 
input5 = lookup_widget(button, "entry41") ; 
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(nom2,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(nom3,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(nom4,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(nom5,gtk_entry_get_text(GTK_ENTRY(input5)));
heure= lookup_widget(button, "spinbutton24") ;
min= lookup_widget(button, "spinbutton26") ; 
heure2 = lookup_widget(button, "spinbutton25") ;
min2= lookup_widget(button, "spinbutton27");
x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure));
y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min));
z=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(heure2));
t=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(min2));
f=fopen("/home/hama/Projects/project10/src/excursionagent.txt","a+");
f2=fopen("/home/hama/Projects/project10/src/excursionagent2.txt","a+");

while (fscanf(f,"%s %s %s %s %s %s %s   \n",nom1,nom12,nom13,nom14,nom15,a,b)!=EOF)
{
if (strcmp(nom1,nom)==0)
{

fprintf(f2,"%s %s %s %s %s  %dh%d %dh%d \n",nom,nom2,nom3,nom4,nom5,x,y,z,t);
}
else
{
fprintf(f2,"%s %s %s %s %s %s %s  \n",nom1,nom12,nom13,nom14,nom15,a,b);
}

}
fclose(f);
fclose(f2);
remove("/home/hama/Projects/project10/src/excursionagent.txt");
rename("/home/hama/Projects/project10/src/excursionagent2.txt","/home/hama/Projects/project10/src/excursionagent.txt");
}



void
on_button34_clicked                    (GtkWidget      *button,
                                        gpointer         user_data)
{

}


void
on_button36_clicked                    (GtkWidget     *button,
                                        gpointer         user_data)
{
GtkWidget * input, * input2,* input3,* input4,* input5,* input6;
char nom[10];
char nom1[10], nom12[10], nom13[10],nom14[10],nom15[10],nom16[10],nom17[10],nom18[10];
FILE *f,*f2;
input = lookup_widget(button, "entry43") ; 

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));

f=fopen("/home/hama/Projects/project10/src/excursionagent.txt","a+");
f2=fopen("/home/hama/Projects/project10/src/excursionagent2.txt","a+");
if (f!=NULL)
while (fscanf(f,"%s %s %s %s %s %s %s  \n",nom1,nom12,nom13,nom14,nom15,nom17,nom18)!=EOF)
{
if (strcmp(nom1,nom)!=0)
{
fprintf(f2,"%s %s %s %s %s %s %s  \n",nom1,nom12,nom13,nom14,nom15,nom17,nom18);
}

}
fclose(f);
fclose(f2);
remove("/home/hama/Projects/project10/src/excursionagent.txt");
rename("/home/hama/Projects/project10/src/excursionagent2.txt","/home/hama/Projects/project10/src/excursionagent.txt");
}

void
on_button38_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}

