#include <stdio.h>
#include <stdlib.h>

// Creating a linked list node
struct Node {
    int data;
    struct Node* link;
};

// Creating a stack structure
struct Stack {
    struct Node* top;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

// Function to initialize an empty stack
void initStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->link = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->link;
    free(temp);
    return data;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to return the top element of the stack
// Function to return the top element of the stack
int peek(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}


// Function to display all the elements of the stack
void display(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    struct Node* temp = stack->top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->link;
        if (temp != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

// Main function
int main() {
    // Creating a stack
    struct Stack stack;
    initStack(&stack);

    // Pushing elements onto the stack
    push(&stack, 11);
    push(&stack, 22);
    push(&stack, 33);
    push(&stack, 44);

    // Displaying stack elements
    display(&stack);

    // Printing the top element of the stack
   printf("%d\n", peek(&stack));


    // Deleting top elements of the stack
   pop(&stack);
     pop(&stack);

    // Displaying stack elements after popping
    display(&stack);

    // Printing the top element of the stack after popping

    return 0;
}
