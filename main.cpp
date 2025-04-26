// g++ -std=c++23 -Iinclude -o my_project main.cpp src\Book.cpp src\User.cpp src\Library.cpp
#include "Library.h"

#include <iostream>

int main()
{
    Library library("Central Library", "Admin");
    while (true)
    {
        std::cout << "\n=== Library Management System ===\n"
                  << "1. Add Book\n"
                  << "2. Delete Book\n"
                  << "3. Add User\n"
                  << "4. Change Book Details\n"
                  << "5. List All Books\n"
                  << "6. List All Users\n"
                  << "7. Find User by ID\n"
                  << "8. Find Book by ID\n"
                  << "9. Issue Book\n"
                  << "10. Return Book\n"
                  << "11. Increase Book Stock\n"
                  << "-1. Exit\n"
                  << "Enter choice: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (library.add_book())
                std::cout << "Book added successfully.\n";
            else
                std::cout << "Failed to add book.\n";
            break;
        }
        case 2:
        {
            if (library.delete_book())
                std::cout << "Book deleted successfully.\n";
            else
                std::cout << "Failed to delete book.\n";
            break;
        }
        case 3:
        {
            library.adding_user();
            break;
        }
        case 4:
        {
            library.change_book_details();
            break;
        }
        case 5:
        {
            library.list_all_books();
            break;
        }
        case 6:
        {
            library.list_all_users();
            break;
        }
        case 7:
        {
            std::cout << "Enter user ID: ";
            int uid;
            std::cin >> uid;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << "Invalid input. User ID must be a number.\n";
            }
            else
            {
                User *usr = library.find_user(uid);
                if (usr)
                {
                    usr->show_details(); // Assuming your User class already has a show_details() function
                }
                else
                {
                    std::cout << "User not found with ID: " << uid << std::endl;
                }
            }

            break;
        }
        case 8:
        {
            std::cout << "Enter book ID: ";
            int bid;
            std::cin >> bid;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << "Invalid input. Book ID must be a number.\n";
            }
            else
            {
                Book *book = library.find_book(bid);
                if (book)
                {
                    book->display_details(); // Assuming your User class already has a show_details() function
                }
                else
                {
                    std::cout << "Book not found with ID: " << bid << std::endl;
                }
            }

            break;
        }
        case 9:
        {
            library.issue_book();
            break;
        }
        case 10:
        {
            library.return_book();
            break;
        }
        case 11:
        {
            std::cout << "Enter Book ID: ";
            int bid;
            std::cin >> bid;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Book ID must be an integer.\n";
            }
            else
            {
                library.increase_book_stock(bid);
            }

            break;
        }
        case -1:
            std::cout << "Exiting. Goodbye!\n";
            return 0;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}