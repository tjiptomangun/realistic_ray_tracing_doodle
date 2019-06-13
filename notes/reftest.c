/*
 * reduction to row echelon form
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int reduce(double *input, int num_col, int num_row) {
	double *temp = (double *) calloc(num_col, sizeof(double));	

	int crow, ccol;
	int mincol = num_col;
	int candrow = 0;
	double candval = 0.000f;
	int procrow = 0 ;
	double reduce_factor;

	while (procrow < num_row){

		//find next leading non zero column
		for (ccol = 0; ccol < num_col; ccol ++){
			for (crow = procrow; crow < num_row; crow ++) {
				if (input[crow * num_col +  ccol] != 0.000f && ccol < mincol){
					mincol = ccol;
					candrow = crow;
					candval = input[crow * num_col + ccol];
				} 
			}
		}
	
		//save row of leading non zero column
		for (ccol = 0 ; ccol < num_col; ccol ++){
			temp[ccol] = input[candrow * num_col + ccol]/candval;
		}
	
		//swap current processed row with candidate row
		for (ccol = 0; ccol < num_col; ccol ++){
			input[candrow * num_col + ccol] = input[procrow * num_col + ccol] ;
			input[procrow * num_col + ccol] = temp[ccol];
		}
	
		//zeroing current leading non zero column all row below procrow
		for (crow = procrow + 1; crow < num_row; crow ++){
			reduce_factor = - (input[crow * num_col + mincol] / candval);	
			for (ccol = 0; ccol < num_col; ccol ++){
				temp[ccol] = input[procrow * num_col  + ccol] * reduce_factor;
				input[crow * num_col + ccol] += temp[ccol];
			}
		}

		procrow ++;
		mincol = num_col;
	}

	free(temp);
	return procrow;	
}

int main(int argc, char **argv) {
	int i,j;
	double test[4][4] = {
							{0.0, 0.0, 3.0, 1.0}, 
							{0.0, 1.0, 2.0, 1.0}, 
							{0.0, 1.0, 1.0, 0.0}, 
							{1.0, 2.0, 0.1, 0.0}, 
						};

	reduce((double *)test, 4, 4);	
	for (i = 0; i < 4; i ++){
		for(j = 0; j < 4; j ++){
			fprintf(stdout, "%0.4lf  ", test[i][j]);
		}
		fprintf(stdout, "\n");
	}
}


