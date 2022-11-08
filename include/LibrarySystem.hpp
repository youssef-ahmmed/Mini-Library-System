#pragma once

#include <vector>
#include "Books.hpp"
#include "Users.hpp"
using namespace std;

class LibrarySystem {
private:
    vector<Books> books;
    vector<Users> users;
public:
    LibrarySystem() = default;
    void run();
    static void menu_list();
    static int menu();
    static bool cmp_book_by_name(Books &a, Books& b);
    static bool cmp_book_by_id(Books &a, Books& b);
    void add_book();
    void search_books_by_prefix();
    void print_who_borrowed_book_by_name();
    void add_user();
    int find_book_idx_by_name(const string& name);
    int find_user_idx_by_name(const string& name);
    bool read_user_name_and_book_name(int &user_idx, int &book_idx, int trials = 3);
    void user_borrow_book();
    void user_return_book();
    void print_library_by_id();
    void print_library_by_name();
    void print_users();

};