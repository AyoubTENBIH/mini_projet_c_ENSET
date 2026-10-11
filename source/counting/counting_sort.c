/* counting_sort.c */
/* Tri par comptage (Counting Sort) */

#include <stdio.h>
#include <stdlib.h>
#include "counting_sort.h"

void countingSort(int tab[], int n)
{
    int i;
    int max;
    int *compteur;
    int position;
    int valeur;

    if (n <= 0)
        return;

    max = tab[0];
    for (i = 1; i < n; i++)
    {
        if (tab[i] > max)
            max = tab[i];
    }

    compteur = (int *)calloc((size_t)max + 1, sizeof(int));
    if (compteur == NULL)
    {
        fprintf(stderr, "Erreur memoire (countingSort)\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
        compteur[tab[i]] = compteur[tab[i]] + 1;

    position = 0;
    for (valeur = 0; valeur <= max; valeur++)
    {
        while (compteur[valeur] > 0)
        {
            tab[position] = valeur;
            position = position + 1;
            compteur[valeur] = compteur[valeur] - 1;
        }
    }

    free(compteur);
}
