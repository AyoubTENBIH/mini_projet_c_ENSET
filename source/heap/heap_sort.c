/*
 * Heap Sort
 * Principe : construire un tas max, puis extraire le maximum repetement.
 * Complexite : toujours O(n log n), memoire O(1)
 */
#include "heap_sort.h"

static void echanger(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void tasifier(int arr[], int n, int i)
{
    int plus_grand = i;
    int gauche = 2 * i + 1;
    int droite = 2 * i + 2;

    if (gauche < n && arr[gauche] > arr[plus_grand])
        plus_grand = gauche;
    if (droite < n && arr[droite] > arr[plus_grand])
        plus_grand = droite;

    if (plus_grand != i) {
        echanger(&arr[i], &arr[plus_grand]);
        tasifier(arr, n, plus_grand);
    }
}

void heapSort(int arr[], int n)
{
    int i;
    if (n <= 1)
        return;

    for (i = n / 2 - 1; i >= 0; i--)
        tasifier(arr, n, i);

    for (i = n - 1; i > 0; i--) {
        echanger(&arr[0], &arr[i]);
        tasifier(arr, i, 0);
    }
}
