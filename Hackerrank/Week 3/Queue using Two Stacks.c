#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int val) {
    s->data[++s->top] = val;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

int peek(Stack *s) {
    return s->data[s->top];
}

Stack s1, s2;

void enqueue(int x) {
    push(&s1, x);
}

void shiftStacks() {
    if (isEmpty(&s2)) {
        while (!isEmpty(&s1)) {
            push(&s2, pop(&s1));
        }
    }
}

void dequeue() {
    shiftStacks();
    pop(&s2);
}

void printFront() {
    shiftStacks();
    printf("%d\n", peek(&s2));
}

int main() {
    init(&s1);
    init(&s2);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        } else if (type == 2) {
            dequeue();
        } else if (type == 3) {
            printFront();
        }
    }

    return 0;
}
