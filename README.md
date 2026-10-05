# Mini-projet — Étude expérimentale des algorithmes de tri

## Compilation (pour le professeur)

### Windows (le plus simple)

| Action | Fichier / commande |
|--------|--------------------|
| **Compiler** | double-clic sur `compiler.bat` |
| **Lancer** (tableau terminal) | double-clic sur `run.bat` |
| **Compiler + sauver CSV** | double-clic sur `run_csv.bat` |

Prérequis : `gcc` (MSYS2 / MinGW). Le script cherche aussi les chemins courants MSYS2.

### Avec Make (Windows MSYS / Linux / macOS)

```bash
make          # compiler
make run      # executer
make csv      # executer + CSV
make clean    # nettoyer
```

### Linux / macOS (sans make)

```bash
sh compiler.sh
./bin/benchmark
./bin/benchmark > visualisation/csv/resultats.csv
```

---

## Structure

```
mini_projet/
├── README.md
├── mini_projet.pdf
├── Makefile                 # make / make run / make csv
├── compiler.bat             # Windows : compiler
├── run.bat                  # Windows : executer
├── run_csv.bat              # Windows : compiler + CSV
├── compiler.sh              # Linux/macOS
├── source/                  # 1 dossier / algorithme (.h + .c)
├── visualisation/
│   ├── csv/
│   ├── graphes/par_algo/ + comparaison/
│   ├── data/
│   └── scripts/
├── analyse/
├── rapport/
│   └── rapport.md           # rapport detaille du projet
└── _archives/               # (ne pas rendre)
```
## Protocole

- Langage C, mesure `clock()`, unité **ms**
- Types : `random`, `sorted`, `reverse`, `nearly_sorted`
- Tailles : 100 … 100000 (insertion / bubble / selection limités à 20000)
- Format CSV : `algorithm,type,n,time`

## Algorithmes

Bubble, Selection, Insertion, Quick, Merge, Heap, Counting, Bucket.
