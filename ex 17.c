#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100
char tape[MAX];
int head = 0;
int state = 0;
bool simulateTM(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        tape[i] = str[i];
    }
    tape[len] = '_';
    while (true) {
        switch (state) {
            case 0:
                if (tape[head] == 'a') {
                    tape[head] = 'X';
                    head++;
                    state = 1;
                } else if (tape[head] == 'b') {
                    tape[head] = 'Y';
                    head++;
                    state = 1;
                } else if (tape[head] == '_') {
                    state = 5;
                }
                break;
            case 1:
                if (tape[head] == 'a' || tape[head] == 'b') {
                    head++;
                } else if (tape[head] == 'X' || tape[head] == 'Y') {
                    state = 2;
                }
                break;
            case 2:
                if (tape[head] == 'a') {
                    tape[head] = 'X';
                    head--;
                    state = 3;
                } else if (tape[head] == 'b') {
                    tape[head] = 'Y';
                    head--;
                    state = 3;
                } else if (tape[head] == '_') {
                    state = 5;
                }
                break;
            case 3:
                if (tape[head] == 'X' || tape[head] == 'Y') {
                    head++;
                } else if (tape[head] == '_') {
                    state = 0;
                }
                break;
            case 5:
                return true;
        }
    }
}
int main() {
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);
    if (simulateTM(input)) {
        printf("The string is accepted by the Turing Machine.\n");
    } else {
        printf("The string is rejected by the Turing Machine.\n");
    }
    return 0;
}
