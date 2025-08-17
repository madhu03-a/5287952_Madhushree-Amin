#include <stdio.h>

int main() {
    int q;
    unsigned int n;
    int i;

    scanf("%d", &q); 

    for (i = 0; i < q; i++) {
        scanf("%u", &n);
        printf("%u\n", ~n & 0xFFFFFFFF); 
    }

    return 0;
}