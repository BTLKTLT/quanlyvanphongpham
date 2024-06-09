#include<string>
using namespace std;
#pragma once

class Stationery{
    int id;
    string name;
    double price;
    int quantity;
    static double amount;
    static int count;
    public:
        Stationery(int _id = 0,string _name = " ",double _price = 0,int _quantity = 0);
        ~Stationery();
        void changeStationery(int _id,string _name,double _price, int _quantity);
        void sortStationery();
        void searchStationery();
        static void billReceipt(int _id,string _name,double _price, int count);
};        






