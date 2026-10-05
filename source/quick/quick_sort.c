/*
 * Quick Sort
 * Principe : pivot (milieu), partition, tris recursifs.
 * Complexite : moyen O(n log n), pire O(n^2), memoire O(log n)
 */
#include "quick_sort.h"

static void echanger(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static int partitionner(int arr[], int debut, int fin)
{
    int milieu = debut + (fin - debut) / 2;
    int pivot, i, j;

    echanger(&arr[milieu], &arr[fin]);
    pivot = arr[fin];
    i = debut - 1;

    for (j = debut; j < fin; j++) {
        if (arr[j] <= pivot) {
            i = i + 1;
            echanger(&arr[i], &arr[j]);
        }
    }
    echanger(&arr[i + 1], &arr[fin]);
    return i + 1;
}

static void quickSortRec(int arr[], int debut, int fin)
{
    int p;
    if (debut < fin) {
        p = partitionner(arr, debut, fin);
        quickSortRec(arr, debut, p - 1);
        quickSortRec(arr, p + 1, fin);
    }
}

void quickSort(int arr[], int n)
{
    if (n > 1)
        quickSortRec(arr, 0, n - 1);
}
