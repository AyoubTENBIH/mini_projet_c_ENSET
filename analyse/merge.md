# Merge Sort

## Principe
Diviser le tableau en deux, trier chaque moitié, puis **fusionner** avec un buffer temporaire.

## Complexité

| Cas | Temps | Mémoire |
|-----|-------|---------|
| Tous | \(O(n\log n)\) | \(O(n)\) |

## Résultats observés
- Comportement régulier.
- `random` plus lent que les cas ordonnés (constante pratique).
- ≈ **19.6 ms** à n = 100 000 (`random`).

![Merge](../visualisation/graphes/par_algo/merge.png)

## Théorie / expérience
Confirmé \(O(n\log n)\). Coût : mémoire auxiliaire \(O(n)\).
