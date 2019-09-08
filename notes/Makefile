all: notes gauss_jordan gauss_backsub2 inverse_gaussjordan
  
notes: notes
	latex vectors.tex
	pdflatex vectors.tex

gauss_jordan: gauss_jordan.c
	gcc -Wall -ggdb3 gauss_jordan.c -o gauss_jordan

gauss_backsub2: gauss_backsub2.c
	gcc -Wall -ggdb3 gauss_backsub2.c -o gauss_backsub2

inverse_gaussjordan: inverse_gaussjordan.c
	gcc -Wall -ggdb3 inverse_gaussjordan.c -o inverse_gaussjordan

clean: vectors.tex
	rm -f gauss_jordan gauss_backsub2 vectors.aux vectors.dvi vectors.log
   
