#include <stdio.h>
#include <ctype.h>
#define N 5
int front=-1,rear=-1;
int Queue[N];
void enque(int x){
    if((front==0 && rear==N-1) || front==rear+1){
        printf("Queue Overflow\n");
       }
    else if(front==-1 && rear==-1){
        front=rear=0;
        Queue[rear]=x;
       }
    else{
        rear=(rear+1)%N;
        Queue[rear]=x;
       }
}
void deque(){
    if(front==-1 && rear==-1){
        printf("Queue Underflow\n");
    }
    else if(front==rear){
        printf("Deleted Element is %d\n",Queue[front]);
        front=rear=-1;
    }
    else {
        printf("Deleted Element is %d\n",Queue[front]);
        front=(front+1)%N;
    }
}
void display(){
    printf("Elements in the queue are: ");
    if(front<=rear){
        for(int i=front;i<=rear;i++){
            printf("%d\t",Queue[i]);
        }
    }
    else{
        for(int i=front;i<N;i++){
            printf("%d\t",Queue[i]);
        }
        for(int j=0;j<=rear;j++){
            printf("%d\t",Queue[j]);
        }
    }
    printf("\n");
}
int main(){
    int c;
    printf("1. Insert\n2. Deletion\n3. Display\n4. Exit\n");
    do{
        printf("Enter a operation: ");
        scanf("%d",&c);
        switch(c){
            case 1:{
                int x;
                printf("Enter the value to be inserted: ");
                scanf("%d",&x);
                enque(x);
                break;
            }
            case 2:{
                deque();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                printf("Exiting\n");
                break;
            }
            default:
                printf("Entered wrong value, choose again\n");
        }
    }while(c!=4);
}

