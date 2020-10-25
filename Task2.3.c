#include <stdio.h>

int main() {
	int m, n, i, j;
    int sum = 0, smallest = 99999, index;
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
        	scanf("%d", &matrix[i][j]);
        }
    }
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
        	sum += matrix[j][i]; 
        }
        if(sum < smallest) {
        	smallest = sum;
            index = i;
        }
        sum = 0;
    }
    printf("%d", index);
    return 0;
}