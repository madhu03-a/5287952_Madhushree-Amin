#include <stdio.h>
#include <stdlib.h>


int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        qsort(arr, n, sizeof(int), cmpfunc);

   
        int mid = (n - 1) / 2;

        int temp = arr[mid];
        arr[mid] = arr[n - 1];
        arr[n - 1] = temp;

      
        int left = mid + 1, right = n - 2;
        while (left <= right) {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }

        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
    }

    return 0;
}