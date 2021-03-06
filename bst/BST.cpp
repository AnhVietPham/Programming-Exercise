#include <iostream>
#include <vector>
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
       NODE *newNode = new NODE;
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
void findNodeReplaceMostLeftOfRightSub(NODE *&root, NODE *&p)
{
       if (root->left != NULL)
       {
              findNodeReplaceMostLeftOfRightSub(root->left, p);
       }
       else
       {
              p->data = root->data;
              p = root;
              root = root->right;
       }
}

void findNodeReplaceMostRightOfLeftSub(NODE *&root, NODE *&p)
{
       if (root->right != NULL)
       {
              findNodeReplaceMostRightOfLeftSub(root->right, p);
       }
       else
       {
              p->data = root->data;
              p = root;
              root = root->left;
       }
}

void removeNode(NODE *&root, int x)
{
       if (root == NULL)
       {
              return;
       }

       if (x > root->data)
       {
              removeNode(root->right, x);
       }
       else if (x < root->data)
       {
              removeNode(root->left, x);
       }
       else
       {
              NODE *p = root;
              if (root->left == NULL)
              {
                     root = p->right;
              }
              else if (root->right == NULL)
              {
                     root = p->left;
              }
              else
              {
                     findNodeReplaceMostLeftOfRightSub(root->right, p);
              }

              delete p;
              p = NULL;
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

int findMinInBSTRecursion(NODE *Root)
{
       if (Root == NULL)
       {
              return 0;
       }

       if (Root->left != NULL)
       {
              return findMinInBSTRecursion(Root->left);
       }

       return Root->data;
}

int findMinInBSTRidOfRecursion(NODE *Root)
{
       if (Root == NULL)
       {
              return 0;
       }

       while (Root->left != NULL)
       {
              Root = Root->left;
       }

       return Root->data;
}

int findMaxInBSTRecursion(NODE *Root)
{
       if (Root == NULL)
       {
              return -1;
       }

       if (Root->right != NULL)
       {
              return findMaxInBSTRecursion(Root->right);
       }

       return Root->data;
}

int findMaxInBSTRidOfRecursion(NODE *Root)
{
       if (Root == NULL)
       {
              return -1;
       }

       while (Root->right != NULL)
       {
              Root = Root->right;
       }

       return Root->data;
}

void convertFromBSTToArray(NODE *Root, vector<int> &arr, int x, int y, bool &isAddX, bool &isAddY)
{

       if (Root != NULL)
       {
              convertFromBSTToArray(Root->left, arr, x, y, isAddX, isAddY);

              if (Root->data > x && isAddX == false)
              {
                     arr.push_back(x);
                     isAddX = true;
              }

              if (Root->data > y && isAddY == false)
              {
                     arr.push_back(y);
                     isAddY = true;
              }

              arr.push_back(Root->data);

              convertFromBSTToArray(Root->right, arr, x, y, isAddX, isAddY);
       }
}

void outPutVector(vector<int> vector)
{
       cout << "Output Vector of begin and end: ";
       for (auto i = vector.begin(); i != vector.end(); i++)
       {
              cout << *i << "   ";
       }
}

int binarySearch(vector<int> arr, int left, int right, int x)
{
       if (left > right)
       {
              return -1;
       }

       int mid = (left + right) / 2;

       if (x < arr[mid])
       {
              return binarySearch(arr, left, mid - 1, x);
       }

       if (x > arr[mid])
       {
              return binarySearch(arr, mid + 1, right, x);
       }

       if (x == arr[mid])
       {
              return mid;
       }
}

void checkBST(NODE *ROOT, bool &isBST, int data = INT32_MIN)
{
       if (ROOT != NULL)
       {
              checkBST(ROOT->left, isBST, data);
              if (ROOT->data > data && isBST == true)
              {
                     data = ROOT->data;
                     isBST = true;
              }
              else
              {
                     data = ROOT->data;
                     isBST = false;
                     return;
              }
              checkBST(ROOT->right, isBST, data);
       }
}

void GiaiPhongCay_DeQuy(NODE *&Root)
{
       if (Root != NULL)
       {
              GiaiPhongCay_DeQuy(Root->left);
              GiaiPhongCay_DeQuy(Root->right);

              delete Root;
              // Root = NULL; // Để sau hàm giải phóng nếu người dùng có thao tác gì đó với cây thì Root = NULL nên ko làm gì được nữa, tránh xảy ra lỗi ngang
       }
}

int main()
{
       NODE *ROOT;
       NODE *ROOT1;
       bool isBST = true;
       // ROOT1 = createNode(20);
       // ROOT1->left = createNode(10);
       // ROOT1->right = createNode(21);
       // ROOT1->left->right = createNode(13);
       // ROOT1->right->left = createNode(13);
       int a[] = {40, 5, 35, 45, 15, 56, 48, 13, 16, 49, 47};
       // // int a[] = {50, 30, 100, 20, 40, 35, 45, 37};
       int n = sizeof(a) / sizeof(a[0]);
       // vector<int> arr;
       // int x = 59;
       // int y = 89;
       // bool isAddX = false;
       // bool isAddY = false;
       createBST(ROOT, a, n);
       // convertFromBSTToArray(ROOT, arr, x, y, isAddX, isAddY);
       // if (isAddX == false && isAddY == false)
       // {
       //        arr.push_back(x);
       //        arr.push_back(y);
       //        isAddX = true;
       //        isAddY = true;
       // }

       // outPutVector(arr);
       // cout << endl;
       // int indexOfX = binarySearch(arr, 0, arr.size() - 1, x);
       // int indexOfY = binarySearch(arr, 0, arr.size() - 1, y);
       // cout << "Index of X in arr: " << indexOfX << endl;
       // cout << "Index of Y in arr: " << indexOfY << endl;
       // cout << "Quantity of number in [X,Y] " << indexOfY - indexOfX + 1 - 2;
       checkBST(ROOT, isBST);
       cout << "Check BST: " << isBST;
       // createBSTRidOfRecursion(ROOT1, a, n);
       // // cout << "NLR: "
       // //      << "\n";
       // // NLR(ROOT);
       // // GiaiPhongCay_DeQuy(ROOT);
       // cout << "\n";
       // cout << "LNR Recursion: "
       //      << "\n";
       // LNR(ROOT);

       // cout << "\n";
       // cout << "Min in BST Recursion: " << findMinInBSTRecursion(ROOT) << endl;
       // cout << "Min in BST Rid of Recursion: " << findMinInBSTRidOfRecursion(ROOT) << endl;

       // cout << "Max in BST Recursion: " << findMaxInBSTRecursion(ROOT) << endl;
       // cout << "Max in BST Rid of Recursion: " << findMaxInBSTRidOfRecursion(ROOT) << endl;
       // cout << "\n";
       // cout << "LNR Rid of Recursion: "
       //      << "\n";
       // LNR(ROOT1);

       // removeNode(ROOT, 30);
       // cout << "\n";
       // cout << "LNR Recursion: "
       //      << "\n";
       // LNR(ROOT);

       // // cout << "\n";
       // // cout << "LNR Rid of Recursion: "
       // //      << "\n";
       // // LNR(ROOT1);

       // // cout << "\n";
       // // cout << "Find Node in BST: " << findNodeRecursion(ROOT, 35);

       // // cout << "\n";
       // // cout << "Find Node Rid of Recursion in BST: " << findNodeRidOfRecursion(ROOT, 35);
       // // cout << "\n";
       // // cout << "RNL: "
       // //      << "\n";
       // // RNL(ROOT);
       // // cout << "\n";
       // // cout << "LRN: "
       // //      << "\n";
       // // LRN(ROOT);
       return 0;
}