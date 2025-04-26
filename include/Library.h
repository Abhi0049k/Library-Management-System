#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include "Book.h"
#include "User.h"

class Library
{
public:
    std::string name, owner;
    std::vector<Book *> book_available;
    Library(std::string n, std::string o);
    std::vector<User *> users;
    void display_library_details();
    bool add_book();
    bool delete_book();
    void change_book_details();
    void adding_user();
    void list_all_books();
    void list_all_users();
    void find_user_by_id(int id);
    void find_book_by_id(int id);
    void issue_book();
    void return_book();
    User* find_user(int user_id);
    Book* find_book(int book_id);
    void increase_book_stock(int book_id);
};

#endif