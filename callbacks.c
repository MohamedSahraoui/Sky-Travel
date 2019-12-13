#ifdef HAVE_CONFIG_H
# include <config.h>
#endif
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


#include "fct_divers.h"

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"



void
on_buttonB1_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)//ajouter-reservation
{
GtkWidget *input1 , *input2 , *output1 , *output2, *window1, *output3, *output6,
*jour_debut, *mois_debut, *annee_debut, *jour_fin, *mois_fin, *annee_fin, *combobox1, *combobox2, *combobox3, *combobox4;

/*
typedef struct C C;
struct C
{
	char nom[20],  prenom[20], username[20], password[20];

};
*/
client C ;
char hotel[50], heb[50],vol[50], voiture[50] ;
//char excursion[20] , vol[20], voiture[20], hotel[20], date_debut[20], date_fin[20];
int jourdebut, moisdebut,anneedebut,jourfin,moisfin,anneefin;
//int aa, bb, cc, dd, ee, ff;
//window1=create_windowA2 ();
input1 = lookup_widget (objet_graphique , "entryB1");
input2 = lookup_widget (objet_graphique , "entryB2");
//input3 = lookup_widget (objet_graphique , "entryB3");
//input4 = lookup_widget (objet_graphique , "entryB4");
output1 =lookup_widget (objet_graphique , "labelB5");
output2 =lookup_widget (objet_graphique , "labelB6");
output3 =lookup_widget (objet_graphique , "labelB7");
//output4 =lookup_widget (objet_graphique , "labelB8");
//output5 =lookup_widget (objet_graphique , "labelB9");
output6 =lookup_widget (objet_graphique , "labelB15");

combobox1 = lookup_widget(objet_graphique, "comboboxB1");
combobox2 = lookup_widget(objet_graphique, "comboboxB2");
combobox3 = lookup_widget(objet_graphique, "comboboxB3");
combobox4 = lookup_widget(objet_graphique, "comboboxB4");

jour_debut = lookup_widget(objet_graphique, "spinbuttonB1");
mois_debut = lookup_widget(objet_graphique, "spinbuttonB3");
annee_debut = lookup_widget(objet_graphique, "spinbuttonB2");
jour_fin = lookup_widget(objet_graphique, "spinbuttonB4");
mois_fin = lookup_widget(objet_graphique, "spinbuttonB5");
annee_fin = lookup_widget(objet_graphique, "spinbuttonB6");

strcpy(heb, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(hotel, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
strcpy(vol, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));
strcpy(voiture, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));
strcpy (C.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy (C.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
//strcpy (C.username,gtk_entry_get_text(GTK_ENTRY(input3)));
//strcpy (C.password,gtk_entry_get_text(GTK_ENTRY(input4)));
jourdebut = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_debut));
moisdebut = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_debut));
anneedebut = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee_debut));
jourfin = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_fin));
moisfin = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_fin));
anneefin = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee_fin));

/*aa = sscanf(jourdebut , "%d" , &aa);
bb = sscanf(moisdebut , "%d" , &bb);
cc = sscanf(anneedebut , "%d" , &cc);
dd = sscanf(jourfin , "%d" , &dd);
ee = sscanf(moisfin , "%d" , &ee);
ff = sscanf(anneefin , "%d" , &ff);

strcat(date_debut, aa);
strcat(date_debut, "/");
strcat(date_debut, bb);
strcat(date_debut, "/");
strcat(date_debut, cc);
strcat(date_fin, dd);
strcat(date_fin, "/");
strcat(date_fin, ee);
strcat(date_fin, "/");
strcat(date_fin, ff);*/


if (strcmp(C.nom,"")==0 || strcmp(C.prenom,"")==0 || strcmp(C.username,"")==0 || strcmp(C.password,"")==0) 
{
gtk_label_set_text(GTK_LABEL(output6),"Remplir tous les champs");
}
else  
{
ajouter_reserv (C, hotel, heb, vol, voiture, jourdebut, moisdebut, anneedebut, jourfin, moisfin, anneefin);
//gtk_widget_show(window1);
}
}





void
on_buttonA1_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *win2;
	win2=create_windowA3 ();	
	gtk_widget_show(win2);
}


void
on_buttonA3_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *nom , *prenom , *ciin , *j, *m, *y , *nt , *em , *passe , *output ;
	gboolean toggle1,toggle2;  
	cll A ;
	
	
	
	nom=lookup_widget(objet_graphique,"entryA4");
	prenom=lookup_widget(objet_graphique,"entryA5");
	ciin=lookup_widget(objet_graphique,"entryA10");
	em=lookup_widget(objet_graphique,"entryA6");
	nt=lookup_widget(objet_graphique,"entryA7");
	passe=lookup_widget(objet_graphique,"entryA8");
	
	j=lookup_widget(objet_graphique,"spinbutton1A");
	m=lookup_widget(objet_graphique,"spinbutton2A");
	y=lookup_widget(objet_graphique,"spinbutton3A");

	output=lookup_widget(objet_graphique,"labelchamp");


	strcpy(A.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(A.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(A.cin,gtk_entry_get_text(GTK_ENTRY(ciin)));
	strcpy(A.tel,gtk_entry_get_text(GTK_ENTRY(nt)));
	strcpy(A.mail,gtk_entry_get_text(GTK_ENTRY(em)));
	strcpy(A.passwd,gtk_entry_get_text(GTK_ENTRY(passe)));
	
	A.jj=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
	A.mm=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
	A.yy=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(y));


	toggle1 = on_checkbuttonA2_toggled(objet_graphique,user_data);
	toggle2 = on_checkbuttonA1_toggled(objet_graphique,user_data);

                 	if (toggle1)
					strcpy(A.sexe,"Female");
	        	 if (toggle2)
					strcpy(A.sexe,"Male");
	

	if (((strcmp(A.nom,"") ==0) || (strcmp(A.prenom,"") ==0) || (strcmp(A.cin,"") ==0) || (strcmp(A.tel,"") ==0) || (strcmp(A.mail,"") ==0) 		|| (strcmp(A.passwd,"") ==0) || (strcmp(A.sexe,"") ==0) ))
	 {
		
		gtk_label_set_text(GTK_LABEL(output),"Remplir tous les champs");
	 }
	
	else{
		gtk_label_set_text(GTK_LABEL(output),"Client ajouté aver succés");
        ajouter_client(A); 
  	
		}	

}

gboolean
on_checkbuttonA1_toggled                (GtkWidget    *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget	*togglebutton1,*togglebutton2;
	gboolean etat;
	togglebutton1=lookup_widget(objet_graphique,"checkbuttonA1");
	togglebutton2=lookup_widget(objet_graphique,"checkbuttonA2");
	etat=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton1));
	if(etat){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton2),FALSE);
	}
	return etat;
}

gboolean
on_checkbuttonA2_toggled                (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget	*togglebutton1,*togglebutton2;
	gboolean etat;
	togglebutton1=lookup_widget(objet_graphique,"checkbuttonA1");
	togglebutton2=lookup_widget(objet_graphique,"checkbuttonA2");
	etat=gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton2));
	if(etat){
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton1),FALSE);
	}
	return etat;
}





void
on_buttonB2_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	FILE* f ;
	
		GtkWidget *tree ,*emp;

                emp=lookup_widget(objet_graphique,"windowB1");
		tree=lookup_widget(emp,"treeviewB1");
		afficher_reservation (tree);
	

}

char test[50] ;
void
on_buttonB3_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *win2,*window ,*te ;
        window=lookup_widget(objet_graphique,"windowB1");
        te=lookup_widget(objet_graphique,"entryB5");
	strcpy(test,gtk_entry_get_text(GTK_ENTRY(te)));
	win2=create_windowC1 ();	
	gtk_widget_show(win2);
	gtk_widget_hide(window);



}


void
on_buttonB4_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *num_reservation, *mdp;
	char num[50]; //passwd[20];


	num_reservation=lookup_widget(objet_graphique,"entryB7");
	//mdp=lookup_widget(obj,"entryB8");
	strcpy(num,gtk_entry_get_text(GTK_ENTRY(num_reservation)));
	//strcpy(passwd,gtk_entry_get_text(GTK_ENTRY(mdp)));
	//if(!strcmp(passwd,"")){
		supprimer_reserv(num);
	//}

}


void
on_buttonC1_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f ;
FILE *f2 ;

	GtkWidget *exc, *voit, *vol, *hot, *jour_debut, *mois_debut, *annee_debut, *jour_fin, *mois_fin, *annee_fin;
	char heb[20], voiture[20], vol1[20], hotel[20], date_debut[20], date_fin[20];
	int jourdebut, moisdebut, anneedebut, jourfin, moisfin, anneefin;
	//int a, b, c, d, e, f;
	

	exc = lookup_widget(objet_graphique, "comboboxC1");
	voit = lookup_widget(objet_graphique, "comboboxC2");
	vol = lookup_widget(objet_graphique, "comboboxC3");
	hot = lookup_widget(objet_graphique, "comboboxC4");
	jour_debut = lookup_widget(objet_graphique, "spinbuttonC1");
	mois_debut = lookup_widget(objet_graphique, "spinbuttonC2");
	annee_debut = lookup_widget(objet_graphique, "spinbuttonC3");
	jour_fin = lookup_widget(objet_graphique, "spinbuttonC4");
	mois_fin = lookup_widget(objet_graphique, "spinbuttonC5");
	annee_fin = lookup_widget(objet_graphique, "spinbuttonC6");


	jourdebut = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_debut));
	moisdebut = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_debut));
	anneedebut = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee_debut));
	jourfin = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_fin));
	moisfin = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_fin));
	anneefin = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee_fin));

	/*a = sscanf(jourdebut , "%d" , &a);
	b = sscanf(moisdebut , "%d" , &b);
	c = sscanf(anneedebut , "%d" , &c);
	d = sscanf(jourfin , "%d" , &d);
	e = sscanf(moisfin , "%d" , &e);
	f = sscanf(anneefin , "%d" , &f);

	strcat(date_debut, a);
	strcat(date_debut, "/");
	strcat(date_debut, b);
	strcat(date_debut, "/");
	strcat(date_debut, c);
	strcat(date_fin, d);
	strcat(date_fin, "/");
	strcat(date_fin, e);
	strcat(date_fin, "/");
	strcat(date_fin, f);*/

	strcpy(heb,gtk_combo_box_get_active_text(GTK_COMBO_BOX(exc)));
	strcpy(voiture,gtk_combo_box_get_active_text(GTK_COMBO_BOX(voit)));
	strcpy(vol1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(vol)));
	strcpy(hotel,gtk_combo_box_get_active_text(GTK_COMBO_BOX(hot)));

     modifier_reservation(test,heb,voiture,vol1,hotel,jourdebut,moisdebut,anneedebut,jourfin,moisfin,anneefin);
	

GtkWidget *win2,*window;
        window=lookup_widget(objet_graphique,"windowC1");
	win2=create_windowB1 ();	
	gtk_widget_show(win2);
	gtk_widget_hide(window);



}





void
on_buttonX1_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_buttonAAA_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *win2,*windowA2;
	win2=create_windowX1 ();	
	gtk_widget_show(win2);
	gtk_widget_hide(windowA2);

}
