#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *stack_top = NULL;

struct node *queue_front = NULL;
struct node *queue_rear = NULL;

void push(int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = value;
    newnode->next = stack_top;
    stack_top = newnode;
    printf("%d pushed to stack.\n", value);
}

int pop()
{
    if (stack_top == NULL) {
        printf("Stack Underflow: Stack is empty.\n");
        return -1;
    }

    struct node *temp = stack_top;
    int val = temp->data;
    stack_top = stack_top->next;
    free(temp);

    printf("%d popped from stack.\n", val);
    return val;
}


void display_stack()
{
    if (stack_top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct node *current = stack_top;
    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void enqueue(int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (queue_front == NULL) {
        queue_front = queue_rear = newnode;
    } else {
        queue_rear->next = newnode;
        queue_rear = newnode;
    }
    printf("%d enqueued to queue.\n", value);
}

int dequeue()
{
    if (queue_front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }

    struct node *temp = queue_front;
    int value = temp->data;

    queue_front = queue_front->next;
    if (queue_front == NULL)
        queue_rear = NULL;

    free(temp);
    printf("%d dequeued\n", value);
    return value;
}

void display_queue()
{
    if (queue_front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node *current = queue_front;
    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int option, val, del, p;

    
        printf("\nMAIN MENU \n 1. Push\n 2. Pop");
        printf("\n 3. Display the Stack");
        printf("\n 4. Enqueue");
        printf("\n 5. Dequeue");
        printf("\n 6. Display the Queue");
        printf("\n 7. EXIT");
        while(1){
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Enter the number to be inserted into stack: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                del = pop();
                if (del != -1)
                    printf("The number popped is: %d\n", del);
                break;


            case 3:
                printf("Stack elements:\n");
                display_stack();
                break;

            case 4:
                printf("Enter the number to be inserted in the queue: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 5:
                del = dequeue();
                if (del != -1)
                    printf("The number dequeued is: %d\n", del);
                break;

            case 6:
                printf("Queue elements:\n");
                display_queue();
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option\n");
        }

    } 

    return 0;
}
