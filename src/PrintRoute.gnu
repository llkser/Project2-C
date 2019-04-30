unset key
set title "myMap" font "Times-Roman,12"
set xlabel "longitude"
set ylabel "latitude"
plot 'MyMap.dat' w lp lt 6 lw 0.5 pt 1 ps 0.5
replot 'MyRoute.dat' w lp lt 7 lw 2 pt 6 ps 1
