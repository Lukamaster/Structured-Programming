#include <stdio.h>
#include <string.h>
#include <ctype.h>

// DO NOT CHANGE!

void writeToFile(char * file) {
    FILE *f = fopen(file, "w");
    char c;
    while((c = getchar()) != '#') {
        fputc(c, f);
    }
    fclose(f);
}

int isvowel(char c) {
    if(islower(c)) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return 1;
        } else
            return 0;
    } else {
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return 1;
        } else
            return 0;
    }
}

int isPall(char str[]) {
    int length = strlen(str)-1;
    int count1 = 0, count2 = 0;

    for(int i = 0; i < strlen(str)/2; i++) {
        if(isvowel(str[i])) {
            count1++;
            if(isupper(str[i])) {
                str[length-i] = toupper(str[length-i]);
            }
            else if(islower(str[i])){
                str[length-i] = tolower(str[length-i]);
            }

            if(str[i] == str[length-i]) {
                count2++;
            }
        }
    }
    if(count1 == count2) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    char filename[] = "input.txt";

    writeToFile(filename);


    // YOUR CODE HERE
    FILE *fpointer = fopen("input.txt", "r");
    char str[30], strclone[30];
    while(fscanf(fpointer, "%s", str) == 1) {
        strcpy(strclone, str);
        if(isPall(str)) {
            printf("%s\n", strclone);
        }
    }
    fclose(fpointer);
    return 0;
}
