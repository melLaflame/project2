#include <stdlib.h>
#include <stdio.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"

void menu(){
    printf("Choissisez un entier entre 0 et 8:\n 0:Sortir du programme\n 1:Afficher la bibliotheque\n 2:Inserer un ouvrage \n 3:Recherche ouvrage auteur\n 4:Recherche ouvrage titre\n 5:Recherche ouvrage num\n 6:Suppresion ouvrage\n 7:Fusion de biblio\n 8:Enregistrer la biblio\n 9:Exemplaires\n\n");
}

//Q1.7
int main(int argc, char** argv){
    if(argc != 3){
        printf("nombre d'élements saisis insuffisant('il en faut 2')");
        return 0;
    }
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
            printf("Ecrire le numero , le titre et l'auteur de l'ouvrage:\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%d %s %s",&num,titre,auteur) == 3){
                inserer_en_tete(new_biblio,num,titre,auteur);
                printf("Ajout effectue!\n");
            }
            else{
                printf("Erreur de format...\n");
            }
            break;

        case 3:
            printf("Ecrire l'auteur de l'ouvrage:\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%s",auteur) == 1){
                afficher_Bibli(recherche_ouvrage_auteur(new_biblio,auteur));
                printf("recherche effectuée.\n");
            }
            break;
        case 4:
            printf("Ecrire le titre de l'ouvrage:\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%s",titre) == 1){
                afficher_Livre(recherche_ouvrage_titre(new_biblio,titre));
                printf("Recherche effectuée:\n");
            }
            break;
        case 5:
            printf("Ecrire le numero de l'ouvrage.\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%s",&num) == 1){
                afficher_Livre(recherche_ouvrage_num(new_biblio,num));
                printf("Recherche effectuée!\n");
            }
            break;
        case 6:
            printf("Ecrire le numero , le titre et l'auteur de l'ouvrage.\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%d %s %s",&num,titre,auteur) == 3){
                supression_ouvrage(new_biblio,num,titre,auteur);
                printf("Supression effectue!\n");
            }
            else{
                printf("Erreur de format.\n");
            }
            break;

        case 8:
            printf("Ecrire le nom du fichier ou sauvegarder la bibliothèque");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%s",nomfic) == 1){
                enregistrer_biblio(new_biblio,nomfic);
            }
            else{
                printf("Erreur de format.\n");
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