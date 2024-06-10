#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTS = 100; //so san pham toi da

class Stationery {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    
    Stationery(int id, string name, double price, int quantity) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

   //ham tao mac dinh
    Stationery() {
        id = 0;
        name = "";
        price = 0.0;
        quantity = 0;
    }

   
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }

    int getQuantity() {
        return quantity;
    }

   
    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    void setPrice(double price) {
        this->price = price;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    //ham nhap thong tin
    void nhaptt() {
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

    //Ham hien thi thong tin
    void hienthitt() {
        cout << "Ma so san pham: " << id << endl;
        cout << "Ten san pham: " << name << endl;
        cout << "Gia san pham: " << price << endl;
        cout << "So luong san pham: " << quantity << endl;
    }
};

//Ham hien thi menu
void displayMenu() {
    cout << "\n--- MENU ---\n";
    cout << "1. Them moi san pham\n";
    cout << "2. Sua thong tin san pham\n";
    cout << "3. Xoa san pham\n";
    cout << "4. Hien thi danh sach san pham\n";
    cout << "5. Thoat\n";
    cout << "Nhap lua chon: ";
}

//ham tim kiem san pham theo id
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
