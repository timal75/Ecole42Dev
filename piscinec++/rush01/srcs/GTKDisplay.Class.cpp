/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GTKDisplay.Class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:48:01 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/22 16:48:10 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "GTKDisplay.Class.hpp"

GTKDisplay::GTKDisplay(void) : IMonitorDisplay ()
{
}

GTKDisplay::~GTKDisplay(void)
{
}

GTKDisplay::GTKDisplay(ModuleList module)
{
	ModuleList::iterator			it = module.begin();
	ModuleList::iterator			ite = module.end();

	while (it !=ite)
	{
		StringList						lst = (*it)->getContent();
		std::string						title = (*it)->getTitle();
		StringList::iterator			itl = lst.begin();
		StringList::iterator			itel = lst.end();
		
		this->_content.push_back(title);
		while (itl != itel)
		{

			this->_content.push_back(*itl);
			itl++;
		}		
		it++;
	}
}

GTKDisplay::UpdateChamp(ModuleList module)
{
	delete this->_content;
	new this->_content;
	ModuleList::iterator			it = module.begin();
	ModuleList::iterator			ite = module.end();

	while (it !=ite)
	{
		StringList						lst = (*it)->getContent();
		std::string						title = (*it)->getTitle();
		StringList::iterator			itl = lst.begin();
		StringList::iterator			itel = lst.end();
		
		this->_content.push_back(title);
		while (itl != itel)
		{

			this->_content.push_back(*itl);
			itl++;
		}		
		it++;
	}
}

void GTKDisplay::ShowWindow(void)
{
		StringList::iterator			it = this->_content.begin();
		StringList::iterator			ite = this->_content.end();
		gchar* Texte = NULL;
		GtkWidget* Fenetre = NULL;
    	GtkWidget* Label = NULL;
    	GtkWidget *pVBox;
    	GtkWidget *pHBox;
    	GtkWidget     *m_ButtonQuit = gtk_button_new_with_label("Quit");
		
		Fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    	gtk_window_set_title(GTK_WINDOW(Fenetre), "ft_gkrellm");
    	gtk_window_set_default_size(GTK_WINDOW(Fenetre), 200, 600);
    	pVBox = gtk_box_new(GTK_ORIENTATION_VERTICAL , 5);
    	pHBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL , 5);	
    	gtk_window_set_position(GTK_WINDOW(Fenetre), GTK_WIN_POS_CENTER);
		while (it != ite)
		{
			Label=gtk_label_new((*it).c_str());
			gtk_box_pack_start(GTK_BOX(pVBox), Label, FALSE, FALSE, 2);
			it++;
		}
		g_signal_connect(G_OBJECT(m_ButtonQuit), "clicked", G_CALLBACK(gtk_main_quit), NULL);
		gtk_box_pack_start(GTK_BOX(pHBox), m_ButtonQuit, TRUE, TRUE, 2);
		gtk_label_set_use_markup(GTK_LABEL(Label), TRUE);
    	gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);
		gtk_container_add(GTK_CONTAINER(Fenetre), pVBox);
		gtk_box_pack_start(GTK_BOX(pVBox), pHBox);
    	gtk_widget_show_all(Fenetre);
    	g_signal_connect(G_OBJECT(Fenetre), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
    	gtk_main();	
}

GTKDisplay::GTKDisplay(GTKDisplay const &gtk) : IMonitorDisplay ()
{
	*this = gtk;
}

GTKDisplay &GTKDisplay::operator=(GTKDisplay const &gtk)
{
	this->_content = gtk._content;
	return(*this);
}