#ifndef LISTE_H
#define LISTE_H
#include "truc.h"

typedef struct _un_elem {
    Un_truc *truc; //Une station ou une connexion
    struct _un_elem *suiv;
} Un_elem;

Un_elem *inserer_liste_trie(Un_elem *liste, Un_truc *truc);
void ecrire_liste( FILE *flux, Un_elem *liste);

#endif