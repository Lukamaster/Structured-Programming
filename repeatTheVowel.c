#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

//ne menuvaj!
void wtf() {
    FILE *f = fopen("sp.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}
void rff() {
    FILE *f = fopen("output.txt", "r");
    char c;
    while((c = fgetc(f)) != EOF) {
        putchar(c);
    }
    fclose(f);
}

int isvowel(char c) {
    if(islower(c)) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return 1;
        }
        else
            return 0;
    }
    else {
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return 1;
        }
        else
            return 0;
    }
}

int main() {
    wtf();   
	// ne menuvaj nagore
    
    // vashiot kod ovde
    FILE *frpointer = fopen("sp.txt", "r"); // Opens the source file
    FILE *fwpointer = fopen("output.txt", "w"); // Opens the output file
    int repeat, i;
    char ch;
    fscanf(frpointer, "%d", &repeat); // Scans the number of times to repeat vowel
    
    while((ch = fgetc(frpointer)) != EOF) {
        if(isvowel(ch)) {
            for(i = 0; i < repeat; i++) {
                fputc(ch, fwpointer);
            }
        }
        else {
        	fputc(ch, fwpointer);
        }
    }
    fclose(frpointer);
    fclose(fwpointer);
    // ne menuvaj nadolu
    rff();
    return 0;
	
}