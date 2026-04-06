#include <stdio.h>

#define MAX 5

int queue[MAX];         // Queue array
int front = -1, rear = -1;

// Function to add document to queue
void enqueue(int x) {
    if(rear == MAX - 1) {
        printf("Queue Full\n");  // Overflow condition
    }
    else {
        if(front == -1)
            front = 0;          // First insertion
        queue[++rear] = x;      // Insert element
    }
}

// Function to print document (remove from queue)
void dequeue() {
    if(front == -1) {
        printf("Queue Empty\n");  // Underflow condition
    }
    else {
        printf("Printed document: %d\n", queue[front]);
        front++;                 // Move front forward
    }
}

// Function to display queue
void display() {
    int i;

    if(front == -1) {
        printf("Queue Empty\n");
    }
    else {
        printf("Pending documents: ");
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, val;

    while(1) {
        printf("\n1.Add 2.Print 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter document number: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;
        }
    }
}