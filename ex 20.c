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
                    tape[head] = '_';
                    head++;
                    state = 1;
                } else if (tape[head] == '_') {
                    state = 3;
                }
                break;
            case 1:
                if (tape[head] == 'a') {
                    tape[head] = '_';
                    head--;
                    state = 2;
                }
                break;
            case 2:
                if (tape[head] == '_') {
                    return true;
                }
                break;
            case 3:
                if (tape[head] == '_') {
                    return false;
                }
                break;
        }
    }
}
int main() {
    char input[100];
    printf("Enter two strings for subtraction: ");
    scanf("%s", input);
    if (simulateTM(input)) {
        printf("The subtraction is complete.\n");
    } else {
        printf("The strings cannot be subtracted.\n");
    }
    return 0;
}
