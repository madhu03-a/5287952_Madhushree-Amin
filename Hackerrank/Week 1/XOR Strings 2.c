#include <stdio.h>
#include <string.h>

void strings_xor(char s[], char t[]) {
    int n = strlen(s);
    char result[n + 1]; 

    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            result[i] = '0';
        } else {
            result[i] = '1';
        }
    }
    result[n] = '\0'; 

    printf("%s\n", result);
}

int main() {
    char s[10005], t[10005];
    scanf("%s", s);
    scanf("%s", t);

    strings_xor(s, t);

    return 0;
}
