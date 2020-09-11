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

int main()
{
       LIST list;
       input(list);
       output(list);
       return 0;
}