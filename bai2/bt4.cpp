#include <iostream>
#include <math.h>
#define N 4
using namespace std;

struct Node {
    int x;//row
    int y;//col
    int giatri;
    struct Node *next;
};

int r = 0, c = 0, size = 0;
Node *list;
int option;

void init() {
    list = NULL;
}
Node *TaoNode(int x, int y, int giatri) {
    Node *p = new Node;
    p->x = x;
    p->y = y;
    p->giatri = giatri;
    p->next = NULL;
    return p;
}
void addNode(Node *p) {
    if(list == NULL) {
        list = p;
        p->next = NULL;
    } else {
        Node *last = list;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    }
}

void showMenu();
void menuOption();
void taomatran();
void hienthimatran();
void nhanvoiso();
void returnMenu();

int main() {
    showMenu();
    menuOption();
}

void showMenu() {
    cout << "\n\n";
    cout << "\t\t\t\t1. tao ma tran" << endl;
    cout << "\t\t\t\t2. hien thi ma tran" << endl;
    cout << "\t\t\t\t3. nhan 1 so voi ma tran" << endl;
    cout << "\t\t\t\t4. Exit" << endl;
}
void menuOption() {
    cout << "\t\t\t\t  nhap lua chon: "; cin >> option;

    switch(option) {
        case 1:
            system("cls");
            taomatran();
            returnMenu();
            break;
        case 2:
            system("cls");
            hienthimatran();
            returnMenu();
            break;
        case 3:
            system("cls");
            nhanvoiso();
            cout << "Matrix: " << endl;
            hienthimatran();
            returnMenu();
            break;
        case 4:
            cout << "\t\t\t\t  Exited" << endl;
            break;
    }
}
void taomatran() {
    init();
    cout << "nhap ma tran " << endl;
    cout << "hang: "; cin >> r;
    cout << "cot: "; cin >> c;
    size = r * c;
    int tmp;
    int count = size / 2;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cout << "A[" << i << "][" << j << "]= "; cin >> tmp;
            if(tmp) {
                Node *p = TaoNode(i, j, tmp);
                addNode(p);
                count--;
            }
        }
    }
}
void hienthimatran() {
    if(list != NULL) {
        int arr[r][c];

        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                arr[i][j] = 0;

        Node *p = list;
        while(p != NULL) {
            arr[p->x][p->y] = p->giatri;
            p = p->next;
        }
        
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                cout << arr[i][j] << "\t";
            } cout << endl;
        }
    } else {
        cout << "tao khong thanh cong" << endl;
    }
}
void nhanvoiso() {
    if(list != NULL) {
        int num;
        do {
            cout << "nhap so khac 0 "; cin >> num;
        } while(num == 0);

        Node *p = list;
        while(p != NULL) {
            p->giatri *= num;
            p = p->next;
        }
    } else {
        cout << "Dont have matrix" << endl;
    }
}
void returnMenu() {
    system("pause");
    system("cls");
    showMenu();
    menuOption();
}
