#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <reclamation.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"

int check ;
int x , y ;
void
on_recherche_reclam_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *recherche_reclam;
recherche_reclam=create_recherche_reclam ();
gtk_widget_show(recherche_reclam);
}


void

on_modifier_reclam_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modif_reclam;
modif_reclam=create_modif_reclam();
gtk_widget_show(modif_reclam);
}


void
on_ajouter_reclam_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajout_reclam;
ajout_reclam=create_ajout_reclam();
gtk_widget_show(ajout_reclam);
}


void
on_afficher_reclam_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_reclam;
GtkWidget *treeview_afficher_reclam;

afficher_reclam=lookup_widget(button,"afficher_reclam");
afficher_reclam=create_afficher_reclam();

gtk_widget_show(afficher_reclam);

treeview_afficher_reclam=lookup_widget(afficher_reclam,"treeview_afficher_reclam");

afficher_reclamation(treeview_afficher_reclam);
}


void
on_supprimer_reclam_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_reclam;
GtkWidget *treeview_afficher_reclam;

afficher_reclam=lookup_widget(button,"afficher_reclam");
afficher_reclam=create_afficher_reclam();

gtk_widget_show(afficher_reclam);

treeview_afficher_reclam=lookup_widget(afficher_reclam,"treeview_afficher_reclam");

afficher_reclamation(treeview_afficher_reclam);
}


void
on_add_reclam_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *output;
reclamation r;
GtkWidget *ajout_reclam;


GtkWidget *input1,*input2;
char texte1[100];
char texte2[100];

output=lookup_widget(button,"label27");
 
if (check==0)
  {
	
	gtk_label_set_text(GTK_LABEL(output),"caucher la case precedente!");
  }
 
else 
  {
	
	input1=lookup_widget(button,"entry1");
	input2=lookup_widget(button,"entry2");
	if(x==1){
	strcpy(texte1,"1");}
	else if(x==2) {
	strcpy(texte1,"2");
        }
	else if (x==3){
	strcpy(texte1,"3");
        }
	else if (x==4){
	strcpy(texte1,"4");
        }

	if(y==1){
	strcpy(texte2,"1");}
	else if (y==2){
	strcpy(texte2,"2");}
	else if (y==3){
	strcpy(texte2,"3");}
	else if (y==4){
	strcpy(texte2,"4");}

	strcpy(r.msg,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(r.numbv,texte1);
	strcpy(r.listerec,texte2);
	strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(input2)));



	ajouter_reclamation( r);

	ajout_reclam=lookup_widget(button,"ajout_reclam");
	gtk_widget_destroy(ajout_reclam);
	
}
}


void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=3;}
}


void
on_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=4;}

}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=4;}
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=3;}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=2;}
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_termes_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{check=1;}
}


void
on_recherche1_reclam_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *recherche_reclam;
GtkWidget *recherchef_reclam;
GtkWidget *treeview_recherche_reclam;
GtkWidget *input1;
reclamation r;
FILE *f1;
FILE *f2;

int d=0,i;
char c,msg[100],numbv[100],listerec[100],id[100],ident[100];
reclamation rec[100];


input1=lookup_widget(button,"entry3");
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(input1)));

// rechercher
f1=fopen("reclamation.txt","r+");
while((c=fgetc(f1)) !=EOF )
 {
  if(c=='\n')
  d++;
 }
fclose(f1);

f1=fopen("reclamation.txt","r");
for (i=0;i<d;i++)
{
fscanf(f1,"%s %s %s %s\n",rec[i].msg,rec[i].numbv,rec[i].listerec,&rec[i].id);
if (strcmp(ident,rec[i].id)==0)
{
strcpy(id,rec[i].id);
strcpy(msg,rec[i].msg);
strcpy(numbv,rec[i].numbv);
strcpy(listerec,rec[i].listerec);
}
}

}


void
on_treeview_afficher_reclam_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* msg;
	gchar* numbv;
	gchar* listerec;
	gchar* id;
	reclamation r;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
		//obtenir des valeurs de la ligne selectionnée

		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&msg,1,&numbv,2,&listerec,3,&id,-1);
		//copie
		strcpy(r.msg,msg);
		strcpy(r.numbv,numbv);
		strcpy(r.listerec,listerec);
		strcpy(r.id,id);
		//appel de la fct suppression
		supprimer_reclamation(r);
		//mise a jour
		afficher_reclamation(treeview);
	}
}


void
on_retour_afficher_reclam_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficher_reclam;
afficher_reclam=lookup_widget(button,"afficher_reclam");
gtk_widget_destroy(afficher_reclam);
}


void
on_treeview_recherche_reclam_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	GtkTreeIter iter;
	gchar* msg;
	gchar* numbv;
	gchar* listerec;
	gchar* id;
	reclamation r;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model,&iter,path))
	{
		//obtenir des valeurs de la ligne selectionnée

		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&msg,1,&numbv,2,&listerec,3,&id,-1);
		//copie
		strcpy(r.msg,msg);
		strcpy(r.numbv,numbv);
		strcpy(r.listerec,listerec);
		strcpy(r.id,id);
		//appel de la fct suppression
		supprimer_reclamation(r);
		//mise a jour
		chercher_reclamation(treeview);

	}
}


void
on_modifier_reclamation_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *output;
GtkWidget *input1,*input2,*combobox1,*combobox2;
FILE *f;

reclamation r;
int d=0,i;
char c,msg[100],numbv[100],listerec[100],id[100],ident[100],message[100];
char text1[100],text2[100];
reclamation rec[100];

/// //////////////////////////////// ////

input1=lookup_widget(button,"entry4");
strcpy(ident,gtk_entry_get_text(GTK_ENTRY(input1)));

input2=lookup_widget(button,"entry5");
strcpy(message,gtk_entry_get_text(GTK_ENTRY(input2)));

combobox1=lookup_widget(button,"combobox1");
if(strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1))))

	strcpy(text1,"1");
else if (strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1))))
	strcpy(text1,"2");
else if (strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1))))
	strcpy(text1,"3");
else strcpy(text1,"4");


combobox2=lookup_widget(button,"combobox2");

if(strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2))))

	strcpy(text2,"1");
else if (strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2))))
	strcpy(text2,"2");
else if (strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2))))
	strcpy(text2,"3");
else strcpy(text2,"4");

strcpy(r.msg,message);
strcpy(r.numbv,text1);
strcpy(r.listerec,text2);
strcpy(r.id,ident);



output=lookup_widget(button,"label18");

/// rechercher////

f=fopen("reclamation.txt","r+");
while((c=fgetc(f)) !=EOF )
 {
  if(c=='\n')
  d++;
 }
fclose(f);

f=fopen("reclamation.txt","r");
for (i=0;i<d;i++)
{
fscanf(f,"%s %s %s %s\n",rec[i].msg,rec[i].numbv,rec[i].listerec,&rec[i].id);
if (strcmp(ident,rec[i].id)==0)
{
strcpy(id,rec[i].id);
}
}

if  (strcmp(id,ident)==0)
	{
	modifier_reclamation(r) ;// modifier 
	gtk_label_set_text(GTK_LABEL(output),"Modification terminer !");
	}





else
	
	gtk_label_set_text(GTK_LABEL(output)," introuvable !");
}


