set terminal pdf
set output "pj2.pdf"
set title "Receive Rate"
set xlabel "Simulation Time (Seconds)"
set ylabel "Receive Rate"

plot "AODV.csv" using 1:2 with linespoints title "AODV"
