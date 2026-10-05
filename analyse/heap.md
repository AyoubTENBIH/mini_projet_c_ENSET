# Heap Sort

## Principe
Construction d’un **tas max**, puis extractions successives du maximum (tri en place).

## Complexité

| Cas | Temps | Mémoire |
|-----|-------|---------|
| Tous | \(O(n\log n)\) | \(O(1)\) |

## Résultats observés
- Peu sensible au type de tableau.
- ≈ **15.4 ms** à n = 100 000 (`random`).
- Proche de Quick ; souvent un peu plus rapide que Merge sur `random`.

![Heap](../visualisation/graphes/par_algo/heap.png)

## Théorie / expérience
Bonne validation de \(O(n\log n)\) avec mémoire constante.
