#include <iostream>
using namespace std;
struct NODE {
    int key;
    int height;
    NODE* pLeft;
    NODE* pRight;
};
typedef NODE *TREE;
NODE* createNode(int val) {
    NODE *p = new NODE;
    p->key = val;
    p->height = 1;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void createTree(TREE& t) {
    t = NULL;
}
int max(int a, int b) {
    if(a > b)
        return a;
    return b;
}
int heightTree(TREE t) {
    if(t == NULL)
        return 0;
    return t->height;
}
int getBalance(TREE &t) {
    if(t == NULL)
        return 0;
    return heightTree(t->pLeft) - heightTree(t->pRight);
}

// quay phải
NODE* rotationRight(TREE &y) {
    NODE* x = y->pLeft;
    NODE* T2 = x->pRight;
    y->pLeft = T2;
    y->height = max(heightTree(y->pLeft), heightTree(y->pRight));
    x->height = max(heightTree(x->pLeft), heightTree(x->pRight));
    return x;
}

// quay trái
NODE* rotationLeft(TREE &x) {
    NODE* y = x->pRight;
    NODE* T2 = y->pLeft;
    y->pLeft = x;
    x->pRight = T2;
    x->height = max(heightTree(x->pLeft), heightTree(x->pRight));
    y->height = max(heightTree(y->pLeft), heightTree(y->pRight));
    return y;
}
// thêm node vào cây
NODE* insert(TREE& t, int val) {
    NODE *p = createNode(val);
    if(t == NULL)
        return p;
    if(val < t->key)
        t->pLeft = insert(t->pLeft, val);
    else if(val > t->key)
        t->pRight = insert(t->pRight, val);
    else
        return t;
    t->height = max(heightTree(t->pLeft), heightTree(t->pRight));

    int bal = getBalance(t);
    // left left
    if((bal > 1 && val < t->pLeft->key))
        return rotationRight(t);
    // right right
    if(bal < -1 && val > t->pRight->key)
        return rotationLeft(t);
    // left right
    if(bal > 1 && val > t->pLeft->key) {
        t->pLeft = rotationLeft(t->pLeft);
        return rotationRight(t);
    }
    // right left
    if(bal < -1 && val < t->pRight->key) {
        t->pRight = rotationLeft(t->pRight);
        return rotationLeft(t);
    }
    return t;
}
// thêm giá trị vào cây
void input(TREE& t) {
    int a[] = {2, 4, 1, 5, 7, 12, 9};
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i++)
       t = insert(t, a[i]);
}
void preOrder(TREE t) {
	if (t != NULL) {
		cout << t->key << " ";
		preOrder(t->pLeft);
		preOrder(t->pRight);
	}
}
void inOrder(TREE t) {
	if (t != NULL) {
		inOrder(t->pLeft);
		cout << t->key << " ";
		inOrder(t->pRight);
	}
}
int main() {
    TREE t;
    createTree(t);
    input(t);
    cout << "AVL: ";
    preOrder(t);
    cout << "\nAVL: ";
    inOrder(t);
    system("pause");
    return 0;
}