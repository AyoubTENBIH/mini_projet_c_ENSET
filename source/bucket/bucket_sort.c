/*
 * Bucket Sort
 * Principe : repartir dans des seaux, trier chaque seau (insertion), recombiner.
 * Complexite : moyen O(n + k), pire O(n^2), memoire O(n)
 */
#include "bucket_sort.h"

#include <stdio.h>
#include <stdlib.h>

#define NB_SEAUX 10

static void triInsertionSeau(int tab[], int n)
{
    int i, j, cle;
    for (i = 1; i < n; i++) {
        cle = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > cle) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = cle;
    }
}

void bucketSort(int arr[], int n)
{
    int i, j, max_val, num, pos;
    int *seaux[NB_SEAUX];
    int taille[NB_SEAUX];

    if (n <= 0)
        return;

    max_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
    }

    for (i = 0; i < NB_SEAUX; i++) {
        seaux[i] = (int *)malloc((size_t)n * sizeof(int));
        if (seaux[i] == NULL) {
            fprintf(stderr, "Erreur memoire (bucketSort)\n");
            exit(EXIT_FAILURE);
        }
        taille[i] = 0;
    }

    for (i = 0; i < n; i++) {
        num = (arr[i] * NB_SEAUX) / (max_val + 1);
        if (num >= NB_SEAUX)
            num = NB_SEAUX - 1;
        seaux[num][taille[num]] = arr[i];
        taille[num] = taille[num] + 1;
    }

    pos = 0;
    for (i = 0; i < NB_SEAUX; i++) {
        triInsertionSeau(seaux[i], taille[i]);
        for (j = 0; j < taille[i]; j++) {
            arr[pos] = seaux[i][j];
            pos = pos + 1;
        }
        free(seaux[i]);
    }
}
