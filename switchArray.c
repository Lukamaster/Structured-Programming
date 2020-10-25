#include <stdio.h>

int max(int array[], int l) {
    
    static int b = 0;
	static int count = 0;
    
    if(b >= l) {
    	return count;
    }
    
    if(array[b] == array[l]) {
    	b++;
        l--;
        return max(array, l);
    }
    else if(array[b] > array[l]) {
    	array[l] = array[b];
        b++;
        l--;
        return max(array, l);
    }
    else {
    	array[b] = array[l];
        count++;
        b++;
        l--;
        return max(array, l);
    }
}

int main() {

    int a;
    scanf("%d", &a);
    int array[a];
    
    for(int i = 0; i < a; i++) {
    	scanf("%d", &array[i]);
    }
    
    printf("%d\n", max(array, a-1));
    
    for(int i = 0; i < a; i++) {
    	printf("%d ", array[i]);
    }
    return 0;
}