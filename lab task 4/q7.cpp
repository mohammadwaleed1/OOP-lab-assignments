#include <iostream>
using namespace std;
class Book {
private:
    string title;
    string author;
    double price;
    string publisher;
    int stock;

public:
    Book(string t,string a, double p,string pub, int s){
		title=t;
		author=a;
		price=p;
		publisher=pub; 
		stock=s;
}
    int isAvailable(string t,string a){
        if (title == t && author == a){
        	return 1;
		}
		return 0;
    }
    void displayDetails() const {
    cout << "Title: " << title << "\nAuthor: " << author<< "\nPrice: " << price << "\nPublisher: " << publisher<< "\nStock: " << stock <<endl;
    }
    
    void purchaseBook(int copies) {
        if (copies<=stock) {
            cout << "Total Cost: " << (copies * price) <<endl;
            stock -= copies;
        } else {
        cout << "Required copies not in stock." <<endl;
        }
    }
};

int main() {
    Book inventory[2] = {
        Book("TheGreat", "F.Scott", 10.99, "Scribner", 5),
        Book("1984", "George", 8.99, "Penguin", 10)
    };

    string searchTitle, searchAuthor;
    cout << "Enter book title: ";
    cin>>searchTitle;
    cout << "Enter author name: ";
    cin>>searchAuthor;

    int found = 0;
    for (int i = 0; i < 2; i++) {
        if (inventory[i].isAvailable(searchTitle, searchAuthor)) {
            found = 1;
            inventory[i].displayDetails();
            int copies;
            cout << "Enter number of copies required: ";
            cin >> copies;
            inventory[i].purchaseBook(copies);
        }
    }
    
    if (found==0) {
    cout << "Book not available in inventory." << std::endl;
    }

    return 0;
}
