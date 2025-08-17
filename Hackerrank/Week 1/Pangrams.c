#include <stdio.h>
#include <ctype.h>  

int main(void) {
    char s[1005];         
    int seen[26] = {0};    
    int unique = 0;        

   
    if (!fgets(s, sizeof(s), stdin)) {
        return 0;
    }

  
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha((unsigned char)s[i])) {      
            char c = tolower((unsigned char)s[i]);
            int j = c - 'a';                     

            if (j >= 0 && j < 26 && !seen[j]) {
                seen[j] = 1;                     
                unique++;
                if (unique == 26) {               
                    break;
                }
            }
        }
    }

    if (unique == 26) {
        printf("pangram");
    } else {
        printf("not pangram");
    }

    return 0;
}
