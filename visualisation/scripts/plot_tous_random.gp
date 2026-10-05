reset
set terminal pngcairo size 1300,800 enhanced font "Segoe UI,12"
set output "graphes/comparaison/tous_algos_random.png"
set title "Comparaison globale ? cas random (Temps = f(n))"
set xlabel "Taille du tableau n"
set ylabel "Temps moyen (ms)"
set grid
set key top left
set logscale x
set logscale y
plot "data/all_random.dat" using 1:2 title "insertion" with linespoints lw 2 pt 7, \
     "data/all_random.dat" using 1:3 title "quick" with linespoints lw 2 pt 8, \
     "data/all_random.dat" using 1:4 title "merge" with linespoints lw 2 pt 9, \
     "data/all_random.dat" using 1:5 title "heap" with linespoints lw 2 pt 10, \
     "data/all_random.dat" using 1:6 title "counting" with linespoints lw 2 pt 11, \
     "data/all_random.dat" using 1:7 title "bucket" with linespoints lw 2 pt 12, \
     "data/all_random.dat" using 1:8 title "bubble" with linespoints lw 2 pt 13, \
     "data/all_random.dat" using 1:9 title "selection" with linespoints lw 2 pt 14
unset output
