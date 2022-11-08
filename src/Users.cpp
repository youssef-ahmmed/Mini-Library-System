#include "Users.hpp"

Users::Users() {
    name = "";
    id = -1;
}

Users::Users(int id, string name) : id(id), name(std::move(name)) { }

const string &Users::getName() const {
    return name;
}

void Users::read() {
    cout << "Enter user name & national id: ";
    cin >> name >> id;
    Users(id,name);
}

void Users::borrow(int book_id) {
    borrowed_books_ids.insert(book_id);
}

void Users::return_copy(int book_id) {
    auto it = borrowed_books_ids.find(book_id);

    if (it != borrowed_books_ids.end())
        borrowed_books_ids.erase(it);
    else
        cout << "User " << name << " never borrowed book id " << book_id
             << "\n";
}

bool Users::is_borrowed(int book_id) {
    auto it = borrowed_books_ids.find(book_id);
    return it != borrowed_books_ids.end();
}

void Users::print() {
    cout << "user " << name << " id " << id << " borrowed books ids: ";
    for (int book_id : borrowed_books_ids)
        cout << book_id << " ";
    cout << "\n";
}
