set terminal pdf
set output "pj4.pdf"
set title "Receive Rate"
set xlabel "Simulation Time (Seconds)"
set ylabel "Receive Rate"

plot "DSR.csv" using 1:2 with linespoints title "DSR"
