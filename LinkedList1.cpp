#include <stdlib.h>
#include <cstdio>

struct Node{
    int data;
    struct Node *next;
};

struct LinkedList{
    Node *head = NULL;

    void insert(int x){
        struct Node *temp = (Node*)malloc(sizeof(Node)) ;
        temp->data = x;
        temp->next = head;
        head = temp;
    }

    void print(){
        Node *temp;
        while(temp != NULL){
            printf("%d",temp->data);
            temp = temp->next;
        }
    }
};

int main(){
    LinkedList list;
    printf("How many numbers: ");
    int n,x,i;
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        printf("Enter the number: ");
        scanf("%d",&x);
        list.insert(x);
        list.print();
    }
}