#include <stdio.h>


void sortAscending(int arr[], int size) {
    int x, y, temp;
    for (x = 0; x < size - 1; x++) {
        for (y = x + 1; y < size; y++) {
            if (arr[x] > arr[y]) {
                temp = arr[x];
                arr[x] = arr[y];
                arr[y] = temp;
            }
        }
    }
}


void sortDescending(int arr[], int size) {
    int x, y, temp;
    for (x = 0; x < size - 1; x++) {
        for (y = x + 1; y < size; y++) {
            if (arr[x] < arr[y]) {
                temp = arr[x];
                arr[x] = arr[y];
                arr[y] = temp;
            }
        }
    }
}


const char* checkPermutation(int target, int first[], int second[], int size) {
    int i;
    
    sortAscending(first, size);
    sortDescending(second, size);
    
    for (i = 0; i < size; i++) {
        if (first[i] + second[i] < target) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    int queries;
    scanf("%d", &queries);

    while (queries--) {
        int length, requiredSum, i;
        scanf("%d %d", &length, &requiredSum);

        int arrayOne[length], arrayTwo[length];

        for (i = 0; i < length; i++) {
            scanf("%d", &arrayOne[i]);
        }

        for (i = 0; i < length; i++) {
            scanf("%d", &arrayTwo[i]);
        }

        printf("%s\n", checkPermutation(requiredSum, arrayOne, arrayTwo, length));
    }

    return 0;
}
