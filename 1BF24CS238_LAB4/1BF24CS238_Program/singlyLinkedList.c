#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *head=NULL;

void createList(int n){
    int data;
    struct Node *newNode,*temp = NULL;
    if(n<=0){
        printf("Number of nodes should be greater than 0.\n");
        return;
    }
    for(int i=0;i<n;i++){
        newNode = (struct Node*) malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("Memory Allocation failed.\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
        }
        else{
            temp->next=newNode;
        }
        temp=newNode;
    }
        printf("Linked list created successfully.\n");
}
void insertAtBeginning(int data){
    struct Node *newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode ->data = data;
    newNode ->next = head;
    head = newNode;
    printf("Node inserted at beginning.\n");

}
void insertAtEnd(int data){
    struct Node *temp,*newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode ->data=data;
    newNode->next = NULL;
    if(head==NULL){
        head = newNode;
    }
    else {
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at end.\n");
}
void insertAtPosition(int data, int pos){
    struct Node *newNode, *temp = head;
    if(pos<1){
        printf("Invalid Position.\n");
    }
    if(pos==1){
        insertAtBeginning(data);
        return;
    }
    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode ->data=data;

    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp = temp ->next;
    }
    if(temp == NULL){
        printf("Position out of range.\n");
        free(newNode);
    }
    else {
        newNode->next =temp->next;
        temp ->next = newNode;
        printf("Node inserted at %d.\n",pos);
    }
}
void display(){
     struct Node *temp = head;
    if(head==NULL){
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked list: ");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    int c,n,data,pos;
    printf("\n Singly Linked List operations \n");
    printf("1. Create Linked list\n");
    printf("2. Insert at Beginning\n");
    printf("3. Insert at End\n");
    printf("4. Insert at a Position\n");
    printf("5. Display List\n");
    printf("6. Exit\n");

    do{
        printf("\nEnter a choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:{
                printf("Enter number of nodes: ");
                scanf("%d",&n);
                createList(n);
                break;
            }
            case 2:{
                printf("Enter data: ");
                scanf("%d",&data);
                insertAtBeginning(data);
                break;
            }
            case 3:{
                printf("Enter data: ");
                scanf("%d",&data);
                insertAtEnd(data);
                break;
            }
            case 4:{
                printf("Enter data: ");
                scanf("%d",&data);
                printf("Enter position: ");
                scanf("%d",&pos);
                insertAtPosition(data,pos);
                break;
            }
            case 5:{
                display();
                break;
            }
            case 6:{
                printf("Exiting...\n");
                break;
            }
            default :
                printf("Choose a valid choice.\n");
        }
    }while(c!=6);
}
