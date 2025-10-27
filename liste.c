#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include <string.h>

Un_elem *inserer_liste_trie(Un_elem *liste, Un_truc *truc){
    if(liste == NULL){
        Un_elem *l = malloc(sizeof(Un_elem));
        l->truc = truc;
        l->suiv = NULL;
        return l;
    }
    
    if(truc->user_val < liste->truc->user_val){
        Un_elem *l = malloc(sizeof(Un_elem));
        l->truc = truc;
        l->suiv = liste;
        return l;
    }
    
    liste->suiv = inserer_liste_trie(liste->suiv, truc);
    return liste;
}

void ecrire_liste( FILE *flux, Un_elem *liste){
    int a = 0;
    float lat;
    float lon;
    char nom_lecture[20];
    while(!fscanf(flux, "%f;%f;%s\n", &lon, &lat, nom_lecture)){
        char *nom = malloc(sizeof(20));
        strcpy(nom, nom_lecture);
        Une_coord cord = {.lon = lon, .lat = lat};

        Une_station station = {.nom = nom, .tab_con = NULL, .con_pcc = NULL, .nb_con = 0};

        Tdata data;
        data.sta = station;
        

        creer_truc(cord, STA, data, 0);
    }
}