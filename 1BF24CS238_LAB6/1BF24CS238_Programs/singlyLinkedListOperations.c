#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head1 = NULL;
struct Node *head2 = NULL;

void createList(struct Node **headRef, int n) {
    struct Node *newNode, *temp = NULL;
    int data;
    *headRef = NULL;

    for (int i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (*headRef == NULL)
            *headRef = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }
}

void display() {
    struct Node *temp;

    printf("List 1: ");
    temp = head1;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("List 2: ");
    temp = head2;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(int optn) {
    struct Node *i, *j;
    int temp;

    struct Node *head = (optn == 1) ? head1 : head2;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverseList(int optn) {
    struct Node *prev = NULL, *curr, *next;

    curr = (optn == 1) ? head1 : head2;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    if (optn == 1)
        head1 = prev;
    else
        head2 = prev;
}

void concatenate() {
    struct Node *temp;

    if (head1 == NULL) {
        head1 = head2;
        return;
    }
    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
}

int main() {
    int choice, n, optn;

    printf("\nSingly Linked List operations\n");
    printf("\n1. Create Linked List 1\n");
    printf("2. Create Linked List 2\n");
    printf("3. Sort\n");
    printf("4. Reverse\n");
    printf("5. Concatenate\n");
    printf("6. Display\n");
    printf("7. Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Number of elements: ");
            scanf("%d", &n);
            createList(&head1, n);
            break;

        case 2:
            printf("Number of elements: ");
            scanf("%d", &n);
            createList(&head2, n);
            break;

        case 3:
            printf("1st List or 2nd List(1/2): ");
            scanf("%d", &optn);
            sortList(optn);
            break;

        case 4:
            printf("1st List or 2nd List(1/2): ");
            scanf("%d", &optn);
            reverseList(optn);
            break;

        case 5:
            concatenate();
            break;

        case 6:
            display();
            break;

        case 7:
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
