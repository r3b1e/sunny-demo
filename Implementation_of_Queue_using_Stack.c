#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX];
int rear = -1; 
int front = -1;

int isFull() {
    return front == MAX - 1;
}

int isEmpty() {
    return rear == -1;
}

void insert() {
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    if (isFull()) {
        printf("Queue Overflow, element can't be pushed.\n");
        return;
    }
    if (rear == -1) {
        rear = 0;
        front = 0;
    } else {
        front++;
    }
    queue[front] = val;
    printf("Inserted %d into the queue.\n", val);
}

void delete() {
    if (isEmpty() || rear > front) {
        printf("Queue is empty, insert an element first.\n");
        front = -1;
        rear = -1;
        return;
    }
    printf("Deleted element is: %d\n", queue[rear]);
    rear++;
    if (rear > front) {
        front = -1;
        rear = -1;
    }
}

void display() {
    if (isEmpty() || rear > front) {
        printf("There are no elements.\n");
        return;
    }
    int temp = rear;
    printf("Elements are: ");
    while (temp <= front) {
        printf("%d ", queue[temp]);
        temp++;
    }
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1 - Push an element\n2 - Pop an element\n3 - Display all elements\n4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Enter a valid number.\n");
                break;
        }
    }
    return 0;
}
