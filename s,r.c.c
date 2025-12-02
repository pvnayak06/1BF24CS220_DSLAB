#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
void createList(int n) {
    struct Node *newNode, *temp,*head;
    int data, i;
    if (n <= 0) {
        
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    printf("\nLinked list created successfully.\n");
}
    void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;       
    }
    *head = prev;
    printf("List reversed\n");
}
 void sort(struct Node* head) {
    struct Node *i, *j;
    int temp;
    if (head == NULL){ return;
    }
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted.\n");
}
void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
    printf("Lists concatenated.\n");
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    struct Node *newNode, *temp;
    int choice, n, i;

    
      printf("\nSingly Linked List Operations\n1. Create Linked List\n2. Display List \n3.sort\n4. reverse\n5. concatenate\n6. Exit\n");
       while(1) { printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                list1 = NULL; 
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                
                for(i = 0; i < n; i++) {
                    newNode = (struct Node*)malloc(sizeof(struct Node));
                    printf("Enter data for node %d: ", i+1);
                    scanf("%d", &newNode->data);
                    newNode->next = NULL;

                    if (list1 == NULL) {
                        list1 = newNode;
                        temp = list1; 
                    } else {
                        temp->next = newNode;
                        temp = temp->next; 
                    }
                }
                break;

            case 2:
                display(list1);
                break;

            case 3:
                sort(list1);
                break;

            case 4:
                reverse(&list1);
                break;

            case 5:
                list2 = NULL;
                printf("Enter number of nodes for List 2: ");
                scanf("%d", &n);

                for(i = 0; i < n; i++) {
                    newNode = (struct Node*)malloc(sizeof(struct Node));
                    printf("Enter data for List 2 node %d: ", i+1);
                    scanf("%d", &newNode->data);
                    newNode->next = NULL;

                    if (list2 == NULL) {
                        list2 = newNode;
                        temp = list2;
                    } else {
                        temp->next = newNode;
                        temp = temp->next;
                    }
                }
                concatenate(&list1, list2);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

