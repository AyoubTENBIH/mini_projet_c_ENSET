/*
 * Bubble Sort (tri a bulles)
 * Principe : comparer les voisins et echanger s'ils sont mal ordonnes.
 *            Les grands elements "remontent" vers la fin.
 * Optimisation : arret si un passage ne fait aucun echange.
 * Complexite : meilleur O(n), moyen/pire O(n^2), memoire O(1)
 *
 * Adapté du livrable Marouane (projet_tri) au format commun int arr[], int n.
 */
#include "bubble_sort.h"

void bubbleSort(int arr[], int n)
{
    int i, j, echange, tmp;

    for (i = 0; i < n - 1; i++) {
        echange = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                echange = 1;
            }
        }
        if (echange == 0)
            break;
    }
}
