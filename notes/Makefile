all: notes gauss_jordan gauss_backsub2
  
notes: notes
	latex vectors.tex
	pdflatex vectors.tex

gauss_jordan: gauss_jordan.c
	gcc -Wall -ggdb3 gauss_jordan.c -o gauss_jordan

gauss_backsub2: gauss_backsub2.c
	gcc -Wall -ggdb3 gauss_backsub2.c -o gauss_backsub2

clean: vectors.tex
	rm -f gauss_jordan gauss_backsub2 vectors.aux vectors.dvi vectors.log
   
