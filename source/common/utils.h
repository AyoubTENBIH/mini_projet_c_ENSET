/*
 * utils.h — Utilitaires communs du benchmark
 * Generation de tableaux, verification, mesure du temps.
 */
#ifndef UTILS_H
#define UTILS_H

#define NUM_RUNS 8
#define MAX_N    100000
#define SEED     42

typedef void (*sort_fn)(int *arr, int n);
typedef void (*fill_fn)(int *arr, int n);

typedef struct {
    const char *nom;
    fill_fn remplir;
} cas_t;

int  est_trie(const int arr[], int n);

void remplir_random(int arr[], int n);
void remplir_sorted(int arr[], int n);
void remplir_reverse(int arr[], int n);
void remplir_nearly_sorted(int arr[], int n);

/* Mesure le tri seul, en millisecondes (moyenne). */
double mesurer_ms(fill_fn remplir, sort_fn trier, int n, int *base, int *travail);

#endif /* UTILS_H */
