#!/bin/sh
# Compilation Linux / macOS / MSYS
# Usage : ./compiler.sh   ou   sh compiler.sh

set -e
cd "$(dirname "$0")"

mkdir -p bin

CFLAGS="-O2 -Wall -Wextra -std=c11"
INC="-Isource/common -Isource/insertion -Isource/quick -Isource/merge \
     -Isource/heap -Isource/counting -Isource/bucket -Isource/bubble \
     -Isource/selection"

echo "=== Compilation ==="
gcc $CFLAGS $INC \
  source/common/utils.c \
  source/insertion/insertion_sort.c \
  source/quick/quick_sort.c \
  source/merge/merge_sort.c \
  source/heap/heap_sort.c \
  source/counting/counting_sort.c \
  source/bucket/bucket_sort.c \
  source/bubble/bubble_sort.c \
  source/selection/selection_sort.c \
  source/benchmark.c \
  -o bin/benchmark

echo "[OK] bin/benchmark"
echo "Lancer : ./bin/benchmark"
echo "CSV    : ./bin/benchmark > visualisation/csv/resultats.csv"
