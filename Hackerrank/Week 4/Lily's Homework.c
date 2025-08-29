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


int cmp_asc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int cmp_desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int countSwaps(int n, int* arr, int* target) {
    int* pos = malloc(n * sizeof(int));
    int* temp = malloc(n * sizeof(int));

  
    for (int i = 0; i < n; i++) {
        pos[arr[i]] = i;
        temp[i] = arr[i];
    }

    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (temp[i] != target[i]) {
            swaps++;

            int correctVal = target[i];
            int idx = pos[correctVal];

          
            int t = temp[i];
            temp[i] = temp[idx];
            temp[idx] = t;

          
            pos[temp[idx]] = idx;
            pos[temp[i]] = i;
        }
    }

    free(pos);
    free(temp);
    return swaps;
}

int lilysHomework(int arr_count, int* arr) {
    int* asc = malloc(arr_count * sizeof(int));
    int* desc = malloc(arr_count * sizeof(int));

    memcpy(asc, arr, arr_count * sizeof(int));
    memcpy(desc, arr, arr_count * sizeof(int));

    qsort(asc, arr_count, sizeof(int), cmp_asc);
    qsort(desc, arr_count, sizeof(int), cmp_desc);

    int swapsAsc = countSwaps(arr_count, arr, asc);
    int swapsDesc = countSwaps(arr_count, arr, desc);

    free(asc);
    free(desc);

    return (swapsAsc < swapsDesc) ? swapsAsc : swapsDesc;
}

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);
int parse_int(char*);

int main()
{
    int n = parse_int(ltrim(rtrim(readline())));
    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(*(arr_temp + i));
        *(arr + i) = arr_item;
    }

    int result = lilysHomework(n, arr);
    printf("%d\n", result);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) break;

        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;

        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if (!data) break;
    }

    if (data[data_length - 1] == '\n') data[data_length - 1] = '\0';
    return data;
}

char* ltrim(char* str) {
    if (!str) return '\0';
    while (*str != '\0' && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!str) return '\0';
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;
    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    return value;
}
