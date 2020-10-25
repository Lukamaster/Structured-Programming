#include <stdio.h>
#include <string.h>
#include <ctype.h>
// DO NOT CHANGE HERE
void wtf() {
    FILE *f = fopen("datnum.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();
	// your code here
    FILE *fpointer = fopen("datnum.txt", "r");
    int dcounter = 0, lcounter = 0, letter = 0, i;
    char str[100];
    char mrstr[100];
    float ratio = 0;
    
    while((fgets(str, 100, fpointer)) != NULL) {
        for(i = 0; i < strlen(str); i++) {            
            if(isalpha(str[i])) {
            	letter = 1;
                lcounter++;
            }
            else if(isdigit(str[i])) {
            	dcounter++;
            }            
        }
        
        if(ratio <= (float) dcounter / lcounter&&letter == 1) {
        		ratio = (float) dcounter / lcounter;
            	strcpy(mrstr, str);
        }
        
        dcounter = 0;
        lcounter = 0;
        letter = 0;
    }
    printf("%s", mrstr);
    return 0;
}