#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    
    int matrix[n][n];
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            if(i == j) {	// Main Diagonal
                if(matrix[i][j] == 1) {
                	matrix[i][j] = 0;
                	count++;
                }
            }
            
            if(i > j) {		// Below the main diagonal
                if(matrix[i][j] != matrix[j][i]) {
                	matrix[i][j] = matrix[j][i];
                    count++;
                } 
            }
        }
    }
    printf("%d", count);
    return 0;
}