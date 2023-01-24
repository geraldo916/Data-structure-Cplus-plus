#include <cstdio>
#include <cstdlib>

class Node{
    public: 
        int data;
        Node *next;
        Node *prev;
};

class DoubleLinkedList{
    
    public:
        Node *head = nullptr;
        
        void insertAtHead(int x){
            Node *node = getNewNode(x);
            if(head == NULL){
                head = node;
                return;
            }
            head->prev = node;
            node->next = head;
            head = node;
        }

        void insertAtTail(int x){
            Node *node = getNewNode(x);
            Node *temp = head;

            if(head == NULL){
                insertAtHead(x);
                return;
            }
            while(temp->next != NULL){//Goid to the last element;
                temp = temp->next;
            }
            node->prev = temp;
            temp->next = node;
        }

        void print(){
            Node *node = head;
            printf("Printing...:\n");
            while(node != NULL){
                printf("%d ",node->data);
                node = node->next;
            }
            printf("\n");
        }
        void reversePrint(){
            Node *node = head;
            if(node == NULL) return;//Empty List
            while(node->next != NULL){//Going to last node
                node = node->next;
            }

            printf("Reversing...:\n");
            while(node != NULL)
            {
                printf("%d ",node->data);
                node = node->prev;
            }
            printf("\n");
        }
    private:
        Node* getNewNode(int x){
            Node *newNode = new Node();
            newNode->data = x;
            newNode->next = nullptr;
            newNode->prev = nullptr;
            return newNode;
        }
};

int main(){
    DoubleLinkedList myList;
    int x,i=0;
    while (i <= 5)
    {
        printf("Insert an element at list:");
        scanf("%d",&x);
        myList.insertAtHead(x);
        i = i+1;
    }
    system("cls");
    myList.print();
    myList.reversePrint();
    myList.insertAtTail(100);
    myList.print();
}