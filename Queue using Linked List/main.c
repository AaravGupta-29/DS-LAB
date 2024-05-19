#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct QNode {
    int data;
    struct QNode* next;
};

// Define the queue structure
struct Queue {
    struct QNode* front;
    struct QNode* rear;
};

// Function to create a new queue node
struct QNode* createNode(int x) {
    struct QNode* newNode = (struct QNode*)malloc(sizeof(struct QNode));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue an element
void enQueue(struct Queue* q, int x) {
    struct QNode* temp = createNode(x);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    struct QNode* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
// Function to dequeue an element
void deQueue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct QNode* temp = q->front;
    q->front = q->front->next;
    free(temp);
}

// Function to peek at the front element
int peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

// Driver code
// Driver code
int main() {
    struct Queue* q = createQueue();
    int numElements, element;

    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; ++i) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        enQueue(q, element);
    }
    display(q);
    deQueue(q); // Corrected line
    display(q);

    free(q);

    return 0;
}
