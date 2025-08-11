#include <stdio.h>
#include <string.h>
#define MAX 100

// Stack implementation
char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

// Pop function
char pop() {
    if (top == -1) {
        return '\0'; // Stack Underflow
    } else {
        return stack[top--];
    }
}

// Function to check if brackets are matching
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if parentheses are balanced
int areParenthesesBalanced(char *exp) {
	int i;
    for (int i = 0; i < strlen(exp); i++) {
        char c = exp[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            char open = pop();
            if (!isMatchingPair(open, c)) {
                return 0; // Not balanced
            }
        }
    }

    return top == -1; // If stack is empty, it's balanced
}

int main() {
    char expression[MAX];

    printf("Enter the expression: ");
    scanf("%s", expression);

    if (areParenthesesBalanced(expression)) {
        printf("?? Parentheses are balanced.\n");
    } else {
        printf("? Parentheses are not balanced.\n");
    }

    return 0;
}

