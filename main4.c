#include <stdlib.h>
#include <stdio.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"
#include "biblioH.h"
#include "entreeSortieH.h"
#include <time.h>
#define M 30
#define N 50

int main(int argc, char** argv){
    BiblioH* b1 = charger_n_entreesH(argv[1],atoi(argv[2]),M);

    clock_t temps_initial1 ;
    clock_t temps_final1 ;
    double temps_cpu1 ;

    FILE* fic1 = fopen("comparaison_recherche_ouvrage_non_present_hachage.txt","w");
    FILE* fic2 = fopen("comparaison_recherche_titre_non_present_hachage.txt","w");
    FILE* fic3 = fopen("comparaison_recherche_auteur_non_present_hachage.txt","w");

    FILE* fic4 = fopen("comparaison_recherche_ouvrage_present_hachage.txt","w");
    FILE* fic5 = fopen("comparaison_recherche_titre_present_hachage.txt","w");
    FILE* fic6 = fopen("comparaison_recherche_auteur_present_hachage.txt","w");
    
    //1/ comparaison recherche d'ouvrages par numéro en fonction de la taille de la table

    int i;
    for(i=0;i<N;i++){
        BiblioH* b1 = charger_n_entreesH(argv[1],atoi(argv[2]),i);

        //livre non present
        temps_initial1 = clock(); 
        recherche_ouvrage_numH(b1,100000);
        temps_final1 = clock();
        temps_cpu1 = (( double ) ( temps_final1 - temps_initial1 ) ) / CLOCKS_PER_SEC ;

        fprintf(fic1,"%d %f\n",i,temps_cpu1);

        //livre present

        temps_initial1 = clock(); 
        recherche_ouvrage_numH(b1,35);
        temps_final1 = clock();
        temps_cpu1 = (( double ) ( temps_final1 - temps_initial1 ) ) / CLOCKS_PER_SEC ;

        fprintf(fic4,"%d %f\n",i,temps_cpu1);
    }

    //2/ comparaison recherche d'ouvrages par titre en fonction de la taille de la table

    for(i=0;i<N;i++){
        //livre non present
        temps_initial1 = clock(); 
        recherche_ouvrage_titreH(b1,"a");
        temps_final1 = clock();
        temps_cpu1 = (( double ) ( temps_final1 - temps_initial1 ) ) / CLOCKS_PER_SEC ;

        fprintf(fic2,"%d %f\n",i,temps_cpu1);

        //livre present
        temps_initial1 = clock(); 
        recherche_ouvrage_titreH(b1,"PLWUIUPFXL");
        temps_final1 = clock();
        temps_cpu1 = (( double ) ( temps_final1 - temps_initial1 ) ) / CLOCKS_PER_SEC ;

        fprintf(fic5,"%d %f\n",i,temps_cpu1);
    }

    //3/ comparaison recherche d'ouvrages par auteur en fonction de la taille de la table

    for(i=0;i<N;i++){
        //livre non present
        temps_initial1 = clock(); 
        recherche_ouvrage_auteurH(b1,"bknhkwppanlt");
        temps_final1 = clock();
        temps_cpu1 = (( double ) ( temps_final1 - temps_initial1 ) ) / CLOCKS_PER_SEC ;

        fprintf(fic3,"%d %f\n",i,temps_cpu1);

        //livre present

        temps_initial1 = clock(); 
        recherche_ouvrage_auteurH(b1,"bknhkwppanlt");
        temps_final1 = clock();
        temps_cpu1 = (( double ) ( temps_final1 - temps_initial1 ) ) / CLOCKS_PER_SEC ;

        fprintf(fic6,"%d %f %f\n",i,temps_cpu1);
    }
}