#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Rectangle {
private:
    double diagonal;
    double angle;
    string color;

public:
    void fill() {
        cout << "diagonal: ";
        cin >> diagonal;
        if (cin.fail() || diagonal <= 0) {
            throw invalid_argument("Invalid input for diagonal");
        }

        cout << "angle: ";
        cin >> angle;
        if (cin.fail() || angle <= 0 || angle >= 180) {
            throw invalid_argument("Invalid input for angle");
        }

        cout << "color: ";
        cin >> color;
        if (cin.fail()) {
            throw invalid_argument("Invalid input for color");
        }
    }

    void calculate() {
        double area = 0.5 * pow(diagonal, 2) * sin(angle * M_PI / 180);
        cout << left << setw(12) << setfill('*') << setprecision(3) << area << endl;
    }
};

int main() {
    try {
        Rectangle rect;
        rect.fill();
        rect.calculate();
    } catch (invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
