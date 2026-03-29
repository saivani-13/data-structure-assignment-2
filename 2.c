#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int main() {
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);

    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(')
            push(expr[i]);
        else if (expr[i] == ')') {
            if (isEmpty()) {
                printf("Not Balanced\n");
                return 0;
            }
            pop();
        }
    }

    if (isEmpty())
        printf("Balanced Expression\n");
    else
        printf("Not Balanced\n");

    return 0;
}