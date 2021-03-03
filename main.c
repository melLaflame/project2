#include <stdlib.h>
#include <stdio.h>
#include "biblioLC.h"
#include "entreeSortieLC.h"

int main(int argc, char** argv){
    Livre *L1 = creer_livre(10,"HEY","Melvin");

    afficher_Livre(L1);
    liberer_livre(L1);
    printf("\n");
    
    Biblio* new_biblio = charger_n_entrees(argv[1],atoi(argv[2]));

    printf("\n");
    afficher_Bibli(new_biblio);
    printf("\n");

    afficher_Livre(recherche_ouvrage_num(new_biblio,5));
    printf("\n");

    afficher_Livre(recherche_ouvrage_titre(new_biblio,"JYBLD"));
    printf("\n");

    afficher_Bibli(recherche_ouvrage_auteur(new_biblio,"endtomfgdwd"));
    printf("\n");

    supression_ouvrage(new_biblio,0,"WLRBBMQBHCDARZOWK","yhidd");
    afficher_Bibli(new_biblio);

    liberer_biblio(new_biblio);

}