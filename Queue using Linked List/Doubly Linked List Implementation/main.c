#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* last = head;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

int delete(int data) {
    Node* temp = head;
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return 1;
    }
    while (temp != NULL && temp->data != data)
        temp = temp->next;
    if (temp == NULL) return 0;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
    return 1;
}

int search(int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data)
            return 1;
        current = current->next;
    }
    return 0;
}

void display() {
    Node* node = head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    append(1);
    append(2);
    append(3);
    display();
    delete(2);
    display();
    printf("Search for 3: %d\n", search(3));
    return 0;
}
