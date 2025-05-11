#include <iostream>
using namespace std;

class Book {

    private:
        string title;
        float price;
    public:
        Book(string t, float p) : title(t), price(p) {}
        friend class Librarian;

};

class Librarian {
    public:
        void displayBookDetails(Book& b) {
            cout << "Displaying book details..." << endl << "Title: " << b.title << ", Price: " << b.price << endl; 
        }
        void applyBookDiscount(Book& b, float p) {
            if(p <= 100 && p > 0) {
                cout << "Applying "  << p << "% discount on Book " << b.title << "..." << endl;
                b.price = b.price * (100-p)/100;
            } else {
                cout << "Discount " << p << "% out of range!" << endl; 
            }
        }
};

int main() {
    Book b("BFG", 71.2);
    Librarian taha;
    taha.displayBookDetails(b);
    taha.applyBookDiscount(b, 25);
    taha.displayBookDetails(b);
}