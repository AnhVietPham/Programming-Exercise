#include <iostream>
using namespace std;

struct Node
{
       int data;
       struct Node *right;
       struct Node *left;
};
typedef Node NODE;

void init(NODE *&root)
{
       root = NULL;
}

NODE *createNode(int data)
{
       NODE *newNode = new NODE();
       if (newNode == NULL)
              return NULL;

       newNode->data = data;
       newNode->left = NULL;
       newNode->right = NULL;
       return newNode;
}

void addNodeIntoThree(NODE *&root, int data)
{
       if (root != NULL)
       {
              if (data < root->data)
              {
                     addNodeIntoThree(root->left, data);
              }
              else if (data > root->data)
              {
                     addNodeIntoThree(root->right, data);
              }
       }
       else
       {
              root = createNode(data);
       }
}

void createBST(NODE *&root, int a[], int n)
{
       init(root);
       for (int i = 0; i < n; i++)
       {
              addNodeIntoThree(root, a[i]);
       }
}

void NLR(NODE *root)
{
       if (root != NULL)
       {
              cout << root->data << "   ";
              NLR(root->left);
              NLR(root->right);
       }
}

void LNR(NODE *root)
{
       if (root != NULL)
       {
              LNR(root->left);
              cout << root->data << "   ";
              LNR(root->right);
       }
}

void RNL(NODE *root){
       if (root != NULL)
       {
              RNL(root->right);
              cout << root->data << "   ";
              RNL(root->left);
       }
}

int main()
{
       NODE *ROOT;
       int a[] = {40, 5, 35, 45, 15, 56, 48, 13, 16, 49, 47};
       int n = sizeof(a) / sizeof(a[0]);

       createBST(ROOT, a, n);
       cout << "NLR: "<< "\n";
       NLR(ROOT);
       cout<<"\n";
       cout << "LNR: "<< "\n";
       LNR(ROOT);
       cout<<"\n";
       cout << "RNL: "<< "\n";
       RNL(ROOT);
       return 0;
}