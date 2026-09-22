Student Class with Details and Result Calculation:

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

