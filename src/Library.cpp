#include "Library.h"
#include "Book.h"
#include "User.h"

#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

Library::Library(std::string n, std::string o) : name(n), owner(o) {};

void Library::display_library_details()
{
    std::cout << "\n================= Library Details =================" << std::endl;
    std::cout << std::left;
    std::cout << std::setw(15) << "Library Name:" << name << std::endl;
    std::cout << std::setw(15) << "Owner:" << owner << std::endl;

    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Available Books:" << std::endl;

    if (book_available.empty())
    {
        std::cout << "  No books available in the library." << std::endl;
    }
    else
    {
        int index = 1;
        for (auto &el : book_available)
        {
            std::cout << "\n  Book #" << index++ << ":" << std::endl;
            el->display_details();
        }
    }

    std::cout << "====================================================" << std::endl;
}

bool Library::add_book()
{
    std::string n, a;
    int cnt, p;
    std::vector<std::string> g;

    std::cout << "Enter the name of the book:\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush input
    std::getline(std::cin, n);

    std::cout << "Enter the name of the Author:\n";
    std::getline(std::cin, a);

    std::cout << "Enter a genre one-by-one, or type 'exit' to finish:\n";
    while (true)
    {
        std::string gen;
        std::getline(std::cin, gen);
        if (gen == "exit")
            break;
        if (!gen.empty())
            g.push_back(gen);
    }

    std::cout << "Enter the count of the book:\n";
    std::cin >> cnt;

    std::cout << "Enter the price of the book:\n";
    std::cin >> p;

    book_available.push_back(new Book(n, a, g, book_available.size() + 1, cnt, p));
    std::cout << "New book added to the Library.\n";

    return true;
}

void Library::adding_user()
{
    std::string n;
    int a;
    std::cout << "Enter the name of the user:\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush leftover input
    std::getline(std::cin, n);                                          // properly read full name with spaces

    std::cout << "Enter the age of the user:\n";
    std::cin >> a;

    users.push_back(new User(n, a, users.size() + 1));
    std::cout << "User added successfully.\n";
}

bool Library::delete_book()
{
    int i;
    std::cout << "Enter the ID of the book to delete: ";
    std::cin >> i;

    auto it = std::find_if(book_available.begin(), book_available.end(),
                           [i](Book *book)
                           {
                               return book->id == i;
                           });

    if (it != book_available.end())
    {
        book_available.erase(it);
        std::cout << "Book with ID " << i << " has been deleted." << std::endl;
        return true;
    }
    else
    {
        std::cout << "No book found with ID " << i << "." << std::endl;
        return false;
    }
}

void Library::change_book_details()
{
    int search_id;
    std::cout << "Enter the ID of the book you want to edit: ";
    std::cin >> search_id;

    for (Book *book : book_available)
    {
        if (book->id == search_id)
        {
            Book updated = *book;

            int ch;
            std::cout << "What detail do you want to change?\n";
            std::cout << "1. Name\n2. Author Name\n3. Price\n4. Count\n5. Genre\n";
            std::cin >> ch;

            switch (ch)
            {
            case 1:
            {
                std::cout << "Enter new name: ";
                std::cin.ignore();
                std::getline(std::cin, updated.title);
                break;
            }
            case 2:
            {
                std::cout << "Enter new author name: ";
                std::cin.ignore();
                std::getline(std::cin, updated.author_name);
                break;
            }
            case 3:
            {
                std::cout << "Enter new price: ";
                std::cin >> updated.price;
                break;
            }
            case 4:
            {
                std::cout << "Enter new count: ";
                std::cin >> updated.count;
                break;
            }
            case 5:
            {
                std::cout << "Enter genres (type 'done' to finish):\n";
                std::vector<std::string> genres;
                std::string g;
                while (true)
                {
                    std::cin >> g;
                    if (g == "done")
                        break;
                    genres.push_back(g);
                }
                updated.genres = genres;
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
                return;
            }

            if (book->edit_into(updated))
            {
                book = &updated;
                std::cout << "Book updated successfully.\n";
            }
            else
            {
                std::cout << "Failed to update book. Invalid data.\n";
            }
            return;
        }
    }

    std::cout << "Book with ID " << search_id << " not found.\n";
}

void Library::list_all_books()
{
    if (book_available.empty())
    {
        std::cout << "No books are available in the library.\n";
        return;
    }

    std::cout << "Listing all available books:\n";
    for (auto el : book_available)
    {
        if (el)
            el->display_details();
        else
            std::cout << "Encountered a null book entry.\n";
    }
}

void Library::list_all_users()
{
    if (users.empty())
    {
        std::cout << "No users are currently registered in the library.\n";
        return;
    }

    std::cout << "Listing all users:\n";
    for (auto el : users)
    {
        if (el)
            el->show_details();
        else
            std::cout << "Encountered a null user entry.\n";
    }
}

User *Library::find_user(int user_id)
{
    auto it = std::find_if(
        users.begin(), users.end(),
        [user_id](User *u)
        { return u->id == user_id; });
    return (it != users.end()) ? *it : nullptr;
}

Book *Library::find_book(int book_id)
{
    auto book = std::find_if(
        book_available.begin(), book_available.end(),
        [book_id](Book *b)
        {
            return b->id == book_id;
        });
    return (book != book_available.end()) ? *book : nullptr;
}

void Library::issue_book()
{
    int book_id, id;

    std::cout << "Enter user ID: ";
    std::cin >> id;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input for user ID.\n";
        return;
    }

    User *usr = find_user(id);
    if (!usr)
    {
        std::cout << "User not found.\n";
        return;
    }

    std::cout << "Enter book ID: ";
    std::cin >> book_id;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input for book ID.\n";
        return;
    }

    for (auto el : book_available)
    {
        if (el->id == book_id)
        {
            if (el->count > 0)
            {
                el->count--;
                usr->borrowed_books.push_back(el);
                std::cout << "Book issued successfully to user " << usr->name << ".\n";
            }
            else
            {
                std::cout << "Book is currently not available.\n";
            }
            return;
        }
    }
    std::cout << "Book ID not found in library.\n";
}

void Library::increase_book_stock(int book_id)
{
    for (auto el : book_available)
    {
        if (el->id == book_id)
        {
            el->count++;
            return;
        }
    }
}

void Library::return_book()
{
    int i, book_id;
    std::cout << "Enter the user id: " << std::endl;
    std::cin >> i;
    User *usr = find_user(i);
    if (!usr)
    {
        std::cout << "User not found!" << std::endl;
        return;
    }
    std::cout << "Enter the book id: " << std::endl;
    std::cin >> book_id;
    Book *book = find_book(book_id);
    if (!book)
    {
        std::cout << "Book not Found!" << std::endl;
        return;
    }
    usr->borrowed_books.erase(
        std::remove(usr->borrowed_books.begin(),
                    usr->borrowed_books.end(), book),
        usr->borrowed_books.end());
    increase_book_stock(book_id);
}