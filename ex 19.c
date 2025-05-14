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
                    head++;
                } else if (tape[head] == '_') {
                    state = 1;
                }
                break;
            case 1:
                if (tape[head] == '_') {
                    tape[head] = 'a';
                    head--;
                    state = 2;
                }
                break;
            case 2:
                if (tape[head] == '_') {
                    return true;
                }
                break;
            default:
                return false;
        }
    }
}
int main() {
    char input[100];
    printf("Enter two strings: ");
    scanf("%s", input);
    if (simulateTM(input)) {
        printf("The strings are added.\n");
    } else {
        printf("The strings cannot be added.\n");
    }
    return 0;
}
