/*
 * Insertion Sort
 * Principe : inserer chaque element a sa place dans la partie deja triee.
 * Complexite : meilleur O(n), moyen/pire O(n^2), memoire O(1)
 */
#include "insertion_sort.h"

void insertionSort(int arr[], int n)
{
    int i, j, cle;

    for (i = 1; i < n; i++) {
        cle = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > cle) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = cle;
    }
}
