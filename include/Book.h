#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

class Book
{
public:
    std::string title, author_name;
    std::vector<std::string> genres;
    int id, count, price;

    Book(std::string n, std::string an, const std::vector<std::string> &g, int i, int cnt, int price);
    bool edit_into(Book &book);
    void display_details();
};

#endif