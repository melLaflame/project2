#include <stdlib.h>
#include <stdio.h>
#include "entreeSortieLC.h"
#include "biblioLC.h"


Biblio* charger_n_entrees(char* nomfic, int n){

    FILE* fic = fopen(nomfic,"r");
    Biblio* new_biblio = creer_biblio();

    int i;
    int num;
    char auteur[256];
    char titre[256];
    char buf[256];
    for(i=0;i<n;i++){
        fgets(buf,256,fic);
        if(sscanf(buf,"%d %s %s",&num,titre,auteur)!= 3){
            printf("erreur de lecture");
            return NULL;
        }
        inserer_en_tete(new_biblio,num,titre,auteur);
    }
    fclose(fic);
    return new_biblio;
}

void enregistrer_biblio(Biblio *b, char* nomfic){
    FILE* fic = fopen(nomfic,"w");
    Livre* tmp = b->L;
    while(tmp != NULL){
        fprintf(fic,"%d %s %s\n",tmp->num,tmp->titre,tmp->auteur);
        tmp = tmp->suiv;
    }
    fclose(fic);
}