#include <cstdio>

class Node{
    public:
        int data;
        Node *left;
        Node *right;
};

class BinarySearchTree{
    public:
        Node *root = nullptr;

        Node *createNewNode(int data){
            Node *newNode = new Node();
            newNode->data = data;
            newNode->left = nullptr;
            newNode->right = nullptr;
            return newNode;
        }

        Node *Insert(Node *rootPtr, int data){
            if(rootPtr == nullptr){
                rootPtr = createNewNode(data);
            }else if(data <= rootPtr->data){
                rootPtr->left = Insert(rootPtr->left,data);
            }else{
                rootPtr->right = Insert(rootPtr->right,data);
            }
            return rootPtr;
        }

        bool Search(Node *rootPtr, int value){
            if(rootPtr == nullptr){
                return false;
            }else if(value == rootPtr->data){
                return true;
            }else if(value <= rootPtr->data){
                return Search(rootPtr->left,value);
            }else{
                return Search(rootPtr->right,value);
            } 
        }
};

int main(){
    BinarySearchTree myTree;
    myTree.root = myTree.Insert(myTree.root,10);
    myTree.Insert(myTree.root,18);
    myTree.Insert(myTree.root,12);
    myTree.Insert(myTree.root,2);
    myTree.Insert(myTree.root,212);

    if(myTree.Search(myTree.root,21) == true){
        printf("Found!!");
    }else{
        printf("Not Found!!");
    }
}