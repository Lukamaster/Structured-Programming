#include <stdio.h>
#include <string.h>
#include <ctype.h>

// DO NOT CHANGE!

void wtf() {
    FILE *f = fopen("input.txt", "w");
    char c;
    while((c = getchar()) != EOF) {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    wtf();

    // YOUR CODE HERE
    FILE *fpointer = fopen("input.txt", "r");
    char line[20];
    int count = 0, flag = 0, i;
    while(fscanf(fpointer, "%s", line) == 1) {
        for(i = 0; i < strlen(line); i++) {
            if(!isxdigit(line[i])) {
                flag = 1;
                break;
            }
        }

        if(!flag) {
            for(i = 0; i < strlen(line); i++) {
                line[i] = toupper(line[i]);
            }
            printf("%s\n", line);
            count++;
        }
        flag = 0;
    }
    fclose(fpointer);
    printf("Total: %d", count);
    
    return 0;
}
