# Analyse globale — Benchmark des tris

Mesures régénérées sur ce PC (`clock()`, ms, moyenne 8 runs).  
Détails : fiches `insertion.md`, `quick.md`, … dans ce dossier.

![Comparaison globale](../visualisation/graphes/comparaison/tous_algos_random.png)

## Complexités

| Algorithme | Meilleur | Moyen | Pire | Mémoire |
|------------|----------|-------|------|---------|
| Insertion | \(O(n)\) | \(O(n^2)\) | \(O(n^2)\) | \(O(1)\) |
| Bubble | \(O(n)\) | \(O(n^2)\) | \(O(n^2)\) | \(O(1)\) |
| Selection | \(O(n^2)\) | \(O(n^2)\) | \(O(n^2)\) | \(O(1)\) |
| Quick | \(O(n\log n)\) | \(O(n\log n)\) | \(O(n^2)\) | \(O(\log n)\) |
| Merge | \(O(n\log n)\) | \(O(n\log n)\) | \(O(n\log n)\) | \(O(n)\) |
| Heap | \(O(n\log n)\) | \(O(n\log n)\) | \(O(n\log n)\) | \(O(1)\) |
| Counting | \(O(n+k)\) | \(O(n+k)\) | \(O(n+k)\) | \(O(k)\) |
| Bucket | \(O(n+k)\) | \(O(n+k)\) | \(O(n^2)\) | \(O(n)\) |

## Repères (cas `random`)

| Algo | n = 20 000 (ms) | n = 100 000 (ms) |
|------|----------------:|-----------------:|
| counting | très faible | ≈ 1 |
| quick / heap / merge | ≈ 2–4 | ≈ 13–20 |
| bucket | ≈ 12 | ≈ 200+ |
| insertion | ≈ 70–80 | *(limité)* |
| bubble | ≈ 161 | *(limité)* |
| selection | ≈ 381 | *(limité)* |

*(Insertion / Bubble / Selection : n ≤ 20 000 car \(O(n^2)\).)*

## Conclusions

1. Les tris \(O(n\log n)\) (Quick, Merge, Heap) restent efficaces jusqu’à 100 000.
2. Counting domine sur entiers ≥ 0 avec k raisonnable.
3. Bubble / Selection / Insertion confirment \(O(n^2)\) ; Bubble brille seulement si déjà trié.
4. Selection est uniforme (lent même sur `sorted`).
5. Bucket dépend de la répartition des données.

Voir : `../visualisation/csv/tableaux.md`
