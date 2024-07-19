#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Ð?nh ngh?a c?u trúc s?n ph?m
struct Stationery {
    int id;
    char name[100];
    double price;
    int quantity;
};

// Hàm nh?p thông tin s?n ph?m
void nhapThongTin(struct Stationery *sp) {
    printf("Nhap ID san pham: ");
    scanf("%d", &sp->id);
    getchar(); // Ð?c k? t? Enter t? bàn phím

    printf("Nhap ten san pham: ");
    fgets(sp->name, sizeof(sp->name), stdin);
    sp->name[strcspn(sp->name, "\n")] = '\0'; // Xóa k? t? Enter cu?i chu?i

    printf("Nhap gia san pham: ");
    scanf("%lf", &sp->price);

    printf("Nhap so luong san pham: ");
    scanf("%d", &sp->quantity);
}

// Hàm hi?n th? thông tin s?n ph?m
void hienThiThongTin(const struct Stationery *sp) {
    printf("Ma so san pham: %d\n", sp->id);
    printf("Ten san pham: %s\n", sp->name);
    printf("Gia san pham: %.2f\n", sp->price);
    printf("So luong san pham: %d\n", sp->quantity);
}

// Hàm hi?n th? menu
void hienThiMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Them moi san pham\n");
    printf("2. Sua thong tin san pham\n");
    printf("3. Xoa san pham\n");
    printf("4. Hien thi danh sach san pham\n");
    printf("5. Tim kiem san pham theo ten\n");
    printf("6. Sap xep san pham theo gia\n");
    printf("7. Sap xep san pham theo ten\n");
    printf("8. Thoat\n");
    printf("Nhap lua chon: ");
}

// Hàm t?m ki?m s?n ph?m theo ID
int timSanPhamTheoID(const struct Stationery *ds, int soluong, int id) {
    for (int i = 0; i < soluong; ++i) {
        if (ds[i].id == id) {
            return i; // Tr? v? ch? s? c?a s?n ph?m n?u t?m th?y
        }
    }
    return -1; // Không t?m th?y s?n ph?m
}

// Hàm tìm kiếm sản phẩm theo tên
void timSanPhamTheoTen(const struct Stationery *ds, int soluong, const char *ten) {
    int found = 0;
    for (int i = 0; i < soluong; ++i) {
        if (strstr(ds[i].name, ten) != NULL) {
            hienThiThongTin(&ds[i]);
            printf("----------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay san pham.\n");
    }
}

// Hàm sắp xếp sản phẩm theo giá
void sapXepTheoGia(struct Stationery *ds, int soluong) {
    for (int i = 0; i < soluong - 1; ++i) {
        for (int j = i + 1; j < soluong; ++j) {
            if (ds[i].price > ds[j].price) {
                struct Stationery temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp sản phẩm theo tên
void sapXepTheoTen(struct Stationery *ds, int soluong) {
    for (int i = 0; i < soluong - 1; ++i) {
        for (int j = i + 1; j < soluong; ++j) {
            if (strcmp(ds[i].name, ds[j].name) > 0) {
                struct Stationery temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

int main() {
    struct Stationery products[MAX_PRODUCTS];
    int count = 0;
    int choice;

    do {
        hienThiMenu();
        scanf("%d", &choice);
        getchar(); // Ð?c k? t? Enter t? bàn phím

        switch (choice) {
        case 1: {
            if (count < MAX_PRODUCTS) {
                struct Stationery newProduct;
                nhapThongTin(&newProduct);
                products[count] = newProduct;
                count++;
            } else {
                printf("Khong the them san pham moi. Danh sach da day.\n");
            }
            break;
        }
        case 2: {
            int id;
            printf("Nhap ID san pham can sua: ");
            scanf("%d", &id);
            getchar(); // Ð?c k? t? Enter t? bàn phím
            int index = timSanPhamTheoID(products, count, id);
            if (index != -1) {
                nhapThongTin(&products[index]);
            } else {
                printf("San pham khong ton tai.\n");
            }
            break;
        }
        case 3: {
            int id;
            printf("Nhap ID san pham can xoa: ");
            scanf("%d", &id);
            getchar(); // Ð?c k? t? Enter t? bàn phím
            int index = timSanPhamTheoID(products, count, id);
            if (index != -1) {
                for (int i = index; i < count - 1; ++i) {
                    products[i] = products[i + 1];
                }
                count--;
                printf("San pham da duoc xoa.\n");
            } else {
                printf("San pham khong ton tai.\n");
            }
            break;
        }
        case 4: {
            for (int i = 0; i < count; ++i) {
                hienThiThongTin(&products[i]);
                printf("----------------\n");
            }
            break;
        }
        case 5: {
            char ten[100];
            printf("Nhap ten san pham can tim: ");
            fgets(ten, sizeof(ten), stdin);
            ten[strcspn(ten, "\n")] = '\0'; // Xóa ký tự Enter cuối chuỗi
            timSanPhamTheoTen(products, count, ten);
            break;
        }
        case 6: {
            sapXepTheoGia(products, count);
            printf("San pham da duoc sap xep theo gia.\n");
            break;
        }
        case 7: {
            sapXepTheoTen(products, count);
            printf("San pham da duoc sap xep theo ten.\n");
            break;
        }
        case 8:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (choice != 8);

    return 0;
}

