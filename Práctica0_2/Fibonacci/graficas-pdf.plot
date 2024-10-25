# Codificación y terminal.

set encoding locale
set terminal pdf size 16cm,10cm

# Título de cada eje.

set xlabel "n"
set ylabel "t(n) (tiempo en segundos)"

# Estilo de presentación (puntos interpolados linealmente).

set style data linespoints
set linetype 1 pointtype 5 pointsize 0.5 linewidth 2 linecolor rgb "blue" 
set linetype 2 pointtype 7 pointsize 0.5 linewidth 2 linecolor rgb "red" 

# Creación de los ficheros PDF.

set output "prueba-1.pdf"
plot "prueba-1.tmp" title "Fibonacci recursivo trivial"

set output "prueba-2.pdf"
plot "prueba-2.tmp" title "Fibonacci dinámico"

set output "pruebas-1-y-2.pdf"
plot "prueba-1.tmp" title "Fibonacci recursivo trivial", \
     "prueba-2.tmp" title "Fibonacci dinámico"
