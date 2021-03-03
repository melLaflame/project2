#ifndef _BIBIO_H
#define _BIBIO_H

typedef struct livre {
    int num;
    char * titre ;
    char * auteur ;
    struct livre * suiv ;
}Livre;

typedef struct { /* Tete fictive */
    Livre * L; /* Premier element */
}Biblio ;

void liberer_livre(Livre* l);
Livre* creer_livre(int num,char* titre,char* auteur);
Biblio* creer_biblio();
void liberer_biblio(Biblio* b);
void inserer_en_tete(Biblio* b,int num,char* titre,char* auteur);
void afficher_Livre(Livre* livre);
void afficher_Bibli(Biblio* bibli);
Livre* recherche_ouvrage_num(Biblio* bibli, int num);
Livre* recherche_ouvrage_titre(Biblio* bibli, char* titre);
Biblio* recherche_ouvrage_auteur(Biblio* bibli, char* auteur);
void supression_ouvrage(Biblio* bibli, int num, char* titre, char* auteur);


#endif