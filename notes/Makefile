all: notes gauss_jordan gauss_backsub2 inverse_gaussjordan annex quaternion line_line_intersection
annex: elements_id_annex.tex  
	latex elements_id_annex.tex
	pdflatex elements_id_annex.tex

elements_id:
	latex elements_id.tex
	pdflatex elements_id.tex

vector:
	latex vectors.tex
	pdflatex vectors.tex

quaternion:
	latex kuliah_tentang_quaternion.tex
	pdflatex kuliah_tentang_quaternion.tex

notes: elements_id vector annex
	


gauss_jordan: gauss_jordan.c
	gcc -Wall -ggdb3 gauss_jordan.c -lm -o gauss_jordan

gauss_backsub2: gauss_backsub2.c
	gcc -Wall -ggdb3 gauss_backsub2.c -o gauss_backsub2

inverse_gaussjordan: inverse_gaussjordan.c
	gcc -Wall -ggdb3 inverse_gaussjordan.c -o inverse_gaussjordan

line_line_intersection: line_line_intersection.c
	gcc -Wall -ggdb3 line_line_intersection.c -o line_line_intersection

clean: vectors.tex
	rm -f gauss_jordan gauss_backsub2 vectors.aux vectors.dvi vectors.log elements_id.aux elements_id.dvi elements_id.log elements_id.pdf vectors.pdf elements_id_annex.pdf kuliah_tentang_quaternion.dvi kuliah_tentang_quaternion.log kuliah_tentang_quaternion.pdf
   
