#include <cstdio>

class Node{
    public:
        int data;
        Node * next;
};

class Queue{
    Node *front = nullptr;
    Node *rear = nullptr;
    public:
        void Enqueue(int x){
            Node *temp = new Node();
            temp->data = x;
            temp->next = nullptr;
            if(front == nullptr && rear==nullptr){
                front = rear = temp;
                return;
            }else{
                rear->next = temp;
                rear = temp;
            }
        }

        void Dequeue(){
            Node *temp = front;
            if(front==nullptr)return;
            if(front == rear){
                front = rear = nullptr;
            }else{
                front = temp->next;
            }
            delete temp;
        }
};

int main(){
    Queue myQueue;
    myQueue.Enqueue(3);
    myQueue.Enqueue(5);
    myQueue.Enqueue(7);
    myQueue.Enqueue(1);
}