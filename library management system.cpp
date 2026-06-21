#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    void addBook() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Author: ";
        getline(cin, author);

        issued = false;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: ";

        if (issued)
            cout << "Issued\n";
        else
            cout << "Available\n";
    }
};

int main() {
    Book books[100];

    int count = 0;
    int choice;

    do {
        cout << "\n\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Search by Title";
        cout << "\n6. Search by Author";
        cout << "\n0. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            books[count].addBook();
            count++;
        }

        else if (choice == 2) {
            for (int i = 0; i < count; i++) {
                books[i].display();
            }
        }

        else if (choice == 3) {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (books[i].id == id) {
                    books[i].issued = true;
                    cout << "Book Issued";
                }
            }
        }

        else if (choice == 4) {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;

            for (int i = 0; i < count; i++) {
                if (books[i].id == id) {
                    books[i].issued = false;
                    cout << "Book Returned";
                }
            }
        }

        else if (choice == 5) {
            string search;
            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, search);

            for (int i = 0; i < count; i++) {
                if (books[i].title == search) {
                    books[i].display();
                }
            }
        }

        else if (choice == 6) {
            string search;
            cin.ignore();

            cout << "Enter Author: ";
            getline(cin, search);

            for (int i = 0; i < count; i++) {
                if (books[i].author == search) {
                    books[i].display();
                }
            }
        }

    } while (choice != 0);

    return 0;
}