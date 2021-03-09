#include <stdlib.h>
#include <stdio.h>
#include "entreeSortieH.h"
#include "biblioH.h"

BiblioH* charger_n_entreesH(char* nomfic, int n,int m){
    FILE* fic = fopen(nomfic,"r");
    BiblioH* new_biblio = creer_biblioH(m);

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
        inserer(new_biblio,num,titre,auteur);
    }
    fclose(fic);
    return new_biblio;
}

void enregistrer_biblioH(BiblioH *b, char* nomfic){
    FILE* fic = fopen(nomfic,"w");
    int i;
    for(i=0;i<b->m;i++){
        LivreH* tmp = (b->T)[i];
        while(tmp!=NULL){
            fprintf(fic,"%d %s %s\n",tmp->num,tmp->titre,tmp->auteur);
            tmp = tmp->suivant;
        }
    }
    fclose(fic);
}