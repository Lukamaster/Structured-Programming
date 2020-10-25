#include <stdio.h>
#define max 99
int main() {

    float matrix[max][max] = {};
    float zArray[max] = {};

    int a, i, j, k, t;
    scanf("%d", &a);

    for(i = 0; i < a; i++) {          // Scans the matrix from SI
        for(j = 0; j < a; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }
    
    k = 0;
    
    for(i = 0; i < a; i++) {        // Finds the Z-Diagonal of the matrix
        zArray[k] = matrix[0][i];
        k++;
    }
    for(i = 1, j = (a-2); j > 0, i < (a - 1); j--, i++) {
        zArray[k] = matrix[i][j];
        k++;
    }
    
    for(i = 0; i < a; i++) {
        zArray[k] = matrix[a-1][i];
        k++;
    }
    
    t = k;
    k -= 1;

    for(i = 0; i < a; i++, k--) {       // Adds the Z-Diagonal in reversed order into the original matrix
        matrix[0][i] = zArray[k];
    }
    for(i = 1, j = (a-2); j > 0, i < (a - 1); j--, i++, k--) {
        matrix[i][j] = zArray[k];
    }
    for(i = 0; i < a; i++, k--) {
        matrix[a-1][i] = zArray[k];
    }


    for(i = 0; i < t; i++) {        // Prints the Z-Diagonal Array
        printf("%.2f ", zArray[i]);
    }
    printf("\n");

    for(i = 0; i < a; i++) {        // Prints the reversed Z-Diagonal Matrix
        for(j = 0; j < a; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}