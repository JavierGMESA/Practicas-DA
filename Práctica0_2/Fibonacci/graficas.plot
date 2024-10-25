# Título de cada eje.

set xlabel "n"
set ylabel "t(n) (tiempo en segundos)"

# Estilo de presentación (puntos interpolados linealmente).

set style data linespoints
set linetype 1 pointtype 5 pointsize 2 linewidth 4 linecolor rgb "blue" 
set linetype 2 pointtype 7 pointsize 2 linewidth 4 linecolor rgb "red" 

# Representación gráfica.

set terminal qt size 1920,1080 persist

set terminal qt 0 title "Fibonacci recursivo trivial"
plot "prueba-1.tmp" title "Fibonacci recursivo trivial"

set terminal qt 1 title "Fibonacci dinámico"
plot "prueba-2.tmp" title "Fibonacci dinámico"

set terminal qt 2 title "Comparación entre ambas versiones"
plot "prueba-1.tmp" title "Fibonacci recursivo trivial", \
     "prueba-2.tmp" title "Fibonacci dinámico"
