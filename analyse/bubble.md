# Bubble Sort

## Principe
On compare les éléments voisins et on les échange s’ils sont mal ordonnés.  
Les grands éléments « remontent » vers la fin.  
Optimisation : arrêt si un passage ne fait aucun échange.

## Complexité

| Cas | Temps | Mémoire |
|-----|-------|---------|
| Meilleur (`sorted`) | \(O(n)\) | \(O(1)\) |
| Moyen | \(O(n^2)\) | \(O(1)\) |
| Pire | \(O(n^2)\) | \(O(1)\) |

## Résultats observés
- Favorable : `sorted` / `nearly_sorted` (quasi instantané grâce au drapeau d’arrêt).
- Défavorable : `random` (≈ **161 ms** à n = 20 000) et `reverse`.
- Sur ce PC, Bubble (`random`) est plus rapide que Selection, mais les deux restent nettement en \(O(n^2)\).

![Bubble](../visualisation/graphes/par_algo/bubble.png)

## Théorie / expérience
Le meilleur cas \(O(n)\) est bien visible sur `sorted`.  
Sur données désordonnées, la croissance est clairement quadratique.  
n limité à 20 000 (comme Insertion / Selection).
