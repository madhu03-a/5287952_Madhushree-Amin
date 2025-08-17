#include <stdio.h>

int birthday(int squares[], int n, int d, int m) {
    int count = 0;
    
    for (int start = 0; start <= n - m; start++) {
        int sum = 0;
        
        
        for (int j = 0; j < m; j++) {
            sum += squares[start + j];
        }
        
        if (sum == d) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int n;
    scanf("%d", &n); 

    int chocolate[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &chocolate[i]);
    }

    int day, month;
    scanf("%d %d", &day, &month);

    int result = birthday(chocolate, n, day, month);
    printf("%d\n", result);

    return 0;
}
