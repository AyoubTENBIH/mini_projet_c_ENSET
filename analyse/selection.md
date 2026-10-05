# Selection Sort

## Principe
À chaque passage, on cherche le **minimum** de la partie non triée, puis on l’échange avec la position courante.  
La partie triée grandit d’un élément à chaque tour.

## Complexité

| Cas | Temps | Mémoire |
|-----|-------|---------|
| Tous les cas | \(O(n^2)\) | \(O(1)\) |

*(Pas d’arrêt anticipé : même coût si le tableau est déjà trié.)*

## Résultats observés
- Temps **similaire** sur `random`, `sorted`, `reverse`, `nearly_sorted`.
- À n = 20 000 : ≈ **370–430 ms** selon le type.
- Peu d’échanges (au plus un par passage), mais beaucoup de comparaisons.

![Selection](../visualisation/graphes/par_algo/selection.png)

## Théorie / expérience
Confirmé : toujours \(O(n^2)\), y compris sur `sorted` (contrairement à Bubble / Insertion).  
n limité à 20 000.
