#include <stdio.h>

int pattern(int n) {
    if(n < 1) {
    	return 1;
    }
    else {
    	pattern(n-1);
        printf("%d", n);
    }
}

int triangle(int n) {
    if(n < 0) {
    	return 0;
    }
    else {
    	triangle(n-1);
        printf("\n");
    }
    return pattern(n); 
}

int main() {
    int n;
    scanf("%d", &n);
    triangle(n);
}