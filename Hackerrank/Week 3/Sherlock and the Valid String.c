#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();




char* isValid(char* s) {
    static char yes[] = "YES";
    static char no[] = "NO";

    int freq[26] = {0};

    
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

   
    int counts[26];
    int size = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            counts[size++] = freq[i];
        }
    }


    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (counts[i] > counts[j]) {
                int tmp = counts[i];
                counts[i] = counts[j];
                counts[j] = tmp;
            }
        }
    }

    int minFreq = counts[0];
    int maxFreq = counts[size - 1];

    if (minFreq == maxFreq) {
        return yes;  
    }

    
    if (minFreq == 1 && counts[1] == maxFreq) {
        return yes;
    }

 
    if (maxFreq - minFreq == 1 && counts[size - 2] == minFreq) {
        return yes;
    }

    return no;

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = isValid(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}
