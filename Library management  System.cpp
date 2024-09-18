#include <iostream>
#include <fstream>
using namespace std;

class Library {
    string id, name, author, search;
    fstream file;

public:
    void addBook();
    void showAll();
    void extractBook();
};

void Library::addBook() {
    cout << "Enter Book ID: ";
    cin >> id;
    cout << "Enter Book Name: ";
    cin >> name;
    cout << "Enter Book's Author Name: ";
    cin >> author;

    file.open("bookData.txt", ios::out | ios::app);
    if (!file) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }
    file << id << "*" << name << "*" << author << endl;
    file.close();
}

void Library::showAll() {
    file.open("bookData.txt", ios::in);
    if (!file) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    cout << "\n";
    cout << "Book ID \t\t Book Name \t\t Author's Name" << endl;
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author)) {
        cout << id << "\t\t\t" << name << "\t\t\t" << author << endl;
    }
    file.close();
}

void Library::extractBook() {
    cout << "Enter Book ID to extract: ";
    cin >> search;

    file.open("bookData.txt", ios::in);
    if (!file) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    bool found = false;
    cout << "Book ID \t\t Book Name \t\t Author's Name" << endl;
    while (getline(file, id, '*') && getline(file, name, '*') && getline(file, author)) {
        if (search == id) {
            cout << id << "\t\t\t" << name << "\t\t\t" << author << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
    file.close();
}

int main() {
    Library obj;
    char choice;

    do {
        cout << "----------------------------------" << endl;
        cout << "1 - Show All Books" << endl;
        cout << "2 - Extract Book" << endl;
        cout << "3 - Add Books (ADMIN)" << endl;
        cout << "4 - Exit" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                obj.showAll();
                break;
            case '2':
                obj.extractBook();
                break;
            case '3':
                obj.addBook();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid Choice!" << endl;
        }
    } while (choice != '4');

    return 0;
}
