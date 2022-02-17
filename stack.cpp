#include<iostream>
using namespace std;

struct node {
    int data;
    node *pNext;
};
typedef node NODE;

struct stack {
    NODE *pTop;
};
typedef stack STACK;

NODE* createNode(int val) {
    NODE *p = new NODE();
    p->data = val;
    p->pNext = NULL;
    return p;
}

void createStack(STACK s) {
    s.pTop = NULL;
}

bool isEmpty(STACK s) {
    if(s.pTop == NULL)
        return true;
    return false;
}

void push(STACK &s, int val) {
    NODE *p = createNode(val);
    if(isEmpty(s) == true)
        s.pTop = p;
    else {
        p->pNext = s.pTop;
        s.pTop = p;
    }
}

void top(STACK s) {
    if(isEmpty(s))
        cout << "Stack dang rong!";
    else 
        cout << "Gia tri dau stack la: " << s.pTop->data;
}

void pop(STACK &s, int &val) {
    if(isEmpty(s))
        cout << "Stack rong!";
    else {
        NODE *p = new NODE;
        p = s.pTop;
        val = p->data;
        s.pTop = s.pTop->pNext;
        delete p;
    }
}

int size(STACK s) {
    NODE *p = s.pTop;
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->pNext;
    }
    return count;
}

int main() {
    STACK s;
    createStack(s);
    for (int i = 1; i <= 10; i += 2)
        push(s, i);
    int x;
    pop(s, x);
    pop(s, x);
    cout << "Kich thuoc Stack la: " << size(s) << endl;
    top(s);
    return 0;
}