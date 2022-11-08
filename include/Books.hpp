#pragma once

#include <string>
#include <iostream>
using namespace std;

class Books {
private:
    int id;
    string name;
    int total_quantity;
    int total_borrowed;
public:
    Books();
    Books(int id, string name, int totalQuantity);
    int getId() const;
    const string &getName() const;
    int getTotalQuantity() const;
    int getTotalBorrowed() const;
    void read();
    bool borrow();
    void return_copy();
    bool has_prefix(string prefix);
    void print() const;

};