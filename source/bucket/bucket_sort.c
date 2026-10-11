/* bucket_sort.c */
#include <stdio.h>
#include <stdlib.h>
#include "bucket_sort.h"

#define NB_BUCKETS 10

/* Tri par insertion */
void triInsertion(int tab[], int n)
{
    int i, j, cle;

    for (i = 1; i < n; i++)
    {
        cle = tab[i];
        j = i - 1;

        while (j >= 0 && tab[j] > cle)
        {
            tab[j + 1] = tab[j];
            j = j - 1;
        }

        tab[j + 1] = cle;
    }
}

/* Bucket Sort */
void bucketSort(int tab[], int n)
{
    int i, j;
    int max;
    int numSeau;
    int position;

    int *seaux[NB_BUCKETS];
    int tailleSeaux[NB_BUCKETS];

    if (n <= 0)
        return;

    max = tab[0];
    for (i = 1; i < n; i++)
    {
        if (tab[i] > max)
            max = tab[i];
    }

    for (i = 0; i < NB_BUCKETS; i++)
    {
        seaux[i] = (int *)malloc((size_t)n * sizeof(int));
        if (seaux[i] == NULL)
        {
            fprintf(stderr, "Erreur memoire (bucketSort)\n");
            exit(EXIT_FAILURE);
        }
        tailleSeaux[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        numSeau = (tab[i] * NB_BUCKETS) / (max + 1);

        if (numSeau >= NB_BUCKETS)
            numSeau = NB_BUCKETS - 1;

        seaux[numSeau][tailleSeaux[numSeau]] = tab[i];
        tailleSeaux[numSeau] = tailleSeaux[numSeau] + 1;
    }

    position = 0;

    for (i = 0; i < NB_BUCKETS; i++)
    {
        triInsertion(seaux[i], tailleSeaux[i]);

        for (j = 0; j < tailleSeaux[i]; j++)
        {
            tab[position] = seaux[i][j];
            position = position + 1;
        }

        free(seaux[i]);
    }
}
