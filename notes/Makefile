all: notes gauss_jordan gauss_backsub
  
notes: notes
	latex vectors.tex
	pdflatex vectors.tex

gauss_jordan: gauss_jordan.c
	gcc -Wall -ggdb3 gauss_jordan.c -o gauss_jordan

gauss_backsub: gauss_backsub.c
	gcc -Wall -ggdb3 gauss_backsub.c -o gauss_backsub

clean: vectors.tex
	rm -f gauss_jordan gauss_backsub vectors.aux vectors.dvi vectors.log
   
