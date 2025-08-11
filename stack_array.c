#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf("? Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("? Pushed %d onto the stack\n", value);
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("? Stack Underflow! No elements to pop\n");
    } else {
        printf("? Popped %d from the stack\n", stack[top]);
        top--;
    }
}

// Peek operation
void peek() {
    if (top == -1) {
        printf("?? Stack is empty\n");
    } else {
        printf("??? Top element: %d\n", stack[top]);
    }
}

// Display the stack
void display() {
    if (top == -1) {
        printf("?? Stack is empty\n");
    } else {
        int i; // ? Declare outside the for loop
        printf("?? Stack elements: ");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("?? Exiting program.\n");
                return 0;
            default:
                printf("?? Invalid choice! Try again.\n");
        }
    }

    return 0;
}

