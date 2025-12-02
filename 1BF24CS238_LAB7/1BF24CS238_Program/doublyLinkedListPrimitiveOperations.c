#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void createDLL(int n) {
    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    int value;
    struct Node *newNode, *temp;

    head = NULL;

    for (int i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->prev = newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
    printf("Doubly Linked list created successfully.\n");
}

void insertLeft(int pos, int value) {
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (pos == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    printf("Node is inserted to left at position %d.\n",pos);
}


void deleteSpecificValue(int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node %d is deleted.\n", value);
}

void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    printf("NULL ");
    while (temp != NULL) {
        printf("<- %d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, n, value, pos;
    printf("\nDoubly Linked List primitive operations:\n");
    printf("1. Create list\n");
    printf("2. Insert left of position\n");
    printf("3. Delete node by value\n");
    printf("4. Display list\n");
    printf("5. Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createDLL(n);
                break;

            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertLeft(pos, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteSpecificValue(value);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}
