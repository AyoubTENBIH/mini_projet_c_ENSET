/*
 * benchmark.c — Programme principal du mini-projet
 *
 * Affiche un tableau dynamique sur stderr
 * et ecrit le CSV (algorithm,type,n,time) sur stdout.
 *
 * Algorithmes : insertion, quick, merge, heap, counting, bucket,
 *               bubble, selection
 */

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "counting_sort.h"
#include "bucket_sort.h"
#include "bubble_sort.h"
#include "selection_sort.h"

typedef struct {
    const char *nom;
    sort_fn fonction;
    int n_max;
} algo_t;

int main(void)
{
    algo_t algos[] = {
        {"insertion", insertionSort, 20000},
        {"quick",     quickSort,     MAX_N},
        {"merge",     mergeSort,     MAX_N},
        {"heap",      heapSort,      MAX_N},
        {"counting",  countingSort,  MAX_N},
        {"bucket",    bucketSort,    MAX_N},
        {"bubble",    bubbleSort,    20000},
        {"selection", selectionSort, 20000}
    };
    int nb_algos = (int)(sizeof(algos) / sizeof(algos[0]));

    cas_t cas[] = {
        {"random",        remplir_random},
        {"sorted",        remplir_sorted},
        {"reverse",       remplir_reverse},
        {"nearly_sorted", remplir_nearly_sorted}
    };
    int nb_cas = (int)(sizeof(cas) / sizeof(cas[0]));

    int tailles[] = {100, 500, 1000, 5000, 10000, 20000, 50000, 100000};
    int nb_tailles = (int)(sizeof(tailles) / sizeof(tailles[0]));

    int *base;
    int *travail;
    int a, c, s;

    base = (int *)malloc((size_t)MAX_N * sizeof(int));
    travail = (int *)malloc((size_t)MAX_N * sizeof(int));
    if (base == NULL || travail == NULL) {
        fprintf(stderr, "Erreur allocation buffers\n");
        return EXIT_FAILURE;
    }

    fprintf(stderr, "\n+------------+----------------+----------+--------------+\n");
    fprintf(stderr, "| Algorithme | Type           |        n | Temps (ms)   |\n");
    fprintf(stderr, "+------------+----------------+----------+--------------+\n");

    printf("algorithm,type,n,time\n");

    for (a = 0; a < nb_algos; a++) {
        for (c = 0; c < nb_cas; c++) {
            for (s = 0; s < nb_tailles; s++) {
                int n = tailles[s];
                double ms;

                if (n > algos[a].n_max)
                    continue;

                srand(SEED + a * 1000 + c * 100 + s);
                ms = mesurer_ms(cas[c].remplir, algos[a].fonction, n, base, travail);

                fprintf(stderr, "| %-10s | %-14s | %8d | %12.6f |\n",
                        algos[a].nom, cas[c].nom, n, ms);
                fflush(stderr);

                printf("%s,%s,%d,%.6f\n", algos[a].nom, cas[c].nom, n, ms);
                fflush(stdout);
            }
        }
        fprintf(stderr, "+------------+----------------+----------+--------------+\n");
    }

    fprintf(stderr, "\nBenchmark termine (8 algorithmes).\n");

    free(base);
    free(travail);
    return EXIT_SUCCESS;
}
