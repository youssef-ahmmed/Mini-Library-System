#pragma once

#include <iostream>
#include <string>
#include <set>
using namespace std;

class Users {
private:
    int id;
    string name;

    set<int> borrowed_books_ids;
public:
    Users();
    Users(int id, string name);
    const string &getName() const;
    void read();
    void borrow(int book_id);
    void return_copy(int book_id);
    bool is_borrowed(int book_id);
    void print();

};