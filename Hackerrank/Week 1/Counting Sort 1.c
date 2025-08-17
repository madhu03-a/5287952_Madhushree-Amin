#include <stdio.h>

int main() {
    int totalNum;
    scanf("%d", &totalNum); 

    int freq[100] = {0}; 
    int num;

    
    for (int k = 0; k < totalNum; k++) {
        scanf("%d", &num);
        freq[num] += 1;
    }

   
    for (int i = 0; i < 100; i++) {
        printf("%d ", freq[i]);
    }

    printf("\n");
    return 0;
}