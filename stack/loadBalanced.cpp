#include <cstdio>
#include <iostream>
#include <string>

class Node{
    public:
        char data[1];
        Node * link;
};

class Stack{
    Node * top = nullptr;
    public:
        int isEmpty(){
            if(top == NULL) return 1;
            return 0;
        }
        void push(char symbol){
            Node * node = new Node();
            node->data[0] = symbol;
            
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
        char Top(){
            return top->data[0];
        }
        void printStack(){
            Node *node = top;
            while(node != nullptr){
                printf("%c ",node->data);
                node = node->link;
            }
            printf("\n");
        }
};

class LoadBalanced{
    Stack myStack;
    public:
        void excute(const char *myExpression){
            const std::string myString = myExpression;
            int numCloseOp = 0;
            for (size_t i = 0; i <= myString.length(); i++)
            {
                if(myString[i]=='}' || myString[i]==']' || myString[i]==')'){
                    numCloseOp = numCloseOp + 1;
                }
                if(myString[i]=='{' || myString[i]=='[' || myString[i]=='('){
                    myStack.push(myString[i]);
                }else if(myStack.isEmpty() == 0 && isPair(myStack.Top(),myString[i])==1){
                    numCloseOp = numCloseOp - 1;
                    myStack.pop();
                }
            }
            
            if(myStack.isEmpty() == 1 && numCloseOp == 0){
                printf("Is Balanced");
            }else{
                printf("Is not Balanced");
            }
        }
    private:
        int isPair(char first, char second){
        if(first == '{' && second == '}'){
            return 1;
        }else if(first == '[' && second == ']'){
            return 1;
        }else if(first == '(' && second == ')'){
            return 1;
        }
        return 0;
    }
};

int main(){
    LoadBalanced operatorBalanced;
    operatorBalanced.excute("[()]");
}