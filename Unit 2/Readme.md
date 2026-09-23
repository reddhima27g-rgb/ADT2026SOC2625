4)Employee Class with Constructors:

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee {
private:
    int empId;
    string name;
    float basicSalary;
    float bonus;
    float totalSalary;

public:
    Employee()
        : empId(0), name("Unknown"), basicSalary(0),
          bonus(0), totalSalary(0) {
        cout << "Default constructor called" << endl;
    }

    Employee(int id, const string& n, float salary, float b)
        : empId(id), name(n), basicSalary(salary), bonus(b) {
        calculateTotalSalary();
        cout << "Parameterized constructor called" << endl;
    }

    void calculateTotalSalary() {
        totalSalary = basicSalary + bonus;
    }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "Employee ID: " << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << totalSalary << endl;
    }
};

int main() {
    Employee e1;
    cout << "\nDefault Employee:\n";
    e1.display();

    cout << "\nParameterized Employee:\n";
    Employee e2(101, "Rahul", 30000, 5000);
    e2.display();

    return 0;
}



5)Book Class with Copy Constructor:

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    float price;
    static int bookCount;

public:
    Book(int id, const string& t, const string& a, float p)
        : bookId(id), title(t), author(a), price(p) {
        ++bookCount;
        cout << "Book created. Total books: " << bookCount << endl;
    }

    Book(const Book& other)
        : bookId(other.bookId),
          title(other.title),
          author(other.author),
          price(other.price) {
        ++bookCount;
        cout << "Book copied. Total books: " << bookCount << endl;
    }

    ~Book() {
        --bookCount;
        cout << "Book destroyed. Total books: " << bookCount << endl;
    }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }

    static int getBookCount() {
        return bookCount;
    }
};

int Book::bookCount = 0;

int main() {
    Book b1(101, "C++ Programming", "Bjarne Stroustrup", 4500);
    b1.display();

    cout << endl;

    Book b2(b1);
    b2.display();

    cout << "\nTotal books: " << Book::getBookCount() << endl;

    return 0;
}


