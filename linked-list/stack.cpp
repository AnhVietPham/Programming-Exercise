#include <iostream>
using namespace std;

struct Node
{
       int data;
       Node *pNext;
};

typedef struct Node NODE;

struct Stack
{
       NODE *sTop;
};

typedef struct Stack STACK;

NODE *createNode(int data)
{
       NODE *p = new NODE();

       if (p == NULL)
       {
              cout << "Disk is not enough to create NODE";
              return NULL;
       }
       else
       {
              p->data = data;
              p->pNext = NULL;
       }
       return p;
}

void init(STACK &stack)
{
       stack.sTop = NULL;
}

bool isEmpty(STACK stack)
{
       if (stack.sTop == NULL)
       {
              return true;
       }
       return false;
}

bool pop(STACK &stack)
{
       if (stack.sTop == NULL)
       {
              return false;
       }
       else
       {
              NODE *p = new NODE();
              p = stack.sTop;
              stack.sTop = p->pNext;
              delete p;
              return true;
       }
}

int top(STACK stack)
{
       return stack.sTop->data;
}

bool push(STACK &stack, NODE *p)
{
       if (p == NULL)
       {
              return false;
       }

       if (stack.sTop == NULL)
       {
              stack.sTop = p;
       }
       else
       {
              p->pNext = stack.sTop;
              stack.sTop = p;
       }
       return true;
}

void inputStack(STACK &stack, int n)
{
       for (int i = 0; i < n; i++)
       {
              int data;
              cout << "INPUT DATA: ";
              cin >> data;
              NODE *p = createNode(data);
              push(stack, p);
       }
}

void output(STACK &stack)
{
       if (isEmpty(stack))
       {
              cout << "STACK IS EMPTY" << endl;
       }
       else
       {
              while (!isEmpty(stack))
              {
                     cout << top(stack) << "  ";
                     pop(stack);
              }
       }
}

int main()
{
       STACK stack;
       init(stack);
       inputStack(stack, 5);
       output(stack);
       return 0;
}