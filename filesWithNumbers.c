#include <stdio.h>
#include <string.h>
#define MAX 100

// do not change
void wtf() {
    FILE *f = fopen("numbers.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int mostSig(int c) {
    while(c > 9) {
    	c /= 10;
    }
	return c;
}



int main()
{
    wtf();
    
    // your code here
    FILE *fpointer = fopen("numbers.txt", "r");
    int n = 1, array[MAX], arrayCopy, largest, k;
    
    if((fpointer=fopen("numbers.txt","r"))==NULL) {
        printf("Unable to open");
        return 1;
    }
    
    while(fscanf(fpointer,"%d",&n)) {
        if(n==0) {
            break;
        }
        else {
            for(int i = 0; i < n; i++) {
                fscanf(fpointer, "%d", &array[i]);
            }
        }
        largest = 0;
        for(int i = 0; i < n; i++) {
            k = mostSig(array[i]);
            if(k > largest) {
            	largest = k;
                arrayCopy = array[i];
            }
        }
        
        printf("%d\n", arrayCopy);
        
    
    }
    fclose(fpointer);
    return 0;
}