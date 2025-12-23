#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void createList(struct Node** head, int n) {
    struct Node *newNode, *temp;
    int data, i;
    
    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    *head = NULL; 

    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        
        newNode = createNode(data);
        
        if (*head == NULL) {
            *head = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp; 
        }
        temp = newNode;
    }
    printf("\nLinked list created successfully.\n");
}

void insertbeg(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode; 
        *head = newNode;         
    }
    printf("Inserted %d at the beginning.\n", data);
}

void insertend(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at the end.\n", data);
}

void insertLeft(struct Node** head, int target, int data) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Target node %d not found!\n", target);
        return;
    }

    struct Node* newNode = createNode(data);
    
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode; 
    }

    temp->prev = newNode;

    printf("Inserted %d to the left of %d\n", data, target);
}

void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found!\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next; 

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node with value %d deleted.\n", value);
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, target, n;

    printf("\n MENU \n1. Insert at Beginning \n2. Insert to the Left\n3. Delete a Node by Value\n4. Display List\n5. Exit\n6. Insert at End\n7. Create List\n");
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertbeg(&head, value);
                break;

            case 2:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter new value to insert: ");
                scanf("%d", &value);
                insertLeft(&head, target, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 4:
                displayList(head);
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);
                break;
                
            case 6: 
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertend(&head, value);
                break; 
                
            case 7: 
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(&head, n);
                break;    

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}