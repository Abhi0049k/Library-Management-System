#ifndef USER_H
#define USER_H

#include <vector>
#include <string>
#include "Book.h"

class User
{
public:
    int id, age;
    std::string name;
    std::vector<Book *> borrowed_books;
    User(std::string n, int a, int i);
    void books_taken();
    void show_details();
};

#endif