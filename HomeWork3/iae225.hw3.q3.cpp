#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;

    cout << "Enter coefficient a: ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter coefficient c: ";
    cin >> c;

    if (a == 0 && b == 0 && c == 0) {
        cout << "Infinite number of solutions" << endl;
    }

    else if (a == 0 && b == 0) {
        cout << "No solution" << endl;
    }

    else if (a == 0) {
        cout << "No real solution" << endl;
    } else {
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Two real solutions: x1 = " << x1 << ", x2 = " << x2 << endl;
        }

        else if (discriminant == 0) {
            double x = -b / (2 * a);
            cout << "One real solution: x = " << x << endl;
        }

        else {
            cout << "No real solution" << endl;
        }
    }

    return 0;
}
