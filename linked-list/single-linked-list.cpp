#include <iostream>

using namespace std;

struct Node
{
       int data;
       struct Node *pNext;
};
typedef struct Node NODE;

struct List
{
       NODE *pHead, *pTail;
};

typedef struct List LIST;

void init(LIST &list)
{
       list.pHead = list.pTail = NULL;
}

NODE *createNote(int value)
{
       NODE *p = new NODE;

       if (p == NULL)
       {
              cout << "You can not create a NODE\n";
              return NULL;
       }

       p->data = value;
       p->pNext = NULL;
       return p;
}

void addHead(LIST &list, NODE *p)
{
       if (list.pHead == NULL)
       {
              list.pHead = list.pTail = p;
       }
       else
       {
              p->pNext = list.pHead;
              list.pHead = p;
       }
}

void addTail(LIST &list, NODE *p)
{
       if (list.pHead == NULL)
       {
              list.pHead = list.pTail = p;
       }
       else
       {
              list.pTail->pNext = p;
              list.pTail = p;
       }
}

void input(LIST &list)
{
       init(list);

       int n;
       cout << "Input quantity of element of Single Linked List: ";
       cin >> n;

       for (int i = 0; i < n; i++)
       {
              int value;
              cout << "\nInput value: ";
              cin >> value;

              NODE *p;
              p = createNote(value);
              addTail(list, p);
       }
}

void output(LIST list)
{
       for (NODE *p = list.pHead; p != NULL; p = p->pNext)
       {
              cout << "   " << p->data;
       }
}

int sum(LIST list)
{
       int sum = 0;
       for (NODE *p = list.pHead; p != NULL; p = p->pNext)
       {
              sum += p->data;
       }
       return sum;
}

void listEvenNumber(LIST list)
{
       cout << "\nList Even Number: ";
       for (NODE *p = list.pHead; p != NULL; p = p->pNext)
       {
              if (p->data % 2 == 0)
              {
                     cout << "   " << p->data;
              }
       }
}

void swapSolutionOne(int &x, int &y)
{
       int temp = x;
       x = y;
       y = temp;
}

void swapSolutionTwo(int &x, int &y)
{
       x = x + y;
       y = x - y;
       x = x - y;
}

void listOddNumber(LIST list)
{
       cout << "\nList Odd Number: ";
       for (NODE *p = list.pHead; p != NULL; p = p->pNext)
       {
              if (p->data % 2 != 0)
              {
                     cout << "   " << p->data;
              }
       }
}

void arrangeIncreasing(LIST &list)
{
       for (NODE *p = list.pHead; p != NULL; p = p->pNext)
       {
              for (NODE *q = p->pNext; q != NULL; q = q->pNext)
              {
                     if (p->data > q->data)
                     {
                            swapSolutionTwo(p->data, q->data);
                     }
              }
       }
}

void arrangDecreasing(LIST &list)
{
       for (NODE *p = list.pHead; p != NULL; p = p->pNext)
       {
              for (NODE *q = p->pNext; q != NULL; q = q->pNext)
              {
                     if (p->data < q->data)
                     {
                            swapSolutionOne(p->data, q->data);
                     }
              }
       }
}

// 1 2 3 4 5 6 7

void insertAfter(LIST &list, NODE *x, NODE *k)
{
       for (NODE *p = list.pHead; p != NULL; p = p->pNext)
       {
              if (p->data == x->data)
              {
                     k->pNext = p->pNext;
                     p->pNext = k;
                     return;
              }
       }
}

void insertAfterAllEvenNumber(LIST &list, int data)
{
       for (NODE *p = list.pHead; p != NULL; p = p->pNext)
       {
              if (p->data % 2 == 0)
              {
                     NODE *x = createNote(data);
                     x->pNext = p->pNext;
                     p->pNext = x;
              }
       }
}
// 1 2 3 4 5 6
void insertBefore(LIST &list, NODE *x, NODE *k)
{
       NODE *temp;

       if (list.pHead->data == x->data)
       {
              addHead(list, k);
       }

       for (NODE *p = list.pHead; p != NULL; p = p->pNext)
       {
              if (x->data == p->data)
              {
                     temp->pNext = k;
                     k->pNext = p;
              }
              temp = p;
       }
}

void insertBeforeAllEvenNumber(LIST &list, int data)
{
       NODE *temp;

       if (list.pHead->data % 2 == 0)
       {
              NODE *k = createNote(data);
              addHead(list, k);
       }

       for (NODE *p = list.pHead->pNext; p != NULL; p = p->pNext)
       {
              if (p->data % 2 == 0)
              {
                     NODE *k = createNote(data);
                     temp->pNext = k;
                     k->pNext = p;
              }
              temp = p;
       }
}

void removeOneNode(LIST &list, int data)
{
       NODE *temp;
       for (NODE *p = list.pHead; p != NULL; p = p->pNext)
       {
              if (p->data == data)
              {
                     temp->pNext = p->pNext;
                     delete p;
                     return;
              }
              temp = p;
       }
}

void removeManyNode(LIST &list, int data)
{
       NODE *temp;
       for (NODE *p = list.pHead; p != NULL; p = p->pNext)
       {
              if (p->data == data)
              {
                     temp->pNext = p->pNext;
                     delete p;
                     p = temp;
              }
              temp = p;
       }
}

void removeAfter(LIST &list, int data)
{
       for (NODE *p = list.pHead;  p != NULL; p = p->pNext)
       {
              if (p->data == data)
              {
                     NODE *temp = p->pNext;
                     p->pNext = temp->pNext;
                     delete temp;
                     return;
              }
       }
       
}

void removeBefore(LIST &list, int data)
{
       
}

void destroy(LIST &list)
{
       NODE *p;
       while (list.pHead != NULL)
       {
              p = list.pHead;
              list.pHead = list.pHead->pNext;
              delete p;
       }
}

int main()
{
       LIST list;
       input(list);
       output(list);
       cout << "\n Sum: " << sum(list);
       listEvenNumber(list);
       listOddNumber(list);
       // cout << "\nArrange Increasing: ";
       // arrangeIncreasing(list);
       // output(list);
       // cout << "\nArrange Decreasing: ";
       // arrangDecreasing(list);
       // output(list);
       // cout << "\nInsert after node: ";
       // NODE *p = createNote(2);
       // NODE *k = createNote(69);
       // insertAfter(list, p, k);
       // output(list);
       // cout << "\nInsert after all even number: ";
       // insertAfterAllEvenNumber(list, 69);
       // output(list);
       // cout << "\nInsert before node: ";
       // NODE *p = createNote(3);
       // NODE *k = createNote(69);
       // insertBefore(list, p, k);
       // output(list);
       // cout << "\nInsert before all even number: ";
       // insertBeforeAllEvenNumber(list, 69);
       // cout << "\nRemove one NODE: ";
       // removeOneNode(list, 2);
       // cout << "\nRemove many NODE: ";
       // removeManyNode(list, 2);
       cout<<"\nRemove Node after: ";
       removeAfter(list, 2);
       output(list);
       destroy(list);
       return 0;
}