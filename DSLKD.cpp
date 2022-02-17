#include<iostream>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
struct list
{
    NODE *head;
    NODE *tail;
};
typedef struct list LIST;
NODE *taoNode(int giaTri) 
{
    NODE *p = new NODE;
    p->data = giaTri;
    p->next = NULL;
    return p;
}
void taoDanhSach(LIST &l) 
{
    l.head = l.tail = NULL;
}
bool ktraDanhSachRong(LIST l) 
{
    return l.head == NULL;
}
int kichThuocDanhSach(LIST l) 
{
    if (ktraDanhSachRong(l))
        return 0;
    else 
    {
        int count = 0;
        NODE *p = l.head;
        while(p != NULL) 
        {
            count++;
            p = p->next;
        }
        return count;
    }
}
void xuatDanhSach(LIST l) 
{
    if (kichThuocDanhSach(l) == 0)
        std::cout << "Danh sach rong!";
    else 
    {
        NODE *p = l.head;
        while (p != NULL) 
        {
            std::cout << p->data << " ";
            p = p->next;
        }
    }
}
void themDau(LIST &l, int giaTri) 
{
    NODE *p = taoNode(giaTri);
    if (kichThuocDanhSach(l) == 0)
        l.head = l.tail = p;
    else 
    {
        p->next = l.head;
        l.head = p;
    }
}
void themCuoi(LIST &l, int giaTri) 
{
    NODE *p = taoNode(giaTri);
    if (ktraDanhSachRong(l))
        l.head = l.tail = p;
    else 
    {
        l.tail->next = p;
        l.tail = p;
    }
}
void xoa(LIST &l, int val) {
    NODE *g = new NODE;
    for (NODE *k = l.head; k != NULL; k = k->next) {
        if (k->data == val) {
            g->next = k->next;
            delete k;
            break;
        }
        g = k;
    }
}
int main() 
{
    LIST l;
    taoDanhSach(l);
    for (int i = 0; i < 5; i++)
        themDau(l, i);
    // themDau(l, 1);
    // themCuoi(l, 2);
    // themCuoi(l, 3);
    xuatDanhSach(l);
    xoa(l, 2);
    std::cout << "\n";
    xuatDanhSach(l);
    return 0;
}
