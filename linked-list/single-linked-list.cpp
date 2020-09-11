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




int main(){
       return 0;
}