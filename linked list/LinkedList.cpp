#include <stdlib.h>
#include <cstdio>
#include <stdexcept>

class Node{
    public:
        int data;
        Node *next;
};

class LinkedList{
    Node *head = NULL;

    public:
        void insert(int x){
            Node *temp = new Node();
            temp->data = x;
            temp->next = head;
            head = temp;
        }
        int length(){
            Node *temp = head;
            int i = 0;
            while(temp != NULL){
                i = i+1;
                temp = temp->next;
            }
            return i;
        }
        void print(){
            Node *temp = head;
            while(temp != NULL){
                printf(" %d ",temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
        void insertIn(int data, int position){
            if(position > length())  throw std::runtime_error{"The given position is over the list length"};
            Node *temp1 = new Node();
            temp1->data = data;
            temp1->next = nullptr;
            if(position == 1){
                temp1->next = head;
                head = temp1;
                return;
            }
            Node *temp2 = head;
            for(int i = 0; i < position-2;i++){
                temp2 = temp2->next;
            }
            temp1->next = temp2->next;
            temp2->next = temp1;
        }
        void deleteElement(int position){
            Node * temp1 = head;
            if(position==1){
                head = temp1->next;
                delete temp1;
                return;
            }
            for(int i = 0; i < position-2;i++){
                temp1 = temp1->next;
            }
            Node *temp2 = temp1->next;
            temp1->next = temp2->next;
            delete temp2;
        }
};

int main(){
    LinkedList list;
    printf("How many numbers: ");
    int n,x,i,pos;
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        printf("Enter the number: ");
        scanf("%d",&x);
        printf("Enter the position: ");
        scanf("%d",&pos);
        list.insertIn(x,pos);
        list.print();
    }
}