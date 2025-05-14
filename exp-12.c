#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool simulateDFA(const char* str) {
    int state = 0;
    int len = strlen(str);
    
    for (int i = 0; i < len; i++) {
        if (state == 0) {
            if (str[i] == 'a') state = 1;
            else if (str[i] == 'b') state = 3;
            else return false;
        }
        else if (state == 1) {
            if (str[i] == 'c') state = 2;
            else return false;
        }
        else if (state == 2) {
            return false;
        }
        else if (state == 3) {
            return false;
        }
    }
    return (state == 1 || state == 2 || state == 3);
}

int main() {
    char input[100];
    
    printf("Enter a string: ");
    scanf("%s", input);
    
    if (simulateDFA(input)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is rejected by the DFA.\n");
    }
    
    return 0;
}
