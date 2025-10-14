#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define N 100
int Stack[N];
int top=-1;

void push(char c){
    if(top==N-1){
        printf("Stack Overflow\n");
        return;
    }
    Stack[++top]=c;
}

char pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    return Stack[top--];
}
char peek(){
    if(top==-1)
        return -1;
    return Stack[top];
}

int precedence(char o){
    switch(o){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
            return 0;
    }
    return -1;
}

int assosivity(char o){
    if(o=='^')
        return 1;
    return 0;
}

void conversion(char infix[], char postfix[]){
    int k=0;
    char c;
    for(int i=0;infix[i]!='\0';i++){
        c=infix[i];
        if(isalnum(c)){
            postfix[k++]=c;
        }
        else if(c=='(')
            push(c);
        else if(c==')'){
            while (peek()!='('){
                postfix[k++]=pop();
            }
            pop(); 
        }
        else {
            while (top!=-1 && ( (precedence(peek())>precedence(c)) || (precedence(peek())==precedence(c) && assosivity(c)==0))){
                postfix[k++]=pop();
            }
            push(c);
        }
    }
    while(top!=-1){
        postfix[k++]=pop();
    }
    postfix[k] = '\0';
}

int main(){
    char infix[N],postfix[N];
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    conversion(infix, postfix);
    printf("Postfix expression: %s",postfix);
    return 0;
}