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
                    state = 4;
                }
                break;
            case 1:
                if (tape[head] == 'a') {
                    tape[head] = 'X';
                    head--;
                    state = 0;
                } else if (tape[head] == 'b') {
                    tape[head] = 'Y';
                    head--;
                    state = 0;
                } else if (tape[head] == '_') {
                    state = 4;
                }
                break;
            case 4:
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
    printf("Enter a string: ");
    scanf("%s", input);
    if (simulateTM(input)) {
        printf("The string is accepted by the Turing Machine.\n");
    } else {
        printf("The string is r
