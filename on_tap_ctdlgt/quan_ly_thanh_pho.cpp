#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

struct city {
    string name;
    int area;
    int population;
};
typedef struct city CITY;

struct city22 {
    string name2, area2, population2;
};
typedef struct city22 CITY2;

struct node {
    CITY data;
    struct node *pNext;
};
typedef struct node NODE;

struct list {
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;

NODE *createNode(CITY x) {
    NODE *p = new NODE;
    p->data = x;
    p->pNext = NULL;
    return p;
}

void createList(LIST &l) {
    l.pHead = l.pTail = NULL;
}

// nhap thong tin 1 thanh pho
void inputCity(CITY &x) {
    cout << "Enter city's name: "; // tên thành phố
    getline(cin, x.name);
    cout << "Enter city's area: "; //  diện tích (nghìn km2)
    cin >> x.area;
    cout << "Enter city's population: "; // dân số (triệu người)
    cin >> x.population;
    cin.ignore();
}

void readFileCity(ifstream &fileIn, CITY &c) {
    getline(fileIn, c.name, ',');
    fileIn >> c.area;
    fileIn >> c.population;
    // getline(fileIn, c.area2);
    // getline(fileIn, c.population2);
}

// xuat thong tin 1 thanh pho
void outputCity(CITY x) {
    cout << "Name: " << x.name << ", "
         << "Area: " << x.area << " (thousand km2)" << ", "
         << "Population: " << x.population << " (milion peoples)"<< endl;
}

// them dau
void addTail(LIST &l, CITY x) {
    NODE *p = createNode(x);
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// xoa dau
void delHead(LIST &l) {
    if (l.pHead == NULL)
        cout << "The list is empty!";
    else {
        NODE *p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
    }
}

// xoa cuoi
void delTail(LIST &l) {
    if (l.pHead == NULL)
        cout << "The list is empty!";
    else {
        for (NODE *q = l.pHead; q != NULL; q = q->pNext) {
			if (q->pNext == l.pTail) {
				delete l.pTail;
				q->pNext = NULL;
				l.pTail = q;
			}
		}
    }
}

// them thanh pho vao danh sach
void inputCityList(LIST &l, CITY x, int n) {
    // ifstream fileIn;
    // fileIn.open("city.txt", ios_base::in);
    cout << "\n===== ENTER INFORMATIONS OF CITY LIST =====";
    for (int i = 0; i < n; i++) {
        cout << "\nEnter information of city " << i + 1 << ":\n";
        inputCity(x);
        // readFileCity(fileIn, x);
        addTail(l, x);
    }
    // fileIn.close();
}

// xuat danh sach
void outputCityList(LIST l) {
    int count = 1;
    if (l.pHead == NULL)
        cout << "The list is empty!" << endl;
    else {
        NODE *p = l.pHead;
        while (p != NULL) {
            cout << count << ": ";
            outputCity(p->data);
            p = p->pNext;
            count++;
        }
    }
}

// tim thanh pho co dien tich lon nhat
void areaMax(LIST l) {
    int max = l.pHead->data.area;
    NODE *p = l.pHead;
    for (NODE *p = l.pHead; p != NULL; p = p->pNext) {
        if (p->data.area > max)
            max = p->data.area;
    }
    while (p != NULL) {
        if (p->data.area == max) {
            outputCity(p->data);
            break;
        }
        p = p->pNext;
    }
}

// hoan vi 2 thanh pho
void swapCity(CITY &x, CITY &y) {
    CITY temp;
    temp = x; x = y; y = temp;
}

// sap xep thanh pho theo dien tich
void sortArea(LIST l) {
    for (NODE *p = l.pHead; p != NULL; p = p->pNext) {
        for (NODE *q = l.pHead->pNext; q != NULL; q = q->pNext) {
            if (p->data.area > q->data.area)
                swapCity(p->data, q->data);
        }
    }
}

// xoa theo ten thanh pho
void delName(LIST &l, string name) {
    if (l.pHead == NULL)
        cout << "The list is empty!";
        else {
            if (l.pHead->data.name == name)
                delHead(l);
            else if (l.pTail->data.name == name)
                delTail(l);
            else {
                NODE *p = l.pHead;
                NODE *temp = NULL;
                while (p != NULL && p->data.name != name) {
                    temp = p;
                    p = p->pNext;
                }
                if (p == NULL)
                    cout << "404 not found!" << endl;
                else {
                    temp->pNext = p->pNext;
                    delete p;
                }
            }
        }
}

int main() {
    LIST l;
    createList(l);
    CITY x;
    int n;
    string name;
    cout << "Enter number of city: ";
    cin >> n;
    cin.ignore();
    inputCityList(l, x, n);
    cout << "\n===== THE LIST CITY =====\n";
    outputCityList(l);
    cout << "The city has max area: ";
    areaMax(l);
    sortArea(l);
    cout << "\n===== THE LIST CITY AFTER SORT AREA =====\n";
    outputCityList(l);
    cout << "\nEnter the city's name that you want to remove: ";
    getline(cin, name);
    delName(l, name);
    cout << "\n===== THE LIST CITY AFTER REMOVE NAME =====\n";
    outputCityList(l);
    return 0;
}