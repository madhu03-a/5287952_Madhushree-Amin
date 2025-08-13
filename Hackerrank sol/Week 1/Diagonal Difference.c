#include <stdio.h>

int main() {
    int size;
    scanf("%d", &size); 

    int arr[size][size];
    int leftDiagonalSum = 0, rightDiagonalSum = 0;

    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &arr[i][j]);

            if (i == j) { 
                leftDiagonalSum += arr[i][j]; 
            }
            if (i + j == size - 1) { 
                rightDiagonalSum += arr[i][j]; 
            }
        }
    }

    int difference;
    if (leftDiagonalSum > rightDiagonalSum) {
            difference = leftDiagonalSum - rightDiagonalSum;
        } else {
                difference = rightDiagonalSum - leftDiagonalSum;
        }
        printf("%d\n", difference);
           
         return 0;
}
