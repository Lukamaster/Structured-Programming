#include <stdio.h>
#include <ctype.h>

void wtf() {
    FILE *f = fopen("sifra.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();    
	// your code here
    FILE *fpointer = fopen("sifra.txt", "r");
    char c;
    while((c = fgetc(fpointer)) != EOF) {
        if(isalpha(c)) {
            if(isupper(c)) {
            	if(c+3 > 'Z') {
            		c = 64+(3-('Z' - c));
            	}
                else
                    c+=3;
            }
            else {
                if(c+3 > 'z') {
            		c = 96+(3-('z' - c));
                }
                else
                    c+=3;
            }
        }
        printf("%c", tolower(c));
    }
    fclose(fpointer);
    return 0;
}