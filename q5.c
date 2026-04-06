#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int x) {

    // Check if queue is full
    if((rear + 1) % MAX == front) {
        printf("Queue Full\n");
    }
    else {
        if(front == -1)
            front = 0;  // First element

        rear = (rear + 1) % MAX; // Circular increment
        queue[rear] = x;         // Insert element
    }
}

// Dequeue operation
void dequeue() {

    if(front == -1) {
        printf("Queue Empty\n");
    }
    else {
        printf("Deleted: %d\n", queue[front]);

        // If only one element
        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX; // Circular increment
    }
}

// Peek operation
void peek() {
    if(front == -1)
        printf("Queue Empty\n");
    else
        printf("Front element: %d\n", queue[front]);
}

// Display elements
void display() {
    int i = front;

    if(front == -1) {
        printf("Queue Empty\n");
    }
    else {
        printf("Queue: ");

        while(1) {
            printf("%d ", queue[i]);

            if(i == rear)
                break;

            i = (i + 1) % MAX; // Move circularly
        }
        printf("\n");
    }
}

int main() {
    int choice, val;

    while(1) {
        printf("\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
        }
    }
}