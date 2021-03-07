#include <stdlib.h>
#include <stdio.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"

void menu(){
    printf("Choissisez un entier entre 0 et 7 :\n 0:Sortir du programme\n 1:Afficher la bibliothèque\n 2:Inserer un ouvrage \n 3: recherche ouvrage auteur\n 4:recherche ouvrage titre\n 5:recherche ouvrage num\n 6:suppresion ouvrage\n 7:fusion de biblio\n8: enregistrer la biblio\n 9:exemplaires\n");
}

int main(int argc, char** argv){
    
    Biblio* new_biblio = charger_n_entrees(argv[1],atoi(argv[2]));
    char buf[256];
    int rep;
    int num;
    char titre[256];
    char auteur[256];
    char nomfic[256];

    do{
        menu();
        fgets(buf,256,stdin);
        sscanf(buf,"%d",&rep);
        switch(rep){
        case 1:
            printf("Affichage :\n");
            afficher_Bibli(new_biblio);
            break;
        case 2:
            printf("ecrire le numero , le titre et l'auteur de l'ouvrage.\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%d %s %s",&num,titre,auteur) == 3){
                inserer_en_tete(new_biblio,num,titre,auteur);
                printf("Ajout_fait.\n");
            }
            else{
                printf("Erreur_format.\n");
            }
            break;

        case 3:
            printf("ecrire l'auteur de l'ouvrage.\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%s",auteur) == 1){
                afficher_Bibli(recherche_ouvrage_auteur(new_biblio,auteur));
                printf("recherche effectuée.\n");
            }
        case 4:
            printf("ecrire le titre de l'ouvrage.\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%s",titre) == 1){
                afficher_Livre(recherche_ouvrage_titre(new_biblio,titre));
                printf("recherche effectuée.\n");
            }
        case 5:
            printf("ecrire le numero de l'ouvrage.\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%s",&num) == 1){
                afficher_Livre(recherche_ouvrage_num(new_biblio,num));
                printf("recherche effectuée.\n");
            }
        case 6:
            printf("ecrire le numero , le titre et l'auteur de l'ouvrage.\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%d %s %s",&num,titre,auteur) == 3){
                supression_ouvrage(new_biblio,num,titre,auteur);
                printf("supression_faite.\n");
            }
            else{
                printf("Erreur_format.\n");
            }
            break;
        case 8:
            printf("ecrire le nom du fichier ou sauvegarder la bibliothèque");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%s",nomfic) == 1){
                enregistrer_biblio(new_biblio,nomfic);
            }
            else{
                printf("Erreur_format.\n");
            }
            break;

        case 9:
            afficher_Bibli(exemplaire(new_biblio)); 
            break; 
        }
    }   while(rep!=0);
    printf("Merci et au revoir");
    liberer_biblio(new_biblio);
    return 0;
}
