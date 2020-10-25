#include <stdio.h>
#define MAX 100

int main() {

    int a, b;
    int i, j;
    scanf("%d %d", &a, &b);

    int matrix[MAX][MAX] = {};
    int matrixB[MAX][MAX] = {};

    for(i = 0; i < a; i++) {
        for(j = 0; j < b; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int m = 0; m < a; m++) {
        for(int n = 0; n < b; n++) {
            int sum = 0;
            if(matrix[m+1][n] > 0) {
                sum += matrix[m+1][n];
            }
            if(matrix[m-1][n] > 0) {
                sum += matrix[m-1][n];
            }
            if(matrix[m][n+1] > 0) {
                sum += matrix[m][n+1];
            }
            if(matrix[m][n-1] > 0) {
                sum += matrix[m][n-1];
            }

            matrixB[m][n] = sum;
        }
    }

    for(i = 0; i < a; i++) {
        for(j = 0; j < b; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }
}