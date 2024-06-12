#include <iostream>
#include"1.h"
using namespace std;

//so luong san pham lon nhat
const int MAX_PRODUCTS = 100;

//Ham tao mau mot sam pham
Stationery::Stationery(int _id, string _n, double _p, int _q) {
    id = _id;
    name = _n;
    price = _p;
    quantity = _q;
}

//Ham lay id san pham
int Stationery::getId()     {return id;}

//Ham lay ten san pham
string Stationery::getName()    {return name;}
        
//Ham lay gia tien cua san pham
double Stationery::getPrice()   {return price;}
        
//Han lay so luong cua san pham
int Stationery::getQuantity()   {return quantity;}       

//Ham thay doi id cua san pham
void Stationery::setId(int _id)     {id = _id;}

//Ham thay ten cua san pham
void Stationery::setName(string _n)     {name=_n;}

//Ham thay doi gia tien cua san pham
void Stationery::setPrice(double _p)    {price=_p;}

//Ham thay doi so luong san pham
void Stationery::setQuantity(int _q)    {quantity=_q;}

//Ham nhap thong tin san pham
void Stationery::nhaptt() {
    cout << "Nhap ID san pham: ";
    cin >> id;
    cin.ignore();
    cout << "Nhap ten san pham: ";
    getline(cin, name);
    cout << "Nhap gia san pham: ";
    cin >> price;
    cout << "Nhap so luong san pham: ";
    cin >> quantity;
}

//Ham hien thi thong tin san pham
void Stationery::hienthitt() {
    cout << "Ma so san pham: " << id << endl;
    cout << "Ten san pham: " << name << endl;
    cout << "Gia san pham: " << price << " vnd"<<endl;
    cout << "So luong san pham: " << quantity << endl;
}

//ham hien thi menu
void displayMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Them moi san pham\n";
    cout << "2. Sua thong tin san pham\n";
    cout << "3. Xoa san pham\n";
    cout << "4. Hien thi danh sach san pham\n";
    cout << "5. Thoat\n";
    cout << "Nhap lua chon: ";
}

//Ham tim kiem san pham theo id
int findProductById(Stationery products[], int count, int id) {
    for (int i = 0; i < count; ++i) {
        if (products[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    Stationery products[MAX_PRODUCTS];
    int count = 0;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            if (count < MAX_PRODUCTS) //kiem tra so luong san pham da day chua
            {
                Stationery newProduct;
                newProduct.nhaptt();
                products[count] = newProduct;
                count++;
            }
            else {
                cout << "Khong the them san pham moi. Danh sach da day.\n";
            }
            break;
        }
        case 2: {
            int id;
            cout << "Nhap ID san pham can sua: ";
            cin >> id;
            int index = findProductById(products, count, id);
            if (index != -1) {
                products[index].nhaptt();
            }
            else {
                cout << "San pham khong ton tai.\n";
            }
            break;
        }
        case 3: {
            int id;
            cout << "Nhap ID san pham can xoa: ";
            cin >> id;
            int index = findProductById(products, count, id);
            if (index != -1) {
                for (int i = index; i < count - 1; ++i) {
                    products[i] = products[i + 1];
                }
                count--;
                cout << "San pham da duoc xoa.\n";
            }
            else {
                cout << "San pham khong ton tai.\n";
            }
            break;
        }
        case 4: {
            for (int i = 0; i < count; ++i) {
                products[i].hienthitt();
                cout << "----------------\n";
            }
            break;
        }
        case 5:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
            break;
        }
    } while (choice != 5); 

    return 0;
}