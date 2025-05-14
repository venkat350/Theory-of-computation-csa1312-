#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char stack[MAX];
    int top;
} Stack;

void push(Stack* s, char c) {
    s->stack[++(s->top)] = c;
}

char pop(Stack* s) {
    if (s->top == -1) return '\0';  // Stack is empty
    return s->stack[(s->top)--];
}

bool simulatePDA(const char* str) {
    Stack stack;
    stack.top = -1;
    push(&stack, 'Z');  // Push initial stack symbol

    int len = strlen(str);
    int state = 0;

    for (int i = 0; i < len; i++) {
        if (state == 0) {
            if (str[i] == 'a') {
                push(&stack, 'A');
                state = 1;
            } else {
                return false;  // Invalid transition
            }
        } else if (state == 1) {
            if (str[i] == 'a') {
                push(&stack, 'A');
            } else if (str[i] == 'b') {
                pop(&stack);
                state = 2;
            } else {
                return false;  // Invalid transition
            }
        } else if (state == 2) {
            if (str[i] == 'b') {
                pop(&stack);
                state = 3;
            } else {
                return false;  // Invalid transition
            }
        } else if (state == 3) {
            if (str[i] == 'b') {
                pop(&stack);
                state = 4;
            } else {
                return false;  // Invalid transition
            }
        }
    }

    return (stack.top == 0 && stack.stack[stack.top] == 'Z');
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (simulatePDA(input)) {
        printf("The string is accepted by the PDA.\n");
    } else {
        printf("The string is rejected by the PDA.\n");
    }

    return 0;
}
