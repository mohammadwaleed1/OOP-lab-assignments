#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;

    Book(string title, string author, string isbn)
        : title(title), author(author), isbn(isbn) {}
};

class Catalog {
private:
    vector<Book> books;  

public:
    // Adds a book to the catalog
    void addBook(const Book& book) {
        books.push_back(book); 
    }

    Book* findBookByISBN(const string& isbn) {
        for (size_t i = 0; i < books.size(); i++) { 
            if (books[i].isbn == isbn) {
                return &books[i];  
            }
        }
        return nullptr; 
    }
};

class Library {
private:
    string name;
    string address;
    Catalog catalog;  
    vector<Book> books; 

public:
    Library(string name, string address)
        : name(name), address(address) {}

    void addBook(const Book& book) {
        books.push_back(book);
        catalog.addBook(book);  
    }

    void removeBook(const string& isbn) {
        for (size_t i = 0; i < books.size(); i++) {  
            if (books[i].isbn == isbn) {
                books.erase(books.begin() + i);
                break;
            }
        }
    }

    Book* findBookInCatalog(const string& isbn) {
        return catalog.findBookByISBN(isbn);
    }

    void displayLibraryInfo() {
        cout << "Library Name: " << name << endl;
        cout << "Library Address: " << address << endl;
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", "9780316769488");
    Book book2("1984", "George Orwell", "9780451524935");
    Book book3("Brave New World", "Aldous Huxley", "9780060850524");

    Library myLibrary("City Library", "123 Main St");

    myLibrary.addBook(book1);
    myLibrary.addBook(book2);
    myLibrary.addBook(book3);

    myLibrary.displayLibraryInfo();

    string isbnToSearch = "9780316769488";  
    Book* foundBook = myLibrary.findBookInCatalog(isbnToSearch);

    if (foundBook) {
        cout << "Found Book: " << foundBook->title << " by " << foundBook->author << endl;
    } else {
        cout << "Book with ISBN " << isbnToSearch << " not found." << endl;
    }

    myLibrary.removeBook("9780451524935"); 

    foundBook = myLibrary.findBookInCatalog("9780451524935");

    if (foundBook) {
        cout << "Found Book: " << foundBook->title << " by " << foundBook->author << endl;
    } else {
        cout << "Book with ISBN 9780451524935 not found." << endl;
    }

    return 0;
}
