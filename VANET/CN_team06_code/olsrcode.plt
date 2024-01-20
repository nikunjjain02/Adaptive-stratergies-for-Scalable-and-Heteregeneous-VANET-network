set terminal pdf
set output "pj1.pdf"
set title "Receive Rate"
set xlabel "Simulation Time (Seconds)"
set ylabel "Receive Rate"

plot "OLSR.csv" using 1:2 with linespoints title "OLSR"
