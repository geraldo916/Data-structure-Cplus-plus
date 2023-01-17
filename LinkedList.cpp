#include <stdlib.h>
#include <cstdio>

struct Node {
    int data;
    struct Node * next;
};
struct Node* head;
void insert(int x){
    struct Node* temp = (Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}
void print(){
    struct Node * temp = head;
    printf("List is:");
    while(temp != NULL){
        printf(" %d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    head = NULL;
    printf("How many numbers: ");
    int n,x,i;
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        printf("Enter the number: ");
        scanf("%d",&x);
        insert(x);
        print();
    }
}