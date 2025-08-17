#include <stdio.h>
#include <string.h>

int main() {
    int totalStrings, totalQueries;
    char list[1000][21];   
    char search[21];       
    int i, k, count;

    scanf("%d", &totalStrings);
    for (i = 0; i < totalStrings; i++) {
        scanf("%s", list[i]);
    }
    scanf("%d", &totalQueries);

    for (i = 0; i < totalQueries; i++) {
        scanf("%s", search);
        count = 0;

        for (k = 0; k < totalStrings; k++) {
            if (strcmp(search, list[k]) == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
