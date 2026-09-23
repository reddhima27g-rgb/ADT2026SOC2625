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



