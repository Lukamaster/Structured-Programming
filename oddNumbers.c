#include <stdio.h>
#define MAX 100

int oddCount = 0;

int odd(int a[], int n) {
    if(n < 0) {
    	return oddCount;
    }
    
    if(a[n-1] % 2 == 0) {
    	return odd(a, n-1);    
    } else {
        oddCount++;
        return odd(a, n-1);
    }
}


int main() {
	int n;
    scanf("%d", &n);
    int array[n];
    
    for(int i = 0; i < n; i++) {
    	scanf("%d", &array[i]);
    }
    printf("%d", odd(array, n));
    return 0;
}