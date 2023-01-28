#include <cstdio>

class Node{
    public:
        int data;
        Node * link;
};

class Stack {
    public:
        Node * top = nullptr;
        void push(int x){
            Node * node = new Node();
            node->data = x;
            node->link = top;
            top = node;
        }
        void pop(){
            Node * node = top;
            if(top == nullptr){
                printf("Stack is empty");
                return;
            }
            top = top->link;
            delete node;
        }
        int Top(){
            return top->data;
        }
        void printStack(){
            Node *node = top;
            while(node != nullptr){
                printf("%d ",node->data);
                node = node->link;
            }
            printf("\n");
        }
};

int main(){
    Stack myStack;
    myStack.push(10);myStack.printStack();
    myStack.push(20);myStack.printStack();
    myStack.pop();myStack.printStack();
    myStack.push(30);myStack.printStack();
    myStack.push(40);myStack.printStack();
    myStack.pop();myStack.printStack();
    myStack.push(50);myStack.printStack();
}