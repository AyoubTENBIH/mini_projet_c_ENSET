/*
 * Selection Sort (tri par selection)
 * Principe : a chaque passage, chercher le minimum de la partie non triee
 *            et l'echanger avec la position courante.
 * Complexite : toujours O(n^2), memoire O(1)
 *
 * Adapté du livrable Marouane (projet_tri) au format commun int arr[], int n.
 */
#include "selection_sort.h"

void selectionSort(int arr[], int n)
{
    int i, j, indice_min, tmp;

    for (i = 0; i < n - 1; i++) {
        indice_min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[indice_min])
                indice_min = j;
        }
        if (indice_min != i) {
            tmp = arr[i];
            arr[i] = arr[indice_min];
            arr[indice_min] = tmp;
        }
    }
}
