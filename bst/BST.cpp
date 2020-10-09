#include <iostream>
using namespace std;

struct Node{
       int data;
       struct Node *right;
       struct Node *left;
};
typedef Node NODE;

void init(NODE *&root){
       root = NULL;
}

NODE* createNode(int data){
       NODE* newNode = new NODE();
       if (newNode == NULL) return;

       newNode->data = data;
       newNode->left = NULL;
       newNode->right = NULL;
}