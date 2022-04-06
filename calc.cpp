#include <stdexcept>
#include <limits>
#include <string>
#include <iostream>
using namespace std;

void error (const char* message) {
    cout << message << endl ;
    exit(1);
}

int main() {
    cout << "Please enter expression (we can handle +, -, *, /): ";

    int lval = 0;
    int rval;
    char op;
    cin >> lval;

    if (!cin) error("no first operand");
    while (cin >> op) {
        cin >> rval;
        if (!cin) error("no second operand");
        switch (op) {
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;
                break;
            case '/':
                lval /= rval;
                break;
            default:
                cout << "Result: " << lval << endl;
                return 0;
        }
    }
    return 0;
}