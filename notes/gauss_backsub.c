/*
 * reduction to row echelon form
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int print_matrix(double* input, int num_col, int num_row) {
    int i, j;
    fprintf(stdout, "---------  MATRIX %d x %d ---------\n", num_col, num_row);
    for (i = 0; i < num_row; i ++) {
        for(j = 0; j < num_col; j ++){
            fprintf(stdout, "%0.4f ", input[i * num_col + j]);
        }

        fprintf(stdout, "\n");
    }
    return 0;
}

int reduce(double *input, int num_col, int num_row) {
	double *temp = (double *) calloc(num_col, sizeof(double));	

	int crow, ccol;
	int mincol = num_col;
	int candrow = 0;
	double candval = 0.000f;
	int procrow = 0 ;
	double reduce_factor;
    int all_zero ;

	while (procrow < num_row){
        print_matrix(input, num_col, num_row);
        all_zero = 1;

		//find next leading non zero column
		for (ccol = 0; ccol < num_col; ccol ++){
			for (crow = procrow; crow < num_row; crow ++) {
				if (input[crow * num_col +  ccol] != 0.000f && ccol < mincol){
					mincol = ccol;
					candrow = crow;
					candval = input[crow * num_col + ccol];
                    all_zero = 0;
				} 
			}
		}
        if (!all_zero){ 
			//save row of leading non zero column
			for (ccol = 0 ; ccol < num_col; ccol ++){
				temp[ccol] = input[candrow * num_col + ccol]/candval;
			}
		
			//swap current processed row with candidate row
			for (ccol = 0; ccol < num_col; ccol ++){
				input[candrow * num_col + ccol] = input[procrow * num_col + ccol] ;
				input[procrow * num_col + ccol] = temp[ccol];
			}
		
			//zeroing mincol column of all row below procrow
			for (crow = procrow + 1; crow < num_row; crow ++){
				reduce_factor = - (input[crow * num_col + mincol] / input [procrow * num_col + mincol]);	
				for (ccol = 0; ccol < num_col; ccol ++){
					temp[ccol] = input[procrow * num_col  + ccol] * reduce_factor;
					input[crow * num_col + ccol] += temp[ccol];
				}
			}
        }

		procrow ++;
		mincol = num_col;
	}

    memset(temp, 0, num_col * sizeof(double));

    procrow = num_row - 1;

    while(procrow > 0){
	    mincol = num_col; 
        all_zero = 1;
        for (ccol = 0; ccol < num_col; ccol ++){
            if (input[procrow * num_col + ccol] != 0.000f && ccol < mincol){
                mincol = ccol;
                candval = input[crow * num_col + ccol];
                all_zero = 0;
            }
        }
        if (!all_zero) {
           // should all columns represented as coefficient times function ? 
           // a f(x) g(y) h(z)
           // all functions are all the same 
           // f (rightmost, x1val, x2val, x3val, ..., xnval) = rightmost - (x1val + x2val + x3val ... + xnval)
           // x1val, ...xnval is another function 
        } 
        procrow --;
    } 
	free(temp);
	return procrow;	
}
/**
 * Bagaimana mengubah matrix tersebut menjadi metode eliminasi ?
 * Apa saja asumsi nya?
 * matrix
 * a * f(x, y, z)      b * g(x, y, z)      c * h(x, y, z)    d
 * u * f(x, y, z)      v * g(x, y, z)      w * h(x, y, z)    m
 * p * f(x, y, z)      q * g(x, y, z)      r * h(x, y, z)    s
 *
 * pakai solusi functional c, dimana setiap variable adalah fungsi atau nilai
 * variable untuk kasus di atas adalah f, g dan h.
 * f g dan h adalah penambahan , 
 * f = o + i * g(x, y, z) + j * h (x, y, z)
 * g = p + k * f(x, y, z) + l * h (x, y, z)
 * h = q + m * f(x, y, z) + n * g (x, y, z)
 * 
 * alternative
 * https://www.codewithc.com/c-program-for-gauss-elimination-method/
 **/
double fntree(double rightmost, int size, double (*arrfun[]) (double, int, double(*[])() )   )   {
    int i;
    double result = 0.00;

    for (i = 0; i < size; i ++){
        result += arrfun[i]();
        
    }
}

int main(int argc, char **argv) {
	double test[4][4] = {
							{0.0, 0.0, 3.0, 1.0}, 
							{0.0, 1.0, 2.0, 1.0}, 
							{0.0, 2.0, 1.0, 1.0}, 
							{1.0, 3.0, 0.0, 4.0}, 
						};

	reduce((double *)test, 4, 4);	
    print_matrix((double *)test, 4, 4);
}


