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

void ridOfRecursionAddNodeIntoThree(NODE *&root, int data)
{
       if (root == NULL)
       {
              root = createNode(data);
       }
       else
       {
              NODE *p;
              NODE *temp = root;
              while (temp != NULL)
              {
                     p = temp;
                     if (data > temp->data)
                     {
                            temp = temp->right;
                     }
                     else if (data < temp->data)
                     {
                            temp = temp->left;
                     }
                     else
                     {
                            return;
                     }
              }
              if (data > p->data)
              {
                     p->right = createNode(data);
              }
              else if (data < p->data)
              {
                     p->left = createNode(data);
              }
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

void createBSTRidOfRecursion(NODE *&root, int a[], int n)
{
       init(root);
       for (int i = 0; i < n; i++)
       {
              ridOfRecursionAddNodeIntoThree(root, a[i]);
       }
}

bool findNodeRecursion(NODE *root, int x)
{
       if (root == NULL)
       {
              return false;
       }

       if (root->data == x)
       {
              return true;
       }

       if (root != NULL)
       {
              if (root->data > x)
              {
                     return findNodeRecursion(root->left, x);
              }
              else if (root->data < x)
              {
                     return findNodeRecursion(root->right, x);
              }
       }
}

bool findNodeRidOfRecursion(NODE *root, int x)
{
       if (root == NULL)
       {
              return false;
       }

       while (root != NULL)
       {
              if (root->data > x)
              {
                     root = root->left;
              }
              else if (root->data < x)
              {
                     root = root->right;
              }
              else
              {
                     return true;
              }
       }
       return false;
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

void RNL(NODE *root)
{
       if (root != NULL)
       {
              RNL(root->right);
              cout << root->data << "   ";
              RNL(root->left);
       }
}

void LRN(NODE *root)
{
       if (root != NULL)
       {
              LRN(root->left);
              LRN(root->right);
              cout << root->data << "   ";
       }
}

int main()
{
       NODE *ROOT;
       NODE *ROOT1;
       int a[] = {40, 5, 35, 45, 15, 56, 48, 13, 16, 49, 47};
       int n = sizeof(a) / sizeof(a[0]);

       createBST(ROOT, a, n);
       createBSTRidOfRecursion(ROOT1, a, n);
       // cout << "NLR: "
       //      << "\n";
       // NLR(ROOT);
       cout << "\n";
       cout << "LNR Recursion: "
            << "\n";
       LNR(ROOT);

       cout << "\n";
       cout << "LNR Rid of Recursion: "
            << "\n";
       LNR(ROOT1);

       cout << "\n";
       cout << "Find Node in BST: " << findNodeRecursion(ROOT, 35);

       cout << "\n";
       cout << "Find Node Rid of Recursion in BST: " << findNodeRidOfRecursion(ROOT, 35);
       // cout << "\n";
       // cout << "RNL: "
       //      << "\n";
       // RNL(ROOT);
       // cout << "\n";
       // cout << "LRN: "
       //      << "\n";
       // LRN(ROOT);
       return 0;
}