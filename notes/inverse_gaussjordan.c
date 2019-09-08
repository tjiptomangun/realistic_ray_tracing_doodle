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

void multiply(double *in1, double *in2, double *out, int num_row, int num_col) {
    for (int i = 0; i < num_row; i ++) {
        for (int j = 0; j < num_col; j ++) {
            double tmp = 0.0;
            for (int k = 0; k < num_col; k ++){
                tmp += in1[i*num_col +  k] * in2[k *num_col + j]; 
            }
            out[i * num_col + j] = tmp;
        }
    }
}

int invert(double *input, double *output, int num_row, int num_col) {
	double *temp = (double *) calloc(num_col, sizeof(double));	
	double *outtemp = (double *) calloc(num_col, sizeof(double));	
    double *buff = (double *) calloc(num_col * num_row, sizeof(double));

	int crow, ccol;
	int mincol = num_col;
	int candrow = 0;
	double candval = 0.000f;
	int procrow = 0 ;
	double invert_factor;
    int all_zero ;

    for (int i = 0; i < num_row; i ++){
        for (int j = 0; j < num_col; j++) {
            buff[i * num_col + j] = input[i * num_col + j];
            if (i == j)
                output[i * num_col + j] = 1.0;
            else
                output[i * num_col + j] = 0.0;
                
        }
    }

      

	while (procrow < num_row){
        all_zero = 1;
		mincol = num_col;

		//find next leading non zero column
		for (ccol = 0; ccol < num_col; ccol ++){
			for (crow = procrow; crow < num_row; crow ++) {
				if (buff[crow * num_col +  ccol] != 0.000f && ccol < mincol){
					mincol = ccol;
					candrow = crow;
					candval = buff[crow * num_col + ccol];
                    all_zero = 0;
				} 
			}
		}
        if (!all_zero){ 
			//save row of leading non zero column
			for (ccol = 0 ; ccol < num_col; ccol ++){
				temp[ccol] = buff[candrow * num_col + ccol]/candval;
				outtemp[ccol] = output[candrow * num_col + ccol]/candval;
			}
		
			//swap current processed row with candidate row
			for (ccol = 0; ccol < num_col; ccol ++){
				buff[candrow * num_col + ccol] = buff[procrow * num_col + ccol] ;
				buff[procrow * num_col + ccol] = temp[ccol];

				output[candrow * num_col + ccol] = output[procrow * num_col + ccol] ;
				output[procrow * num_col + ccol] = outtemp[ccol];
			}
		
			//zeroing mincol column of all row below procrow
			for (crow = procrow + 1; crow < num_row; crow ++){
				invert_factor = - (buff[crow * num_col + mincol] / buff [procrow * num_col + mincol]);	
				for (ccol = 0; ccol < num_col; ccol ++){
					temp[ccol] = buff[procrow * num_col  + ccol] * invert_factor;
					buff[crow * num_col + ccol] += temp[ccol];


					outtemp[ccol] = output[procrow * num_col  + ccol] * invert_factor;
					output[crow * num_col + ccol] += outtemp[ccol]; 
				}
			}
        }

		procrow ++;
	}

    memset(temp, 0, num_col * sizeof(double));
    memset(outtemp, 0, num_col * sizeof(double));

    procrow = num_row - 1;

    while(procrow > 0){
	    mincol = num_col; 
        all_zero = 1;
        for (ccol = 0; ccol < num_col; ccol ++){
            if (buff[procrow * num_col + ccol] != 0.000f && ccol < mincol){
                mincol = ccol;
                candval = buff[procrow * num_col + ccol];
                all_zero = 0;
            }
        }
        if (!all_zero) {
            for (crow = procrow - 1; crow >= 0; crow --){
                invert_factor = - buff[crow * num_col + mincol] / candval;
                for (ccol = 0; ccol < num_col; ccol ++){
                    temp[ccol] = buff[procrow * num_col + ccol] * invert_factor;
                    buff[crow * num_col + ccol] += temp[ccol];

                    outtemp[ccol] = output[procrow * num_col + ccol] * invert_factor;
                    output[crow * num_col + ccol] += outtemp[ccol];
                }
            
            }
        } 
        procrow --;
    }
    
    free(buff);
    free(outtemp);
	free(temp);
	return procrow;	
}

int main(int argc, char **argv) {
	double test[4][4] = {
							{2.0, 3.0, 5.0, 6.0}, 
							{7.0, 1.0, 2.0, 1.0}, 
							{1.0, 2.0, 3.0, 1.0}, 
							{4.0, 11.0, 2.0, 7.0}, 
						};
    double inverse[4][4];
    double result[4][4];

    print_matrix((double *)test, 4, 4);


	invert((double *)test, (double *)inverse, 4, 4);	
    print_matrix((double *)inverse, 4, 4);

    multiply((double *)test, (double *)inverse, (double *)result, 4, 4);
    print_matrix((double *)result, 4, 4);
    

/*
	for (i = 0; i < 4; i ++){
		for(j = 0; j < 4; j ++){
			fprintf(stdout, "%0.4lf  ", test[i][j]);
		}
		fprintf(stdout, "\n");
	}
*/
}


