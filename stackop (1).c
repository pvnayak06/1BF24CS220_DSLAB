#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10
void push(int);
void pop();
void display();
void peek();
int stack[SIZE], top = -1;

void main()
{
    int value,choice;
    while(1){
        printf("\nEnter your choice:\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d",&value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break;
            case 5: exit(0);
            default: printf("\nwrong selection!!! Try again!!!");
        }
    }
}

void push(int value) {
    if(top == SIZE-1)
        printf("\nStack overflow");
    else{
        top++;
        stack[top] = value;
        printf("\nvalue has been inserted");
    }
}

void pop(){
    if(top == -1)
        printf("\nStack underflow");
    else{
        printf("\nDeleted: %d", stack[top]);
        top--;
    }
}

void display(){
    if (top == -1)
         printf("\nStack underflow");
    else{
        int i;
        printf("\nStack elements are: \n");
        for(i=top; i>=0; i--)
            printf("%d\n", stack[i]);
    }
}

void peek()
{
    if(top >= 0)
    {
        int ele = stack[top];
        printf("Peeked: %d\n", ele);
    }
    else
         printf("\nStack underflow");
}