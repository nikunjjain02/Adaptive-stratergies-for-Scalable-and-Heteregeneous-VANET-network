set terminal pdf
set output "pj3.pdf"
set title "Receive Rate"
set xlabel "Simulation Time (Seconds)"
set ylabel "Receive Rate"

plot "DSDV.csv" using 1:2 with linespoints title "DSDV"
