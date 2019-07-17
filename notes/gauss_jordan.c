/*
 * reduction to row echelon form
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int print_matrix(double* input, int num_row, int num_col) {
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

int reduce(double *input, int num_row, int num_col) {
	double *temp = (double *) calloc(num_col, sizeof(double));	

	int crow, ccol;
	int mincol = num_col;
	int candrow = 0;
	double candval = 0.000f;
	int procrow = 0 ;
	double reduce_factor;
    int all_zero ;

	while (procrow < num_row){
        print_matrix(input, num_row, num_col);
        all_zero = 1;
		mincol = num_col;

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
	}

    memset(temp, 0, num_col * sizeof(double));

    procrow = num_row - 1;

    while(procrow > 0){
	    mincol = num_col; 
        all_zero = 1;
        for (ccol = 0; ccol < num_col; ccol ++){
            if (input[procrow * num_col + ccol] != 0.000f && ccol < mincol){
                mincol = ccol;
                candval = input[procrow * num_col + ccol];
                all_zero = 0;
            }
        }
        if (!all_zero) {
            for (crow = procrow - 1; crow >= 0; crow --){
                reduce_factor = - input[crow * num_col + mincol] / candval;
                for (ccol = 0; ccol < num_col; ccol ++){
                    temp[ccol] = input[procrow * num_col + ccol] * reduce_factor;
                    input[crow * num_col + ccol] += temp[ccol];
                }
            
            }
        }

        print_matrix(input, num_row, num_col);
        
        procrow --;
    }
    

	free(temp);
	return procrow;	
}

int main(int argc, char **argv) {
	double test[4][4] = {
							{0.0, 0.0, 3.0, 1.0}, 
							{0.0, 1.0, 2.0, 1.0}, 
							{0.0, 2.0, 1.0, 1.0}, 
							{1.0, 3.0, 0.0, 4.0}, 
						};

	double test_again[5][6] = {
							{0.0, 0.0,  -2.0, 0.0,  7.0, 12.0}, 
							{0.0, 0.0,   0.0, 0.0,  0.0,  0.0},
							{2.0, 4.0, -10.0, 6.0, 12.0, 28.0}, 
							{2.0, 4.0, -10.0, 6.0, 12.0, 28.0}, 
							{2.0, 4.0,  -5.0, 6.0, -5.0, -1.0} 
						};

	reduce((double *)test, 4, 4);	
    print_matrix((double *)test, 4, 4);

	reduce((double *)test_again, 5, 6);	
    print_matrix((double *)test_again, 5, 6);
/*
	for (i = 0; i < 4; i ++){
		for(j = 0; j < 4; j ++){
			fprintf(stdout, "%0.4lf  ", test[i][j]);
		}
		fprintf(stdout, "\n");
	}
*/
}


