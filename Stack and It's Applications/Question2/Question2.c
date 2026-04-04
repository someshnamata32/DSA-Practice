#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    char ch;
    ch = stack[top--];
    return ch;
}

int main() {
    char str[MAX];
    int i = 0, len = 0;

    printf("Enter string: ");
    scanf("%s", str);

    while(str[len] != '\0') {
        len++;
    }

    for(i = 0; i < len; i++) {
        push(str[i]);
    }

    for(i = 0; i < len; i++) {
        str[i] = pop();
    }

    printf("Reversed string: %s", str);

    return 0;
}
