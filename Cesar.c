#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
void cesar(char line[], int n, int x){
    if (n < 0){
        return;
    }else {
        if (islower(line[n])){
            if (line[n] + x > 'z'){
                line[n] -= 26;
                line[n] += x;
            }else{
                line[n] += x;
            }
        }
        if (isupper(line[n])){
            if (line[n] + x > 'Z'){
                line[n] -= 26;
                line[n] += x;
            }else {
                line[n] += x;
            }
        }
    }
    cesar(line, n-1, x);
}

int main() {
    int n, x;
    scanf("%d %d\n", &n, &x);
    char line[80];
    
    for(int i = 0; i < n; i++) {
    	fgets(line, 80, stdin);
        cesar(line, strlen(line)-1, x);
        printf("%s", line);
    }
    return 0; 
}