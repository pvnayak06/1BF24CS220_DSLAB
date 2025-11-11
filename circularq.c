#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int queue[MAX];
int rear = -1;
int front = -1;

void insert() {
    int item;

    if (front == rear - 1||front == 0 && rear==MAX-1) {
        printf("Queue Overflow \n");
    } else {
        if (front == -1) {
            front = 0;
        }

        printf("Enter the element to insert in queue: ");
       scanf("%d",&item); 
           

        rear = (rear + 1) % MAX;
        queue[rear] =item;
        printf("Element %d inserted.\n",item);
    }
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow \n");
        return (-1);
    }
    else if(front == rear)
    {
     front = -1;
     rear= -1;

    }
    else
    {
        printf("Deleted Element is: %d\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty \n");
    } else {
        printf("Queue is: \n");
        for (i = front; i != rear;i=(i+1) % MAX){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nLinear Queue Operations\n");
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice \n");
        }
       
    }
     return 0;
}
