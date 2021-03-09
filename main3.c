#include <stdlib.h>
#include <stdio.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"
#include "biblioH.h"
#include "entreeSortieH.h"
#include <time.h>
#define N 50
#define M 30

int main(int argc, char** argv){
    Biblio* b1 = charger_n_entrees(argv[1],atoi(argv[2]));
    BiblioH* b2 = charger_n_entreesH(argv[1],atoi(argv[2]),M);

    clock_t temps_initial1 ;
    clock_t temps_final1 ;

    clock_t temps_initial2 ;
    clock_t temps_final2 ;

    double temps_cpu1 ;
    double temps_cpu2 ;

    FILE* fic1 = fopen("comparaison_recherche_ouvrage_non_present.txt","w");
    FILE* fic2 = fopen("comparaison_recherche_titre_non_present.txt","w");
    FILE* fic3 = fopen("comparaison_recherche_auteur_non_present.txt","w");

    FILE* fic4 = fopen("comparaison_recherche_ouvrage_present.txt","w");
    FILE* fic5 = fopen("comparaison_recherche_titre_present.txt","w");
    FILE* fic6 = fopen("comparaison_recherche_auteur_present.txt","w");

    //1/ comparaison recherche d'ouvrages par numéro

    int i;
    for(i=0;i<N;i++){
        //livre non present
        temps_initial1 = clock(); 
        recherche_ouvrage_num(b1,100000);
        temps_final1 = clock();
        temps_cpu1 = (( double ) ( temps_final1 - temps_initial1 ) ) / CLOCKS_PER_SEC ;

        temps_initial2 = clock(); 
        recherche_ouvrage_numH(b2,100000);
        temps_final2 = clock();
        temps_cpu2 = (( double ) ( temps_final2 - temps_initial2 ) ) / CLOCKS_PER_SEC ;

        fprintf(fic1,"%d %f %f\n",i,temps_cpu1,temps_cpu2);

        //livre present

        temps_initial1 = clock(); 
        recherche_ouvrage_num(b1,35);
        temps_final1 = clock();
        temps_cpu1 = (( double ) ( temps_final1 - temps_initial1 ) ) / CLOCKS_PER_SEC ;

        temps_initial2 = clock(); 
        recherche_ouvrage_numH(b2,35);
        temps_final2 = clock();
        temps_cpu2 = (( double ) ( temps_final2 - temps_initial2 ) ) / CLOCKS_PER_SEC ;

        fprintf(fic4,"%d %f %f\n",i,temps_cpu1,temps_cpu2);
    }

    //2/ comparaison recherche d'ouvrages par titre

    for(i=0;i<N;i++){
        //livre non present
        temps_initial1 = clock(); 
        recherche_ouvrage_titre(b1,"a");
        temps_final1 = clock();
        temps_cpu1 = (( double ) ( temps_final1 - temps_initial1 ) ) / CLOCKS_PER_SEC ;

        temps_initial2 = clock(); 
        recherche_ouvrage_titreH(b2,"a");
        temps_final2 = clock();
        temps_cpu2 = (( double ) ( temps_final2 - temps_initial2 ) ) / CLOCKS_PER_SEC ;

        fprintf(fic2,"%d %f %f\n",i,temps_cpu1,temps_cpu2);

        //livre present
        temps_initial1 = clock(); 
        recherche_ouvrage_titre(b1,"PLWUIUPFXL");
        temps_final1 = clock();
        temps_cpu1 = (( double ) ( temps_final1 - temps_initial1 ) ) / CLOCKS_PER_SEC ;

        temps_initial2 = clock(); 
        recherche_ouvrage_titreH(b2,"PLWUIUPFXL");
        temps_final2 = clock();
        temps_cpu2 = (( double ) ( temps_final2 - temps_initial2 ) ) / CLOCKS_PER_SEC ;

        fprintf(fic5,"%d %f %f\n",i,temps_cpu1,temps_cpu2);
    }

    //3/ comparaison recherche d'ouvrages par auteur

    for(i=0;i<N;i++){
        //livre non present
        temps_initial1 = clock(); 
        recherche_ouvrage_auteur(b1,"bknhkwppanlt");
        temps_final1 = clock();
        temps_cpu1 = (( double ) ( temps_final1 - temps_initial1 ) ) / CLOCKS_PER_SEC ;

        temps_initial2 = clock(); 
        recherche_ouvrage_auteurH(b2,"bknhkwppanlt");
        temps_final2 = clock();
        temps_cpu2 = (( double ) ( temps_final2 - temps_initial2 ) ) / CLOCKS_PER_SEC ;

        fprintf(fic3,"%d %f %f\n",i,temps_cpu1,temps_cpu2);

        //livre present

        temps_initial1 = clock(); 
        recherche_ouvrage_auteur(b1,"bknhkwppanlt");
        temps_final1 = clock();
        temps_cpu1 = (( double ) ( temps_final1 - temps_initial1 ) ) / CLOCKS_PER_SEC ;

        temps_initial2 = clock(); 
        recherche_ouvrage_auteurH(b2,"bknhkwppanlt");
        temps_final2 = clock();
        temps_cpu2 = (( double ) ( temps_final2 - temps_initial2 ) ) / CLOCKS_PER_SEC ;

        fprintf(fic6,"%d %f %f\n",i,temps_cpu1,temps_cpu2);
    }
}