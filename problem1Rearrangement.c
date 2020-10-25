#include <stdio.h>

void transform(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[i+1]) {
            arr[i] *= 2;
            arr[i + 1] = 0;
        }
    }
    int arr2[n];
    for (int i = 0; i < n; i++) {
        arr2[i] = 0;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr2[index] = arr[i];
            index++;
        }
    }
    for (int i = 0; i < n; i++) {
        arr[i] = arr2[i];
    }
}


int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    transform(arr,n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}