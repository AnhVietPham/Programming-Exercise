#include <iostream>

using namespace std;

struct  Node
{
       int data;
       struct  Node *pNext;
};
typedef struct  Node NODE;

struct List
{
       NODE *pHead, *pTail;
};

typedef struct List LIST;

void init(LIST &list){
       list.pHead = list.pTail = NULL;
}

NODE* createNote(int value){
       NODE *p = new NODE;

       if (p == NULL)
       {
              cout << "You can not create a NODE\n";
              return NULL;
       }

       p ->data = value;
       p ->pNext = NULL;
       return p;
}






int main(){
       return 0;
}