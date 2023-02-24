#include<cstdio>
#include<stdlib.h>
#include<stdexcept>

class Menu{
    public:
        void print(){
            system("CLS");
            printf("[1] - Insert an element\n");
            printf("[2] - Insert an element at certain position\n");
            printf("[3] - Print the entire list\n");
            printf("[4] - Delete an element at certain position\n");
            printf("[5] - Reverse the entire list\n");
            printf("[6] - Exit\n");
        }
};

class Node{
    public:
        int data;
        Node * next;
};

class LinkedList{
    public:
        Node *head = nullptr;
        void print(){
            Node *temp = head;
            while (temp != NULL)
            {
                printf(" %d ",temp->data);
                temp = temp->next;
            }
            printf("\n");
        }

        void insert(int data){
            Node *node = new Node();
            node->data = data;
            node->next = head;
            head = node;
        }

        void insertAt(int data, int position){
            Node *temp = head;
            Node *node = new Node();
            node->data = data;
            node->next = nullptr;

            if(position == 1){
                node->next = head;
                head = node;
                return;
            }
            for (size_t i = 0; i < position - 2; i++)
            {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }

        void deleteElement(int position){
            Node *node = head;
            if(position == 1){
                head = node->next;
                delete node;
                return;
            }
            for (size_t i = 0; i < position-2; i++)
            {
                node = node->next;
            }
            Node *temp = node->next; 
            node->next = temp->next;
            delete temp;
        }
        void reverseList(){
            Node *next,*prev,*current = nullptr;
            current = head;
            prev = nullptr;
            while(current != NULL)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
};

int main(){
    char res[1];
    int opt,x,pos;
    Menu myMenu;
    LinkedList myList;
    
    do{
        myMenu.print();

        printf("\n\n\nChoice the operation:");
        scanf("%d",&opt);
        system("cls");
        switch (opt)
        {
        case 1:
            printf("Insert the new value on the list:");
            scanf("%d",&x);
            myList.insert(x);
            break;
        case 2:
            printf("Insert the new value on the list:");
            scanf("%d",&x);
            printf("Insert the position:");
            scanf("%d",&pos);
            myList.insertAt(x,pos);
            break;
        case 3:
            printf("Printing all the elemetns\n");
            myList.print();
            break;
        case 4:
            printf("Deleting an Element into the list\n");
            printf("Insert the position:");
            scanf("%d",&pos);
            myList.deleteElement(pos);
            break;
        case 5:
            printf("Reversing the list...\n");
            myList.reverseList();
            myList.print();
            break;
        case 6:
            break;
        default:
            break;
        }

    printf("Would you like to do another operation? [y/n] :");
    scanf("%s",&res);
    }while (res[0]=='y');
    
}