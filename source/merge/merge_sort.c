/*
 * Merge Sort
 * Principe : diviser en deux, trier, fusionner avec buffer temporaire.
 * Complexite : toujours O(n log n), memoire O(n)
 */
#include "merge_sort.h"

#include <stdio.h>
#include <stdlib.h>

static void fusionner(int arr[], int gauche, int milieu, int droite, int *tmp)
{
    int i = gauche;
    int j = milieu + 1;
    int k = gauche;

    while (i <= milieu && j <= droite) {
        if (arr[i] <= arr[j]) {
            tmp[k] = arr[i];
            i = i + 1;
        } else {
            tmp[k] = arr[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i <= milieu) {
        tmp[k] = arr[i];
        i = i + 1;
        k = k + 1;
    }
    while (j <= droite) {
        tmp[k] = arr[j];
        j = j + 1;
        k = k + 1;
    }
    for (i = gauche; i <= droite; i++)
        arr[i] = tmp[i];
}

static void mergeSortRec(int arr[], int gauche, int droite, int *tmp)
{
    int milieu;
    if (gauche >= droite)
        return;
    milieu = gauche + (droite - gauche) / 2;
    mergeSortRec(arr, gauche, milieu, tmp);
    mergeSortRec(arr, milieu + 1, droite, tmp);
    fusionner(arr, gauche, milieu, droite, tmp);
}

void mergeSort(int arr[], int n)
{
    int *tmp;
    if (n <= 1)
        return;
    tmp = (int *)malloc((size_t)n * sizeof(int));
    if (tmp == NULL) {
        fprintf(stderr, "Erreur memoire (mergeSort)\n");
        exit(EXIT_FAILURE);
    }
    mergeSortRec(arr, 0, n - 1, tmp);
    free(tmp);
}
