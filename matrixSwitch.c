#include <stdio.h>
#define max 99

int main() {

    int m, n, i, j;
    scanf("%d %d", &m, &n);

    int matrix[max][max] = {};

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int a, b;
    scanf("%d %d", &a, &b);

    if(matrix[a][b] == 0) {
        matrix[a][b] = 1;

        j = b;

        for(i = a+1; i < m; i++) {
            if(matrix[i][j] == 0) {
                matrix[i][j] = 1;
            } else
                break;
        }

        for(i = a-1; i >= 0; i--) {
            if(matrix[i][j] == 0) {
                matrix[i][j] = 1;
            } else
                break;
        }

        i = a;

        for(j = b+1; j < n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][j] = 1;
            } else
                break;
        }

        for(j = b-1; j >= 0; j--) {
            if(matrix[i][j] == 0) {
                matrix[i][j] = 1;
            } else
                break;
        }

        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }


    } else {
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}