#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;
void createList(int n) {
    int data;
    struct Node *newNode, *temp = NULL;

    if (n <= 0) {
        printf("Number of nodes should be greater than 0.\n");
        return;
    }

    top = NULL;

    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (top == NULL) {
            top = newNode;
        }
        else {
            temp->next = newNode;
        }

        temp = newNode;
    }
    printf("Linked list created successfully.\n");
}

void push() {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node *temp = top;
    printf("Popped %d\n", temp->data);

    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", top->data);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp = top;
    printf("Stack: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, n;

    printf("\nSTACK using Singly Linked List\n");
    printf("\n1. Create Stack Linked List\n");
    printf("2. Push\n");
    printf("3. Pop\n");
    printf("4. Peek\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            createList(n);
            break;
        case 2:
            push();
            break;
        case 3:
            pop();
            break;
        case 4:
            peek();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
