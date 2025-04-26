#include "User.h"
#include <string>
#include <iostream>

User::User(std::string n, int a, int i) : id(i), age(a), name(n) {};

void User::books_taken()
{
    for (auto book : borrowed_books)
    {
        book->display_details();
    }
};

void User::show_details()
{
    std::cout << "----- User Details -----" << std::endl;
    std::cout << "ID       : " << id << std::endl;
    std::cout << "Name     : " << name << std::endl;
    std::cout << "Age      : " << age << std::endl;
    std::cout << "Books Taken: " << std::endl;

    if (borrowed_books.empty())
    {
        std::cout << "  No books currently in reading list." << std::endl;
    }
    else
    {
        for (const auto &book : borrowed_books)
        {
            std::cout << "  - " << book->title << " by " << book->author_name << std::endl;
        }
    }
    std::cout << "------------------------" << std::endl;
}
