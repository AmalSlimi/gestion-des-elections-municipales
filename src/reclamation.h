#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#ifndef RECLAMATION_H_INCLUDED
#define RECLAMATION_H_INCLUDED


#include<gtk/gtk.h>

typedef struct
{

char msg[100];
char numbv[100];
char listerec[100];
char id[100];

}reclamation;

void ajouter_reclamation(reclamation r);

void afficher_reclamation(GtkWidget *liste);

void supprimer_reclamation(reclamation r);

void chercher_reclamation(GtkWidget *liste);

void modifier_reclamation(reclamation r);


#endif

