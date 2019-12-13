#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "facture.h"



enum   
{   c_IDFACTURE,
	c_MODEPAY,
    c_MANTANT,
    c_DATE,
    COLUMNS
};
void afficher_facture(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

		facture a; 
        store=NULL;
        int j=0,i=0;
       FILE *f;
	
	store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Réf Facture", renderer, "text",c_IDFACTURE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Montant", renderer, "text",c_MANTANT, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Moyen De paiment", renderer, "text",c_MODEPAY, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  Date", renderer, "text",c_DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


               
	
	}

	store=gtk_list_store_new (COLUMNS,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("facture.bin","rb");

	if(f==NULL)
	{

		return;
	}		
	else 

	{ 	while(!(feof(f)))
		{
			i++;
			fread(&a,sizeof(facture),1,f);

		}
	fclose(f);
/*{   c_IDFACTURE,
	c_MODEPAY,
    c_MANTANT,
    c_DATE,
    COLUMNS
};*/char jj[20],m[20],an[20],str[20];

	f=fopen("facture.bin","rb");
	while(j<i-1)
		{j++;
	fread(&a,sizeof(facture),1,f);
	sprintf(jj,"%d",a.date.j);
	sprintf(m,"%d",a.date.m);
	sprintf(an,"%d",a.date.a);
	strcpy(str,jj);strcat(str,"/");strcat(str,m);strcat(str,"/");strcat(str,an);
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,c_IDFACTURE, a.ref, c_MODEPAY, a.moy,c_MANTANT,a.mont,c_DATE,str, -1); 
		}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

void ajouter_facture(facture s)
{

FILE* f;


f=fopen("facture.bin","ab");
if(f!=NULL){
fwrite(&s,1,sizeof(facture),f);
}fclose(f);
}

//********************************************************************************




//*****************************************************************************

int supprimer_facture(facture s)
{

FILE *f;
FILE *c;int i=0 ,j=0;
facture F;
f=fopen("facture.bin","rb");
c=fopen("tempo.bin","wb");
fclose(c);
c=fopen("tempo.bin","ab");
if(f!=NULL){
	while(!(feof(f)))
		{
			i++;
			fread(&F,sizeof(facture),1,f);

		}
fclose(f);
f=fopen("facture.bin","rb");
while(j<i-1)
	{
	fread(&F,sizeof(facture),1,f);
	if(strcmp(s.ref,F.ref)!=0){fwrite(&F,sizeof(facture),1,c);}
	j++;	
	}

}
fclose(c);
fclose(f);
remove("facture.bin");
rename("tempo.bin","facture.bin");
}
//****************************************************************************
int verifier_facture (facture s)
{
FILE*f;
int t=0;
facture s1;


f=fopen("facture.txt","r+");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %d %d %d %s %s \n",s1.ref,s1.code,s1.moy,s1.mont,&s1.date.j,&s1.date.m,&s1.date.a,s1.ville,s1.pays)!=EOF){
if(strcmp(s1.ref,s.ref)==0){
t++;
break;
}
}
}fclose(f);
return t;
}
//************************************************************************
int rechercher_facture(facture s ,char m[20])
{
FILE*f;
int t=0;
facture s1;


f=fopen("facture.txt","r+");
if(f!=NULL){
while(fscanf(f,"%s %s %s %s %d %d %d %s %s \n",s1.ref,s1.code,s1.moy,s1.mont,&s1.date.j,&s1.date.m,&s1.date.a,s1.ville,s1.pays)!=EOF){
if(strcmp(m,s1.ref)==0){
t++;
break;
}
}
}fclose(f);
return t;
}
void modifier_facture (facture s, char m[20])
{/*
supprimer_facture(s,m);
ajouter_facture(s);*/
}


