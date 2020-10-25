#include <stdio.h>
#define max 100

int main() {
    
    int a, i, j, k, n;
    int matrix[max][max] = {};
    int matrixOut[max][max] = {};
    scanf("%d", &a);
    
    // Scans the matrix from SI
    for(i = 0; i < a; i++) {
        for(j = 0; j < a; j++) {
        	scanf("%d", &matrix[i][j]);
        }
    }
    
    // Creates a new identical matrix
    for(i = 0; i < a; i++) {
        for(j = 0; j < a; j++) {
        	matrixOut[i][j] = matrix[i][j];
        }
    }
    
    // Sums the elements right of the element in the main diagonal
    k = 0;
    for(i = 0; i < a; i++) {
        matrixOut[k][i] = 0;
        for(j = i + 1; j < a; j++) {
            matrixOut[k][i] += matrix[k][j];
    	}
        // Sums the elements in the same column above the element in the main diagonal
        if(k > 0) {
        
            for(n = k - 1; n >= 0; n--) {
            	matrixOut[k][i] += matrix[n][i];
            }
        }
		k++;
	}
    
    // Sums the elements left of the element in the anti-diagonal
    k = 0;
    for(i = a - 1; i >= 0; i--) {
    	matrixOut[k][i] = 0;
        for(j = i - 1; j >= 0; j--) {
        	matrixOut[k][i] += matrix[k][j];
        }
        // Sums the elements in the same column below the element in the anti-diagonal
        if(k < a) {
        
            for(n = k + 1; n < a; n++) {
            	matrixOut[k][i] += matrix[n][i];
            }
        
        }
        k++;
    }
    
    // If the matrix has an odd number of dimentions
    // This will add the sums of the diagonal and anti-diagonal of the middle number
    // This is to avoid overlap with the sum from the diagonal and anti-diagonal
    if(a % 2 != 0) {
        
        int h = a / 2;
    	k = 0;
        matrixOut[h][h] = 0;
        
        for(i = h + 1; i < a; i++) {
        	matrixOut[h][h] += matrix[h][i];
        }
        for(i = h - 1; i >= 0; i--) {
        	matrixOut[h][h] += matrix[h][i];
        }
        for(i = h + 1; i < a; i++) {
        	matrixOut[h][h] += matrix[i][h];
        }
        for(i = h - 1; i >= 0; i--) {
        	matrixOut[h][h] += matrix[i][h];
        }    
    }

    // Prints out the new matrix
    for(i = 0; i < a; i++) {
        for(j = 0; j < a; j++) {
        	printf("%d ", matrixOut[i][j]);
        }
        printf("\n");
    }
}