1)Student Class with Details And Result Calculation:

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    float marks[3];
    float total;
    float percentage;
    string result;

public:
    void acceptDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);





2)Rectangle Class with Member Functions
Objective:

#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float breadth;

public:
    void setDimensions(float l, float b) {
        length = l;
        breadth = b;
    }

    float calculateArea();
    float calculatePerimeter();
    void display();
};

float Rectangle::calculateArea() {
    return length * breadth;
}

float Rectangle::calculatePerimeter() {
    return 2 * (length + breadth);
}

void Rectangle::display() {
    cout << "Length: " << length << endl;
    cout << "Breadth: " << breadth << endl;
    cout << "Area: " << calculateArea() << endl;
    cout << "Perimeter: " << calculatePerimeter() << endl;
}

int main() {
    Rectangle rect;
    float l, b;

    cout << "Enter length and breadth: ";
    cin >> l >> b;

    rect.setDimensions(l, b);
    rect.display();

    return 0;
}


        cout << "Enter marks for 3 subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }

    void calculateResult() {
        total = 0;
        for (int i = 0; i < 3; i++) {
            total += marks[i];
        }

        percentage = total / 3.0f;

        if (percentage >= 40)
            result = "Pass";
        else
            result = "Fail";
    }

    void display() const {
        cout << "\n--- Student Details ---\n";
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;

        cout << fixed << setprecision(2);
        cout << "Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;

        cout << "Total: " << total << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Result: " << result << endl;
    }
};

int main() {
    Student s;
    s.acceptDetails();
    s.calculateResult();
    s.display();

    return 0;
}


3)Product Class with Array of Objects:

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Product {
private:
    int productId;
    string productName;
    float price;
    int monthlySales[12];
    int totalQuantity;
    float totalBill;

public:
    void acceptDetails() {
        cout << "Enter Product ID: ";
        cin >> productId;
        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, productName);

        cout << "Enter Price per unit: ";
        cin >> price;

        cout << "Enter monthly sales for 12 months: ";
        totalQuantity = 0;

        for (int i = 0; i < 12; i++) {
            cin >> monthlySales[i];
            totalQuantity += monthlySales[i];
        }

        totalBill = totalQuantity * price;
    }

    void display() const {
        cout << "\n--- Product Details ---\n";
        cout << "Product ID: " << productId << endl;
        cout << "Product Name: " << productName << endl;
        cout << fixed << setprecision(2);
        cout << "Price per unit: " << price << endl;
        cout << "Total Quantity Sold: " << totalQuantity << endl;
        cout << "Total Bill: " << totalBill << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of products: ";
    cin >> n;

    Product products[10];

    if (n < 1 || n > 10) {
        cout << "Invalid number of products." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Product " << i + 1 << ":\n";
        products[i].acceptDetails();
    }

    for (int i = 0; i < n; i++) {
        products[i].display();
    }

    return 0;
}


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



