/*
 * Counting Sort
 * Principe : compter les occurrences, puis reconstruire le tableau.
 * Hypothese : entiers >= 0.
 * Complexite : O(n + k), memoire O(k)  (k = valeur max)
 */
#include "counting_sort.h"

#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n)
{
    int i, max_val, pos, val;
    int *compteur;

    if (n <= 0)
        return;

    max_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    compteur = (int *)calloc((size_t)max_val + 1, sizeof(int));
    if (compteur == NULL) {
        fprintf(stderr, "Erreur memoire (countingSort)\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
        compteur[arr[i]] = compteur[arr[i]] + 1;

    pos = 0;
    for (val = 0; val <= max_val; val++) {
        while (compteur[val] > 0) {
            arr[pos] = val;
            pos = pos + 1;
            compteur[val] = compteur[val] - 1;
        }
    }
    free(compteur);
}
