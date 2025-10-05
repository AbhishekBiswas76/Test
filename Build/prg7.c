#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Structure for linked list-based stack
struct Stack {
    struct Node* top;
};

// Initialize stack
struct Stack* initStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

// Check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Push element to stack
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack\n", value);
}

// Pop element from stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

// Peek top element
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

// Display stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Free stack memory
void freeStack(struct Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

// Driver program with user interaction
int main() {
    struct Stack* stack = initStack();
    int choice, value;
    while(1){
        printf("\nStack Menu (Linked List-based):\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                value = pop(stack);
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;
            case 3:
                value = peek(stack);
                if (value != -1)
                    printf("Top value: %d\n", value);
                break;
            case 4:
                display(stack);
                break;
            case 5:
                printf("Exiting...\n");
                freeStack(stack);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
