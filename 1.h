#include<string>
using namespace std;
#pragma once

class Stationery {
    int id;
    string name;
    double price;
    int quantity;

public:
    Stationery(int _id = 0, string _n = " ", double _p = 0, int _q = 0);
    int getId() const; 
    string getName() const; 
    double getPrice() const; 
    int getQuantity() const;
    void setId(int _id);
    void setName(string name);
    void setPrice(double price);
    void setQuantity(int quantity);
    void nhaptt();
    void hienthitt() const; 
};      






