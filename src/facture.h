

#include <gtk/gtk.h>
typedef struct 
{
int j;
int m;
int a;
}da ;


typedef struct 
{
char ref[20];
char moy[20];
char mont[20];
char code[20];
char ville[20];
 da date;
char pays[20];

}facture;
void ajouter_facture(facture s);
void modifier_facture(facture s,char m[20]);
int supprimer_facture(facture s);
int rechercher_facture(facture s,char m[20]);
void afficher_facture(GtkWidget *liste);
