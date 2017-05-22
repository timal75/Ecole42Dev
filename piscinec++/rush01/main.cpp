/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:52:27 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/22 02:49:41 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <gtk/gtk.h>

int main(int argc,char **argv)
{
    GtkWidget* Fenetre = NULL;
    GtkWidget* Label = NULL;
    gchar* TexteConverti = NULL;
    GtkWidget *pVBox;

    GtkWidget* Fenetre1 = NULL;
    GtkWidget* Label1 = NULL;
    gchar* TexteConverti1 = NULL;

    gtk_init(&argc, &argv);

    Fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);  // Définition de la fenêtre
    gtk_window_set_title(GTK_WINDOW(Fenetre), "Le texte avec les labels"); // Titre de la fenêtre
    gtk_window_set_default_size(GTK_WINDOW(Fenetre), 800, 400); // Taille de la fenêtre
    
    TexteConverti = g_locale_to_utf8("<span face=\"Verdana\" foreground=\"#73b5ff\" size=\"xx-large\"><b>Le site du Zéro</b></span>\n <span face=\"Verdana\" foreground=\"#39b500\" size=\"x-large\">Le tuto GTK</span>\n", -1, NULL, NULL, NULL);  //Convertion du texte avec les balises
    Label=gtk_label_new(TexteConverti); // Application de la convertion à notre label
    
    pVBox = gtk_box_new(GTK_ORIENTATION_VERTICAL , 5);
    gtk_box_pack_start(GTK_BOX(pVBox), Label, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(pVBox), Label1, TRUE, TRUE, 5);
    TexteConverti1 = g_locale_to_utf8("<span face=\"Verdana\" foreground=\"#73b5ff\" size=\"xx-large\"><b>Le site des Zozo</b></span>\n <span face=\"Verdana\" foreground=\"#39b500\" size=\"x-large\">Le tuto GTK</span>\n", -1, NULL, NULL, NULL);  //Convertion du texte avec les balises
    
    Label1=gtk_label_new(TexteConverti); // Application de la convertion à notre label
    gtk_box_pack_start(GTK_BOX(pVBox), Label, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(pVBox), Label1, TRUE, FALSE, 0);
    g_free(TexteConverti1); // Libération de la mémoire
    g_free(TexteConverti); // Libération de la mémoire
    gtk_window_set_position(GTK_WINDOW(Fenetre), GTK_WIN_POS_CENTER);


    gtk_label_set_use_markup(GTK_LABEL(Label), TRUE); // On dit que l'on utilise les balises pango

    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER); // On centre notre texte


    gtk_container_add(GTK_CONTAINER(Fenetre), pVBox);

    gtk_widget_show_all(Fenetre); // On affiche 'Fenetre' et tout ce qu'il contient
    // gtk_widget_show_all(Fenetre1); // On affiche 'Fenetre' et tout ce qu'il contient

    g_signal_connect(G_OBJECT(Fenetre), "delete-event", G_CALLBACK(gtk_main_quit), NULL); // Je ne commente pas cette fonction, vous la verrez dans le chapitre suivant.

    gtk_main();

    return EXIT_SUCCESS;
}



