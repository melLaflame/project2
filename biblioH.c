#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "biblioH.h"

int fonctionClef(char* auteur){
    char *i = auteur;
    int s_ascii = 0;
    int k;
    for(k=0;k<strlen(auteur);k++){
        int c = *(i+k);
        //printf("%d : %c\n",c,*(i+k));
        s_ascii = s_ascii + c;
    }
    return s_ascii;
}

LivreH* creer_livreH(int num,char* titre,char* auteur){
    LivreH* new_livreH = (LivreH*)malloc(sizeof(LivreH));
    new_livreH->clef = fonctionClef(auteur);
    new_livreH->num = num;
    new_livreH->titre = strdup(titre);
    new_livreH->auteur = strdup(auteur);
    new_livreH->suivant = NULL;
    return new_livreH;
}

void liberer_livreH(LivreH* l){
    free(l->titre);
    free(l->auteur);
    free(l);
}

BiblioH* creer_biblioH(int m){
    int i;
    BiblioH* new_biblio = (BiblioH*)malloc(sizeof(BiblioH));
    new_biblio->nE = 0;
    new_biblio->m = m;
    new_biblio->T = (LivreH**)malloc(sizeof(LivreH*)*m);
    for(i=0;i<m;i++){
        (new_biblio->T)[i] = NULL;
    }
    return new_biblio;
}

void liberer_biblioH(BiblioH* b){
    free(b->T);
    free(b);
}

int fonctionHachage(int cle, int m){
    double A= (sqrt(5)-1)/2.00;
    int h = (int)(m*  (cle*A -(int)(cle*A)) );
    if(h>m){
        printf("ERROR sur h");
        return 0;
    }
    return h;
}

void inserer(BiblioH* b,int num,char* titre,char* auteur){
    LivreH* new_livre = creer_livreH(num,titre,auteur);
    int cle = fonctionClef(auteur);
    int h = fonctionHachage(cle,b->m);
    LivreH* emp = (b->T)[h];
    new_livre->suivant = emp;
    (b->T)[h]= new_livre;
    b->nE = b->nE+1;
}

void afficher_LivreH(LivreH* livre){
    printf("%d %s %s",livre->num,livre->titre,livre->auteur);
}

void afficher_BibliH(BiblioH* b){
    int i;
    LivreH* tmp;
    for(i=0;i<b->m;i++){
        tmp = (b->T)[i];
        while(tmp!=NULL){
            afficher_LivreH(tmp);
            printf("\n");
            tmp = tmp->suivant;
        }
    }
}

LivreH* recherche_ouvrage_numH(BiblioH* b,int num){
    int i;
    for(i=0;i<=b->m;i++){
        LivreH* tmp = (b->T)[i];
        while(tmp != NULL && tmp->num!=num){
            tmp = tmp->suivant;
        }
        return tmp;
    }
}

LivreH* recherche_ouvrage_titreH(BiblioH* b,char* titre){
    int i;
    for(i=0;i<=b->m;i++){
        LivreH* tmp = (b->T)[i];
        while(tmp != NULL && strcmp(tmp->titre,titre)!=0){
            tmp = tmp->suivant;
        }
        return tmp;
    }
}

BiblioH* recherche_ouvrage_auteurH(BiblioH* b,char* auteur){
    BiblioH* new_biblio = creer_biblioH(b->m);
    int cle = fonctionClef(auteur);
    int h = fonctionHachage(cle,b->m);
    LivreH* emp = (b->T)[h];
    while(emp != NULL){
        if(strcmp(emp->auteur,auteur)==0){
            inserer(new_biblio,emp->num,emp->titre,emp->auteur);
        }
        emp = emp -> suivant;
    }
    return new_biblio;
}

void supression_ouvrageH(BiblioH* bibli, int num, char* titre, char* auteur){
    int cle = fonctionClef(auteur);
    int h = fonctionHachage(cle,bibli->m);
    LivreH* emp = (bibli->T)[h];

    //printf("\n%d: %d ; %s:%s ; %s:%s\n",bib->num,num,bib->auteur,auteur,bib->titre,titre);
    if(emp->num == num && strcmp(emp->auteur,auteur)==0 && strcmp(emp->titre,titre)==0){//il s'agit du premiere élément de la liste
        (bibli->T)[h] = emp->suivant;  
        liberer_livreH(emp);
    }

    else{
        while((emp->suivant)->suivant!= NULL){
            if( (emp->suivant)->num == num && strcmp((emp-> suivant)->auteur,auteur)==0 && strcmp((emp->suivant)->titre,titre)==0){
                LivreH* tmp2 = emp->suivant;
                emp->suivant= emp->suivant->suivant;
                liberer_livreH(tmp2);
                break;
            }
            emp = emp -> suivant;
        }

        //printf("\n%d %d: %d ; %s:%s ; %s:%s\n",(bib->suiv)->suiv == NULL,(bib->suiv)->num,num,(bib->suiv)->auteur,auteur,(bib->suiv)->titre,titre);
        if((emp-> suivant)->suivant == NULL && (emp-> suivant)->num == num && strcmp((emp-> suivant)->auteur,auteur)==0 && strcmp((emp->suivant)->titre,titre)==0){
            liberer_livreH(emp->suivant);
            emp->suivant = NULL;
        }
    }  
}

/**Biblio* fusion_bibliotheque(Biblio* biblio1, Biblio* biblio2){
    Livre* bib1 = biblio1->L;
    Livre* bib2 = biblio2->L;
    while(bib1->suiv != NULL){
        bib1 = bib1 -> suiv;
    }
    bib1 -> suiv = bib2;

    return biblio1;
}

    
Biblio* exemplaire(Biblio* biblio){
    Biblio * bib = creer_biblio();
    Livre* L1 = biblio -> L;
    Livre* L2 = biblio -> L;
    int i = 0;
    while(L1->suiv!=NULL){
        while(L2->suiv!=NULL){
            if(strcmp(L1->auteur,L2->auteur)==0 && strcmp(L1->titre,L2->titre)==0){
                if(i == 0){
                    inserer_en_tete(bib,L1->num,L1->auteur,L1->titre);
                    i=1;
                }
                inserer_en_tete(bib,L2->num,L2->auteur,L2->titre);
                L2=L2->suiv;
            }
            L2=L2->suiv;
        }
        i=0;
        L1=L1->suiv;
    }
    return bib;
}**/

