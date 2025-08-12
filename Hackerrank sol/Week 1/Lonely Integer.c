#include <stdio.h>

int findUnique(int num[], int size) {
    int single = 0; 
    int i;
    for (i = 0; i < size; i++) {
        single = single ^ num[i]; 
    }
    return single;
}

int main() {
    int total, i;
    int values[101]; 
    scanf("%d", &total); 

    for (i = 0; i < total; i++) {
        scanf("%d", &values[i]);
    }

    printf("%d\n", findUnique(values, total));

    return 0;
}