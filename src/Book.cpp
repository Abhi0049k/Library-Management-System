#include "Book.h"

#include <iostream>
#include <iomanip>

Book::Book(std::string n, std::string an, const std::vector<std::string> &g, int i, int cnt, int p) : title(n), author_name(an), genres(g), id(i), count(cnt), price(p) {};

bool Book::edit_into(Book &updated)
{
    if (updated.title.empty() || updated.author_name.empty())
    {
        std::cout << "Error: Name and Author fields cannot be empty.\n";
        return false;
    }

    if (updated.count < 0 || updated.price < 0)
    {
        std::cout << "Error: Count and Price must be non-negative.\n";
        return false;
    }

    if (updated.genres.empty())
    {
        std::cout << "Error: At least one genre must be specified.\n";
        return false;
    }

    title = updated.title;
    author_name = updated.author_name;
    genres = updated.genres;
    count = updated.count;
    price = updated.price;

    return true;
}

void Book::display_details()
{
    std::cout << "================= Book Details =================" << std::endl;
    std::cout << std::left;
    std::cout << std::setw(15) << "ID:" << id << std::endl;
    std::cout << std::setw(15) << "Name:" << title << std::endl;
    std::cout << std::setw(15) << "Author:" << author_name << std::endl;
    std::cout << std::setw(15) << "Genres:";

    for (const auto &el : genres)
    {
        std::cout << el;
        if (&el != &genres.back())
            std::cout << ", ";
    }

    std::cout << '\n';
    std::cout << std::setw(15) << "Book Count:" << count << std::endl;
    std::cout << "================================================" << std::endl;
}