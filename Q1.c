#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];   // Stack to store characters
int top = -1;      // Top pointer initialized to -1

// Function to push element into stack
void push(char ch) {
    stack[++top] = ch;   // Increment top and insert element
}

// Function to pop element from stack
char pop() {
    return stack[top--]; // Return top element and decrement top
}

int main() {
    char str[100], rev[100];
    int i;

    printf("Enter string: ");
    scanf("%s", str);

    // Push all characters of string into stack
    for(i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }

    // Pop characters to reverse the string
    for(i = 0; i < strlen(str); i++) {
        rev[i] = pop();
    }

    rev[i] = '\0'; // Null terminate the string

    printf("Reversed string: %s", rev);

    return 0;
}