#include <gtk/gtk.h>


void
on_Ajouter_facture_clicked             (GtkWidget       *object_graphique,
                                        gpointer         user_data);

void
on_button_Edit_facture_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_Delete_Facture_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_save_facture_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_facture_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
