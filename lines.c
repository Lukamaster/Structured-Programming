#include <stdio.h>

int main() {

    int a, b, i, j, k;
    int count1 = 0, count2 = 0;
    scanf("%d %d", &a, &b);
    int matrix[a][b];
    
    // Scan the matrix from SI
    for(i = 0; i < a; i++) {
        for(j = 0; j < b; j++) {
        	scanf("%d", &matrix[i][j]);
        }
    }
    
    // Checks the columns
    for(i = 0; i < a; i++) {
        for(j = 0; j < b; j++) {
            if(matrix[i][j] == 1) {
                k = j;
                while(matrix[i][k] == 1&&k < b) {
                    count1++;
                    k++;
                }
                if(count1 >= 3) {
                    count2++;
                    count1 = 0;
                    break;
                }
            }
            count1 = 0;
        }
    }
    
    // Checks the rows
    count1 = 0;
    for(i = 0; i < b; i++) {
        for(j = 0; j < a; j++) {
            if(matrix[j][i] == 1) {
                k = j;
                while(matrix[k][i] == 1 && k < a) {
                    count1++;
                    k++;
                }
                if(count1 >= 3) {
                    count2++;
                    count1 = 0;
                    break;
                }
                
            }
            count1 = 0;
        }
    }
    
    printf("%d", count2);
    return 0; 
}