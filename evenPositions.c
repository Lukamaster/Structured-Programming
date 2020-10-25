#include <stdio.h>

int count = 0;

int evenPos(int m, int n) {
            
    if(m <= 0) {
    	return count;
    }

    if(((m % 100) / 10) == n) {
    	count++;
        m /= 100;
        return evenPos(m, n);
    }
    else {
    	m /= 100;
        return evenPos(m, n);
    }     
}

int main() {
	
    int a, b, c, aPos, bPos;
    
    while(scanf("%d %d %d", &a, &b, &c) == 3) {
   
        aPos = evenPos(a, c);
        count = 0;
        bPos = evenPos(b, c);
        count = 0;
        
        if(aPos > bPos) {
            printf("%d\n", a);
        }
        else if(bPos > aPos) {
        	printf("%d\n", b);
        }
        else if(aPos == bPos) {
            printf("%d\n", a);            
        }
        else {
            printf("wtf\n");
        }
    }       
    return 0;  
}