reset
set terminal pngcairo size 1100,700 enhanced font "Segoe UI,12"
set output "graphes/par_algo/selection.png"
set title "selection ? Temps d'execution selon n"
set xlabel "Taille du tableau n"
set ylabel "Temps moyen (ms)"
set grid
set key top left
set logscale x
plot "data/selection_random.dat" using 1:2 title "random" with linespoints lw 2 pt 7, \
     "data/selection_sorted.dat" using 1:2 title "sorted" with linespoints lw 2 pt 5, \
     "data/selection_reverse.dat" using 1:2 title "reverse" with linespoints lw 2 pt 9, \
     "data/selection_nearly_sorted.dat" using 1:2 title "nearly_sorted" with linespoints lw 2 pt 11
unset output
