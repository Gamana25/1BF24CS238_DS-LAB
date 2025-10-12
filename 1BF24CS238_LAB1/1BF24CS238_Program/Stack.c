#include <stdio.h>
#define N 100
int stack[N];
int top=-1;

void push(){
    int x;
    printf("Enter a value: ");
    scanf("%d",&x);
    if(top==N-1){
        printf("Stack Overflow");
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else {
        int val=stack[top];
        top--;
        printf("Deleted value is %d\n",val);
    }
}
void peek(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Top value is %d\n",stack[top]);
    }
}
void display(){
    if(top==-1){
        printf("Stack Underflow, no elements are there\n");
    }
    else{
        printf("Elements are:");
        for(int i=0;i<=top;i++){
            printf("\t%d",stack[i]);
        }
    }
}
void main(){
    int c;
    printf("\n 1:push\t 2:pop\t 3:peek\t 4:display\t 5:exit");
    do{
        printf("\nChoose a number: ");
        scanf("%d", &c);
            switch(c){
            case 1:{
                push();
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                peek();
                break;
            }
            case 4:{
                display();
                break;
            }
            case 5:{
                printf("Exiting");
                break;
            }
            defualt:{
                printf("You choose wrong number");
                break;
            }
        }
    }while(c!=5);

}
