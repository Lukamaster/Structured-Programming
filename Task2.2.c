#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);
    int matrixA[n][n];
    int matrixB[n][n];
    int count = 0;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            if(matrixA[i][j] == 0) {

                if(matrixA[i+1][j] == 1&&(i+1) < n) {
                    count++;
                }
                if(matrixA[i][j+1] == 1 && (j+1) < n) {
                    count++;
                }
                if(matrixA[i-1][j] == 1 && (i-1) >= 0) {
                    count++;
                }
                if(matrixA[i][j-1] == 1 && (j-1) >= 0) {
                    count++;
                }
                if(count >= 3) {
                    matrixB[i][j] = 1;
                } else {
                    matrixB[i][j] = 0;
                }

            } else {
                matrixB[i][j] = 1;
            }
            count = 0;
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }
    return 0;
}