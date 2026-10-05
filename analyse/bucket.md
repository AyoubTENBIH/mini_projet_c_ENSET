# Bucket Sort

## Principe
Répartir dans des **seaux**, trier chaque seau (insertion), puis recombiner.

## Complexité

| Cas | Temps | Mémoire |
|-----|-------|---------|
| Meilleur / moyen | \(O(n + k)\) | \(O(n)\) |
| Pire | \(O(n^2)\) | \(O(n)\) |

## Résultats observés
- Plus rapide sur données bien ordonnées.
- `random` ≈ **268 ms** à n = 100 000 (coût du tri interne des seaux).
- Plus variable que Counting / Merge / Heap.

![Bucket](../visualisation/graphes/par_algo/bucket.png)

## Théorie / expérience
Les mesures confirment la dépendance à la répartition. Le pire cas \(O(n^2)\) reste possible.
