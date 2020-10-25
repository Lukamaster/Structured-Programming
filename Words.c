#include <stdio.h>
#include <ctype.h>
#include <string.h>

void writeToFile(char * file) {
    FILE *f = fopen(file, "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int main() {
    writeToFile("input.txt");

    // Your code starts here
    FILE *fpointer = fopen("input.txt", "r");
    char line[20];
    char lineCopy[20];
    char ch;
    int flag = 0, diffCount = 0, highestWord = 0;

    while((fgets(line, 20, fpointer)) != NULL) {
        for(int i = 0; i < strlen(line); i++) {
            ch = line[i];
            for(int j = i+1; j < strlen(line); j++) {
                if(tolower(ch) == tolower(line[j])) {
                    flag = 1;
                }
            }

            for(int j = i-1; j >= 0; j--) {
                if(tolower(ch) == tolower(line[j])) {
                    flag = 1;
                }
            }

            if(flag == 0) {
                diffCount++;
            }
            flag = 0;
        }
        if(highestWord <= diffCount) {
            highestWord = diffCount;
            strcpy(lineCopy, line);
        }
        diffCount = 0;
    }
    printf("%s", lineCopy);
    return 0;
}