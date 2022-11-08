
#include "Books.hpp"

Books::Books() {
    total_quantity = total_borrowed = 0;
    id = -1;
    name = "";
}

Books::Books(int id, string name, int totalQuantity) : id(id), name(std::move(name)),
                                                       total_quantity(totalQuantity),
                                                       total_borrowed(0) { }

int Books::getId() const {
    return id;
}

const string &Books::getName() const {
    return name;
}

int Books::getTotalQuantity() const {
    return total_quantity;
}

int Books::getTotalBorrowed() const {
    return total_borrowed;
}

void Books::read() {
    cout << "Enter book info: id & name & total quantity: ";
    cin >> id >> name >> total_quantity;
    Books(id,name,total_quantity);
}

bool Books::borrow() {
    if (getTotalQuantity() == 0) {
        return false;
    }
    --total_quantity;
    ++total_borrowed;
    return true;
}

void Books::return_copy() {
    --total_borrowed;
    ++total_quantity;
}

bool Books::has_prefix(string prefix) {
    if (name.size() < prefix.size())
        return false;

    for (int i = 0; i < (int) prefix.size(); ++i) {
        if (prefix[i] != name[i])
            return false;
    }
    return true;
}

void Books::print() const {
    cout << "id = " << id << " , name = " << name << " , total_quantity = " << total_quantity << " , total_borrowed = "
         << total_borrowed << "\n";
}
