reset
set term postscript eps enhanced color

set output "tsp11-dp.eps"
set xlabel "x"
set ylabel "y"
set title "TSP 11 cities by Dynamic Programming"
set xrange[10:60]
set yrange[15:70]

plot "output.txt" using 2:3 with linespoints linewidth 2 notitle, "output.txt" using 2:3:(sprintf("(%d)", $1)) with labels point  pt 7 offset char 1,1 notitle
