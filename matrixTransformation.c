#include <stdio.h>
#include <stdlib.h>

int main() {
	int m, n, i, j;
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    int h, sum1 = 0, sum2 = 0, diff;
    
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
        	scanf("%d", &matrix[i][j]);
        }
    }
    
    if(m % 2 == 0) {
    	h = (m/2) - 1;
    } else {
    	h = m/2;
    }
    
    for(j = 0; j < n; j++) {
        for(i = h; i >= 0; i--) {
        	sum1 += matrix[i][j];
        }
        
        if(m % 2 == 0) {
        	for(i = h+1; i < m; i++) 
        		sum2 += matrix[i][j];
        } else {
        	for(i = h; i < m; i++) 
        		sum2 += matrix[i][j];
        }
        diff = sum1 - sum2;
        matrix[h][j] = abs(diff);
        
        if(m % 2 == 0) {
        	matrix[h+1][j] = abs(diff);
        }
        sum1 = 0;
        sum2 = 0;
    }
    
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
        	printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}