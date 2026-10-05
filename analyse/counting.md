# Counting Sort

## Principe
Compter les occurrences de chaque valeur, puis reconstruire le tableau trié.  
**Hypothèse :** entiers ≥ 0.

## Complexité

| Cas | Temps | Mémoire |
|-----|-------|---------|
| Tous | \(O(n + k)\) | \(O(k)\) |

*(k = valeur maximale)*

## Résultats observés
- Le plus rapide du benchmark actuel.
- ≈ **1.0 ms** à n = 100 000 (`random`).
- Peu de différence entre les 4 types.

![Counting](../visualisation/graphes/par_algo/counting.png)

## Théorie / expérience
Temps quasi linéaire si k reste raisonnable. Limite : mémoire si k est très grand.
