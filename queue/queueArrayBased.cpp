#include <cstdio>

#define MAX_SIZE 20
int myArray[MAX_SIZE];
int front = -1;
int rear = -1;

bool isFull(){
    if(rear == MAX_SIZE) return true;
    return false;
}

bool isEmpty(){
    if(rear == -1 && front == -1) return true;
    return false;
}

void Enqueue(int x){
    if(rear == MAX_SIZE) return;
    if(rear == -1 && front == -1){
        rear = 0;
        front = 0;
    }else{
        rear = rear + 1;
    }
    myArray[rear] = x;
}

int Peek(){
   // if(isEmpty()) return -1;
    return myArray[front];
}

int Dequeue(){
    if(isEmpty()) return -1;
    if(rear == front){
        front = -1;
        rear = -1;
    }else{
        front = front + 1;
    }
}

void printQueue(){
    for(size_t i = 0; i <= rear; i++)
    {
        printf("%d ",myArray[i]);
    }
}

int main(){
    Enqueue(5);
    Enqueue(2);
    Enqueue(10);
    printQueue();   
    printf("\n %d",Peek());
}