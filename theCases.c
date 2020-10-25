#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 80

void wtf() {
    FILE *f = fopen("text.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();

    // your code here
    FILE *fpointer = fopen("text.txt", "r");
    char row[MAX];
    int i, lowerCount = 0, upperCount = 0, rowCount = 0, highestRow = 0;
    float ratio = 0, highestratio = 0;

    while((fgets(row, MAX, fpointer)) != NULL) {

        for(i = 0; i < strlen(row); i++) {
            if(isalpha(row[i])) {
                if(islower(row[i])) {
                    lowerCount++;
                } else if(isupper(row[i])) {
                    upperCount++;
                }
            }
        }
        if(highestratio < (float) upperCount / lowerCount) {
            highestRow = rowCount;
            highestratio = (float) upperCount / lowerCount;
        }

        ratio = (float) upperCount / lowerCount;

        printf("%.2f %s", ratio, row);
        lowerCount = 0;
        upperCount = 0;
        rowCount++;
    }
    fclose(fpointer);
    printf("%d", highestRow);
	return 0;
}