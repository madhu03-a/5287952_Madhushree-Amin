#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000
#define MAX_OPS 100000

typedef struct {
    int type;           
    char *data;         
} Operation;

int main() {
    int Q;
    scanf("%d", &Q);

    char *S = (char *)malloc(MAX_LEN + 5);
    S[0] = '\0';  
    int len = 0;

    Operation stack[MAX_OPS];
    int top = -1;

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
           
            char temp[MAX_LEN + 5];
            scanf("%s", temp);
            int l = strlen(temp);

          
            stack[++top].type = 1;
            stack[top].data = (char *)malloc(20);
            sprintf(stack[top].data, "%d", l);

           
            strcat(S, temp);
            len += l;

        } else if (type == 2) {
           
            int k;
            scanf("%d", &k);

           
            stack[++top].type = 2;
            stack[top].data = (char *)malloc(k + 1);
            strncpy(stack[top].data, S + len - k, k);
            stack[top].data[k] = '\0';

            len -= k;
            S[len] = '\0';

        } else if (type == 3) {
          
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);

        } else if (type == 4) {
            
            Operation last = stack[top--];
            if (last.type == 1) {
              
                int l = atoi(last.data);
                len -= l;
                S[len] = '\0';
            } else if (last.type == 2) {
                
                strcat(S, last.data);
                len += strlen(last.data);
            }
            free(last.data);
        }
    }

    free(S);
    return 0;
}
