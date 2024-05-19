#include <stdio.h>
#include <stdlib.h>

// Define the structure for a priority queue node
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Define the priority queue structure
struct PriorityQueue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new priority queue node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty priority queue
struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->front = pq->rear = NULL;
    return pq;
}

// Function to enqueue an element with priority
void enPriorityQueue(struct PriorityQueue* pq, int data, int priority) {
    struct Node* temp = createNode(data, priority);
    if (pq->front == NULL || priority > pq->front->priority) {
        temp->next = pq->front;
        pq->front = temp;
    } else {
        struct Node* current = pq->front;
        while (current->next != NULL && current->next->priority > priority) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
    if (pq->rear == NULL) {
        pq->rear = temp;
    }
}

// Function to dequeue an element with highest priority
void dePriorityQueue(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }
    struct Node* temp = pq->front;
    pq->front = pq->front->next;
    if (pq->front == NULL) {
        pq->rear = NULL;
    }
    free(temp);
}

// Function to peek at the front element's data
int peek(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority Queue is empty.\n");
        return -1;
    }
    return pq->front->data;
}

// Function to peek at the front element's priority
int peekPriority(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority Queue is empty.\n");
        return -1;
    }
    return pq->front->priority;
}

// Function to display the priority queue elements
void displayPriorityQueue(struct PriorityQueue* pq) {
    if (pq->front == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue elements: ");
    struct Node* temp = pq->front;
    while (temp != NULL) {
        printf("(%d, %d) ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct PriorityQueue* pq = createPriorityQueue();
    int numElements, element, priority;

    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; ++i) {
        printf("Enter element %d and its priority: ", i + 1);
        scanf("%d %d", &element, &priority);
        enPriorityQueue(pq, element, priority);
    }

    displayPriorityQueue(pq);

    printf("Dequeueing the highest priority element.\n");
    dePriorityQueue(pq);

    printf("Peek: %d (Priority: %d)\n", peek(pq), peekPriority(pq));

    displayPriorityQueue(pq);

    return 0;
}
