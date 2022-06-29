#include<iostream>
using namespace std;
struct soHang {
    int heSo;
    int bien;
};
typedef struct soHang SOHANG;
struct node {
    SOHANG data;
    struct node *next;
};
typedef struct node NODE;
struct daThuc {
    NODE *head;
    NODE *tail;
};
typedef struct daThuc DATHUC;
NODE *taoNode(SOHANG x) {
    NODE *p = new NODE;
    p->data = x;
    p->next = NULL;
    return p;
}
void taoDaThuc(DATHUC &px) {
    px.head = px.tail = NULL;
}
void xoaDau(DATHUC &px) {
    if (px.head == NULL)
        cout << "Danh sach rong!";
    else {
        NODE *p = px.head;
        px.head = px.head->next;
        delete p;
    }
}
void xoaCuoi(DATHUC &px) {
    if (px.head == NULL)
        cout << "Danh sach rong!";
    else {
        NODE *p = px.head;
        while (p != NULL) {
            if (p->next == px.tail) {
                delete px.tail;
                p->next = NULL;
                px.tail = p;
            }
            p = p->next;
        }
    }
}
// cau a
void themCuoiDaThuc(DATHUC &px, SOHANG x) {
    NODE *p = taoNode(x);
    if (px.head == NULL)
        px.head = px.tail = p;
    else {
        px.tail->next = p;
        px.tail = p;
    }
}
// cau b
void inDaThuc(DATHUC px) {
    if (px.head == NULL)
        cout << "Da thuc trong!";
    else {
        NODE *p = px.head;
        while (p != px.tail) {
            cout << p->data.heSo << "*" << p->data.bien << " + ";
            p = p->next;
        }
        cout << px.tail->data.heSo << "*" << px.tail->data.bien << "\n";
    }
}
// cau c
void xoaBatKiTheoHeSo(DATHUC &px, int val) {
    if (px.head == NULL)
        cout << "Da thuc trong!";
    else if (px.head->data.heSo == val)
        xoaDau(px);
    else if (px.tail->data.heSo == val)
        xoaCuoi(px);
    else {
        NODE *p = new NODE;
        for (NODE *k = px.head; k != NULL; k = k->next)
        {
            if (k->data.heSo == val) {
                p->next = k->next;
                delete k;
                break;
            }
            p = k;
        }
    }
}
void nhapDaThuc(DATHUC &px) {
    SOHANG x;
    int n;
    cout << "Nhap so so hang cua da thuc: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "NHAP SO HANG THU " << i + 1 << ":\n";
        cout << "Nhap he so: ";
        cin >> x.heSo;
        cout << "Nhap bien: ";
        cin >> x.bien;
        themCuoiDaThuc(px, x);
    }
}
void nhapDaThuc2(DATHUC &px) {
    SOHANG x;
    for (int i = 1; i <= 4; i++) {
        x.heSo = i;
        x.bien = i + 1;
        themCuoiDaThuc(px, x);
    }
}
// cau d
int tinhGiaTriDaThuc(DATHUC px) {
    int ketQua = 0;
    NODE *p = px.head;
    while (p != NULL) {
        ketQua += p->data.heSo * p->data.bien;
        p = p->next;
    }
    return ketQua;
}
int main() {
    bool check = true;
    int number = 5;
    DATHUC px;
    taoDaThuc(px);
    nhapDaThuc2(px);
    cout << "--- DA THUC ---\n";
    inDaThuc(px);
    // xoaCuoi(px);
    int val;
    cout << "Nhap he so cua so hang muon xoa: ";
    cin >> val;
    xoaBatKiTheoHeSo(px, val);
    inDaThuc(px);
    // cout << "Gia tri cua da thuc: " << tinhGiaTriDaThuc(px);
    return 0;
}