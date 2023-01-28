#include <cstdio>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void push(int x){
    if(top == MAX_SIZE - 1){
        printf("Error: Stack Overflow\n");
        return;
    }
    top++;
    A[top] = x;
}

void pop(){
    if(top == -1){
        printf("Error: No Element to Pop\n");
        return;
    }
    top--;
}

int Top(){
    return A[top];
}

void printStack(){
    int i;
    for (size_t i = 0; i <= top; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main(){
    push(10);printStack();
    push(20);printStack();
    pop();printStack();
    push(30);printStack();
    push(40);printStack();
    pop();printStack();
    push(50);printStack();
}