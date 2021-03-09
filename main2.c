#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "biblioH.h"
#include "entreeSortieH.h"
#define M 30


void menu(){
    printf("Choissisez un entier entre 0 et 8:\n 0:Sortir du programme\n 1:Afficher la bibliotheque\n 2:Inserer un ouvrage \n 3:Recherche ouvrage auteur\n 4:Recherche ouvrage titre\n 5:Recherche ouvrage num\n 6:Suppresion ouvrage\n 7:Fusion de biblio\n 8:Enregistrer la biblio\n 9:Exemplaires\n\n");
}

int main(int argc, char** argv){
    if(argc != 3){
        printf("nombre d'elements saisis insuffisant('il en faut 2')");
        return 0;
    }

    BiblioH* new_biblio = charger_n_entreesH(argv[1],atoi(argv[2]),M);

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
            afficher_BibliH(new_biblio);
            printf("\n\n");
            break;
        case 2:
            printf("Ecrire le numero , le titre et l'auteur de l'ouvrage.\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%d %s %s",&num,titre,auteur) == 3){
                inserer(new_biblio,num,titre,auteur);
                printf("Ajout effectue...\n");
            }
            else{
                printf("Erreur_format.\n");
            }
            printf("\n\n");
            break;

        case 3:
            printf("Ecrire l'auteur de l'ouvrage:\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%s",auteur) == 1){
                BiblioH* bibli_auteur = recherche_ouvrage_auteurH(new_biblio,auteur);
                if(bibli_auteur -> nE!=0){
                    printf("Affichage:\n\n");
                    afficher_BibliH(bibli_auteur);
                    printf("Recherche effectuee!\n");
                }
                else{
                    printf("Aucun ouvrage trouve de cet auteur...\n");
                }
            }
            printf("\n\n");
            break;
        case 4:
            printf("Ecrire le titre de l'ouvrage:\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%s",titre) == 1){
                LivreH* livre_trouve = recherche_ouvrage_titreH(new_biblio,titre);
                if(livre_trouve!=NULL){
                    afficher_LivreH(livre_trouve);
                }
                else{
                    printf("Livre non trouvee...");
                    break;
                }
                printf("\n");
                printf("Recherche effectuee!\n");
            }
            printf("\n\n");
            break;
        case 5:
            printf("Ecrire le numero de l'ouvrage:\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%s",&num) == 1){
                LivreH* livre_num= recherche_ouvrage_numH(new_biblio,num);
                if(livre_num!=NULL){
                    afficher_LivreH(livre_num);
                    printf("Recherche effectuee!\n");
                }
                else{
                    printf("Numero d'ouvrage non trouve...");
                }
            }
            printf("\n\n");
            break;
        case 6:
            printf("Ecrire le numero , le titre et l'auteur de l'ouvrage:\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%d %s %s",&num,titre,auteur) == 3){
                supression_ouvrageH(new_biblio,num,titre,auteur);
                printf("Supression effectue!\n");
            }
            else{
                printf("Erreur_format.\n");
            }
            printf("\n\n");
            break;
        case 8:
            printf("Ecrire le nom du fichier ou sauvegarder la bibliotheque:\n");
            fgets(buf,256,stdin);
            if(sscanf(buf,"%s",nomfic) == 1){
                enregistrer_biblioH(new_biblio,nomfic);
            }
            else{
                printf("Erreur de format...\n");
            }
            printf("\n\n");
            break;

        case 9:
            //afficher_Bibli(exemplaire(new_biblio)); 
            printf("\n\n");
            break; 
        }
    }   while(rep!=0);
    printf("Merci et au revoir");
    liberer_biblioH(new_biblio);
    return 0;
    
}
