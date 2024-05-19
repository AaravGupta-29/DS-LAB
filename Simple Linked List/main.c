#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insert_at_beginning(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void delete_node(int key) {
    Node *temp = head, *prev;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

int search(int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) return 1;
        current = current->next;
    }
    return 0;
}

void print_list() {
    Node* node = head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    insert_at_beginning(10);
    insert_at_beginning(20);
    print_list(); // Output: 20 10
    delete_node(20);
    print_list(); // Output: 10
    printf("Search result: %d\n", search(10)); // Output: Search result: 1
    return 0;
}
