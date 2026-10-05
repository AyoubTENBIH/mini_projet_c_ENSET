/*
 * utils.c — Implementation des utilitaires de test et de mesure
 */
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int est_trie(const int arr[], int n)
{
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i])
            return 0;
    }
    return 1;
}

void remplir_random(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] = rand() % (n * 10 + 1);
}

void remplir_sorted(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] = i;
}

void remplir_reverse(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        arr[i] = n - i;
}

void remplir_nearly_sorted(int arr[], int n)
{
    int i, nb, a, tmp;

    remplir_sorted(arr, n);
    nb = n / 100;
    if (nb < 1)
        nb = 1;

    for (i = 0; i < nb; i++) {
        a = rand() % (n > 1 ? n - 1 : 1);
        tmp = arr[a];
        arr[a] = arr[a + 1];
        arr[a + 1] = tmp;
    }
}

static int repetitions(int n)
{
    if (n <= 100) return 100;
    if (n <= 500) return 40;
    if (n <= 1000) return 20;
    if (n <= 5000) return 5;
    if (n <= 10000) return 3;
    return 1;
}

static double clocks_vers_ms(clock_t t0, clock_t t1)
{
    return ((double)(t1 - t0) * 1000.0) / (double)CLOCKS_PER_SEC;
}

double mesurer_ms(fill_fn remplir, sort_fn trier, int n, int *base, int *travail)
{
    int r, k, reps;
    double total, copie_ms, tout_ms, tri_ms;
    clock_t t0, t1;

    reps = repetitions(n);
    total = 0.0;

    for (r = 0; r < NUM_RUNS; r++) {
        remplir(base, n);

        t0 = clock();
        for (k = 0; k < reps; k++)
            memcpy(travail, base, (size_t)n * sizeof(int));
        t1 = clock();
        copie_ms = clocks_vers_ms(t0, t1);

        t0 = clock();
        for (k = 0; k < reps; k++) {
            memcpy(travail, base, (size_t)n * sizeof(int));
            trier(travail, n);
        }
        t1 = clock();
        tout_ms = clocks_vers_ms(t0, t1);

        if (!est_trie(travail, n)) {
            fprintf(stderr, "ERREUR : tableau non trie (n=%d)\n", n);
            exit(EXIT_FAILURE);
        }

        tri_ms = (tout_ms - copie_ms) / (double)reps;
        if (tri_ms < 0.0)
            tri_ms = 0.0;
        total = total + tri_ms;
    }

    return total / (double)NUM_RUNS;
}
