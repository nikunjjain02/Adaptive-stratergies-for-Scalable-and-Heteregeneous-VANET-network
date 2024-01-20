set terminal pdf
set output "RR.pdf"
set title "Receive Rate"
set xlabel "Simulation Time (Seconds)"
set ylabel "Receive Rate"

plot "AODV.csv" using 1:2 with linespoints title "AODV", \
     "OLSR.csv" using 1:2 with lines title "OLSR", \
     "DSDV.csv" using 1:2 with lines title "DSDV", \
     "DSR.csv" using 1:2 with lines title "DSR"
     
     
set terminal pdf
set output "PR.pdf"
set title "Packets Received"
set xlabel "Simulation Time (Seconds)"
set ylabel "Packet Receive"

plot "AODV.csv" using 1:3 with linespoints title "AODV", \
     "OLSR.csv" using 1:3 with lines title "OLSR", \
     "DSDV.csv" using 1:3 with lines title "DSDV", \
     "DSR.csv" using 1:3 with lines title "DSR"
     
     
     
     
set terminal pdf
set output "Macphy Overhead.pdf"
set title "Receive Rate"
set xlabel "Simulation Time (Seconds)"
set ylabel "overhead"

plot "AODV.csv" using 1:22 with linespoints title "AODV", \
     "OLSR.csv" using 1:22 with lines title "OLSR", \
     "DSDV.csv" using 1:22 with lines title "DSDV", \
     "DSR.csv" using 1:22 with lines title "DSR"
          
