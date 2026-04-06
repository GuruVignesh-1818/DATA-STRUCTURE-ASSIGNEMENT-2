#include <stdio.h>
#include <string.h>

char stack[100];   // Stack to store parentheses
int top = -1;

// Push function
void push(char ch) {
    stack[++top] = ch;
}

// Pop function
void pop() {
    top--;   // Simply reduce top
}

int main() {
    char exp[100];
    int i;

    printf("Enter expression: ");
    scanf("%s", exp);

    // Traverse the expression
    for(i = 0; exp[i] != '\0'; i++) {

        // If opening bracket, push into stack
        if(exp[i] == '(')
            push(exp[i]);

        // If closing bracket
        else if(exp[i] == ')') {

            // If stack is empty → unbalanced
            if(top == -1) {
                printf("Not Balanced");
                return 0;
            }

            pop(); // Remove matching '('
        }
    }

    // If stack is empty → balanced
    if(top == -1)
        printf("Balanced Expression");
    else
        printf("Not Balanced");

    return 0;
}