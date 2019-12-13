#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "facture.h"
int on_butt_Ajouter_facture_clicked =0;int on_butt_Edit_facture_clicked =0;
facture selected_facture;
void
on_Ajouter_facture_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Add_Fact,*Main_Menue;
Add_Fact = create_window2 ();
  gtk_widget_show (Add_Fact);
Main_Menue=lookup_widget(button,"Main_Menue_Facture");
gtk_widget_destroy (Main_Menue);
on_butt_Ajouter_facture_clicked =1;
on_butt_Edit_facture_clicked =0;
}


void
on_button_Edit_facture_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{

on_butt_Edit_facture_clicked =1;
on_butt_Ajouter_facture_clicked =0;


GtkWidget *Add_Fact,*Main_Menue;
Add_Fact = create_window2 ();
  gtk_widget_show (Add_Fact);
Main_Menue=lookup_widget(button,"Main_Menue_Facture");
gtk_widget_destroy (Main_Menue);
GtkWidget *ref,*date,*montant,*code,*ville,*pays1,*jour,*mois,*annee,*input1,*output1;// modifier facture
facture s ;
ref=lookup_widget(Add_Fact, "entry_Ref_Facture");
jour=lookup_widget(Add_Fact, "spinbutton_jour_facture");
mois=lookup_widget(Add_Fact, "spinbutton_mois_facture");
annee=lookup_widget(Add_Fact, "spinbutton_anne_facture");
montant=lookup_widget(Add_Fact, "entry_montant_facture");
code=lookup_widget(Add_Fact, "entry_code_postale_facture");
ville=lookup_widget(Add_Fact, "entry_ville_facture");
input1=lookup_widget(Add_Fact,"combobox_facture");
pays1=lookup_widget(Add_Fact, "entry_pays_facture");


gtk_entry_set_text(ref,selected_facture.ref);
gtk_entry_set_text(montant,selected_facture.mont);
gtk_entry_set_text(code,selected_facture.code);
gtk_entry_set_text(ville,selected_facture.ville);
gtk_entry_set_text(pays1,selected_facture.pays);

gtk_spin_button_set_value(jour,selected_facture.date.j);
gtk_spin_button_set_value(mois,selected_facture.date.m);
gtk_spin_button_set_value(annee,selected_facture.date.a);

}


void
on_button_Delete_Facture_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget * Main_Menue;
Main_Menue=lookup_widget(button,"Main_Menue_Facture");
gtk_widget_destroy (Main_Menue);

supprimer_facture(selected_facture);

Main_Menue = create_Main_Menue_Facture ();
  gtk_widget_show (Main_Menue);
GtkWidget *tree;
tree=lookup_widget(Main_Menue,"treeview_facture");
afficher_facture(tree);

}


void
on_button_save_facture_clicked         (GtkWidget       *object_graphique,
                                        gpointer         user_data)
{
GtkWidget *ref,*date,*montant,*code,*ville,*pays1,*jour,*mois,*annee,*input1,*output1;// modifier facture
facture s ;

ref=lookup_widget(object_graphique, "entry_Ref_Facture");
jour=lookup_widget(object_graphique, "spinbutton_jour_facture");
mois=lookup_widget(object_graphique, "spinbutton_mois_facture");
annee=lookup_widget(object_graphique, "spinbutton_anne_facture");
montant=lookup_widget(object_graphique, "entry_montant_facture");
code=lookup_widget(object_graphique, "entry_code_postale_facture");
ville=lookup_widget(object_graphique, "entry_ville_facture");
input1=lookup_widget(object_graphique,"combobox_facture");
pays1=lookup_widget(object_graphique, "entry_pays_facture");
strcpy(s.ref,gtk_entry_get_text(GTK_ENTRY(ref)));

strcpy(s.moy,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
s.date.j=gtk_spin_button_get_value(GTK_SPIN_BUTTON(jour));
s.date.a=gtk_spin_button_get_value(GTK_SPIN_BUTTON(annee));
s.date.m=gtk_spin_button_get_value(GTK_SPIN_BUTTON(mois));

strcpy(s.mont,gtk_entry_get_text(GTK_ENTRY(montant)));

strcpy(s.code,gtk_entry_get_text(GTK_ENTRY(code)));
strcpy(s.ville,gtk_entry_get_text(GTK_ENTRY(ville)));
strcpy(s.pays,gtk_entry_get_text(GTK_ENTRY(pays1)));

if(on_butt_Edit_facture_clicked ==1)
supprimer_facture(selected_facture);
FILE *f;
facture FACT;
int check_id_fact=1;
f=fopen("facture.bin","rb");

	if(f==NULL)
	{

		return;
	}		
	else 

	{ 	while(!(feof(f)))
		{
			
			fread(&FACT,sizeof(facture),1,f);if(strcmp(FACT.ref,s.ref)==0)check_id_fact=0;

		}
	fclose(f);
	}


if(check_id_fact==1)
{


ajouter_facture(s);

GtkWidget *Add_Fact,*Main_Menue;

Main_Menue = create_Main_Menue_Facture ();
  gtk_widget_show (Main_Menue);

Add_Fact=lookup_widget(object_graphique,"window2");
gtk_widget_destroy (Add_Fact);

GtkWidget *tree;
tree=lookup_widget(Main_Menue,"treeview_facture");
afficher_facture(tree);
}
else
	{
	g_print("\n ID facture est defa saisie");
	}


}


void
on_treeview_facture_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
gchar *str_data;
GtkListStore *list_store;
list_store=gtk_tree_view_get_model(treeview);
GtkTreeIter iter;
if(gtk_tree_model_get_iter(GTK_TREE_MODEL(list_store),&iter,path))
{
gtk_tree_model_get(GTK_TREE_MODEL(list_store),&iter,0,&str_data,-1);

}
strcpy(selected_facture.ref,str_data);

FILE *f;facture F;
f=fopen("facture.bin","rb");
while(!feof(f))
	{
	fread(&F,sizeof(facture),1,f);
	if(strcmp(selected_facture.ref,F.ref)==0){selected_facture=F;}	
	}
fclose(f);
}

