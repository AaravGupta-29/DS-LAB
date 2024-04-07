#include <stdio.h>

#define MAX 128
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data) {
	if (rear == MAX - 1)
		printf("Queue is full\n");
	else
		queue[++rear] = data;
}

int dequeue() {
	if (front == rear) {
		printf("Queue is empty\n");
		return -1;
	}
	return queue[++front];
}

int isEmpty() {
	return front == rear;
}

void display() {
	for (int i = front + 1; i <= rear; i++) {
		printf("%d ", queue[i]);
	}
	printf("\n");
}

int main() {
	int data;
	printf("Enter the data to be enqueued: ");
	scanf("%d", &data);
	enqueue(data);
	printf("Enter the data to be enqueued: ");
	scanf("%d", &data);
	enqueue(data);
	printf("Dequeued data: %d\n", dequeue());
	printf("Dequeued data: %d\n", dequeue());
	printf("Data in the queue: ");
	display();
	return 0;
}
