#include "LibrarySystem.hpp"
#include <algorithm>

void LibrarySystem::run() {
    menu_list();
    while (true) {
        int choice = menu();
        if (choice == 1)
            add_book();
        else if (choice == 2)
            search_books_by_prefix();
        else if (choice == 3)
            print_who_borrowed_book_by_name();
        else if (choice == 4)
            print_library_by_id();
        else if (choice == 5)
            print_library_by_name();
        else if (choice == 6)
            add_user();
        else if (choice == 7)
            user_borrow_book();
        else if (choice == 8)
            user_return_book();
        else if (choice == 9)
            print_users();
        else
            break;
    }
}

void LibrarySystem::menu_list() {
    cout << "Library menu:\n";
    cout << "1) add book\n";
    cout << "2) search books by prefix\n";
    cout << "3) print who borrowed book by name\n";
    cout << "4) print library by id\n";
    cout << "5) print library by name\n";
    cout << "6) add user\n";
    cout << "7) user borrow book\n";
    cout << "8) user return book\n";
    cout << "9) print users\n";
    cout << "10) Exit\n\n";
}

int LibrarySystem::menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "Enter your menu choices [1 - 10]: ";
        cin >> choice;
        if (!(1 <= choice && choice <= 10)) {
            cout << "Invalid input. Try again\n";
            choice = -1;
        }
    }
    return choice;
}

bool LibrarySystem::cmp_book_by_name(Books &a, Books &b) {
    return a.getName() < b.getName();
}

bool LibrarySystem::cmp_book_by_id(Books &a, Books &b) {
    return a.getId() < b.getId();
}

void LibrarySystem::add_book() {
    Books b;
    b.read();
    books.push_back(b);
}

void LibrarySystem::search_books_by_prefix() {
    cout << "Enter book name prefix: ";
    string prefix;
    cin >> prefix;

    int cnt = 0;
    for (Books &b : books) {
        if (b.has_prefix(prefix)) {
            cout << b.getName() << "\n";
            ++cnt;
        }
    }

    if (!cnt)
        cout << "No books with such prefix\n";
}

void LibrarySystem::print_who_borrowed_book_by_name() {
    string book_name;
    cout << "Enter book name: ";
    cin >> book_name;

    int book_idx = find_book_idx_by_name(book_name);

    if (book_idx == -1) {
        cout << "Invalid book name.\n";
        return;
    }
    int book_id = books[book_idx].getId();

    if (books[book_idx].getTotalBorrowed() == 0) {
        cout << "No borrowed copies\n";
        return;
    }

    for (Users &u : users) {
        if (u.is_borrowed(book_id))
            cout << u.getName() << "\n";
    }
}

void LibrarySystem::add_user() {
    Users u;
    u.read();
    users.push_back(u);
}

int LibrarySystem::find_book_idx_by_name(const string &name) {
    for (int i = 0; i < (int) books.size(); ++i) {
        if (name == books[i].getName())
            return i;
    }
    return -1;
}

int LibrarySystem::find_user_idx_by_name(const string &name) {
    for (int i = 0; i < (int) users.size(); ++i) {
        if (name == users[i].getName())
            return i;
    }
    return -1;
}

bool LibrarySystem::read_user_name_and_book_name(int &user_idx, int &book_idx, int trials) {
    string user_name;
    string book_name;

    while (trials--) {
        cout << "Enter user name and book name: ";
        cin >> user_name >> book_name;

        user_idx = find_user_idx_by_name(user_name);

        if (user_idx == -1) {
            cout << "Invalid user name. Try again\n";
            continue;
        }
        book_idx = find_book_idx_by_name(book_name);

        if (book_idx == -1) {
            cout << "Invalid book name. Try again\n";
            continue;
        }
        return true;
    }
    cout << "You did several trials! Try later.";
    return false;
}

void LibrarySystem::user_borrow_book() {
    int user_idx, book_idx;

    if (!read_user_name_and_book_name(user_idx, book_idx))
        return;

    int book_id = books[book_idx].getId();

    if (!books[book_idx].borrow())
        cout << "No more copies available right now\n";
    else
        users[user_idx].borrow(book_id);
}

void LibrarySystem::user_return_book() {
    int user_idx, book_idx;

    if (!read_user_name_and_book_name(user_idx, book_idx))
        return;

    int book_id = books[book_idx].getId();
    books[book_idx].return_copy();
    users[user_idx].return_copy(book_id);
}

void LibrarySystem::print_library_by_id() {
    sort(books.begin(), books.end(), cmp_book_by_id);

    cout << "\n";
    for (Books &b : books)
        b.print();
}

void LibrarySystem::print_library_by_name() {
    sort(books.begin(), books.end(), cmp_book_by_name);

    cout << "\n";
    for (Books &b : books)
        b.print();
}

void LibrarySystem::print_users() {
    cout << "\n";
    for (Users &u : users)
        u.print();
}