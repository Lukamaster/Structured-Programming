#include <stdio.h>
#define MAX 100

int main() {

    int a, b, i, j, count, m = 0;
    scanf("%d %d", &a, &b);
    
    int matrixA[MAX][MAX] = {};		// Matrix
    int arrayB[MAX] = {};			// Array with output results

    for(i = 0; i < a; i++) {		// Fill up the Matrix
        for(j = 0; j < b; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    for(i = 0; i < a; i++) {		// Goes Through Rows
        for(j = 0; j < b; j++) {	// Goes Through Columns
            count = 0;
            for(int k = 0; k < j; k++) {	// Compares j with all elements before itself
                if(matrixA[i][j] == matrixA[i][k]) {
                    count++;
                }
            }
            for(int l = j+1; l < b; l++) {	// Compares j with all elements after itself until the end
            	if(matrixA[i][j] == matrixA[i][l]) {
                    count++;
                }
            }

            if(count == 0) {				// If a number is not repeated, it is added to the arrayB
                arrayB[m] = matrixA[i][j];
                m++;
                
            }
        } 
    }
    
    if(arrayB[0] == 0) {	// Checks if the results array is empty
    	printf("N");
    }
    else {
    	for(i = 0; i < m; i++) {		// Prints the array with results
            printf("%d ", arrayB[i]);
        }
    }
        return 0;
}