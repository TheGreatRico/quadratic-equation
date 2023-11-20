#include <iostream> // cout, system("Pause") functions
using namespace std;
#define EPSILON 1.0e-10

int main() {
	// solve a*x*x + b*x + c = 0 for any (a, b, c)
	double a = 0.0, b = 0.0, c = 0.1, Re, Im, d, x1, x2;
	cout << "Solving ax^2 + bx + c = 0 for any a, b and c.\nInput a : ";
	cin >> a;
	cout << "Input b : ";
	cin >> b;
	cout << "Input c : ";
	cin >> c;
	cout << "The equations is:\n\n" << a << "*x^2 + " << b << "*x + " << c << " = 0" << endl << endl;

	if (fabs(a) < EPSILON) { // bx+c=0
		if (fabs(b) < EPSILON) { // c=0
			if (fabs(c) < EPSILON) { // 0=0
				cout << "Input numbers are lower then precision or simply zeros." << endl;
			}
			else { // c=0
				cout << "Constant " << c << " = 0, which is wrong. This is probably a typo or an input mistake." << endl;
			}
		}
		else if (fabs(c) < EPSILON){ // bx=0 ?????
			cout << "x = 0" << endl;
		}
		else { // bx+c=0
			x1 = (-c) / b;
			cout << "x = " << x1 << endl;
		}
	}
	else if (fabs(b) < EPSILON) { // ax^2+c=0
		if (fabs(c) < EPSILON) { // ax^2=0
			cout << "x = 0" << endl;
		}
		else { // ax^2+c=0
			x1 = (-c) / a;
			if (x1 > 0) {
				cout << "x1 =  " << sqrt(x1) << endl;
				cout << "x2 = -" << sqrt(x1) << endl;
			}
			else {
				cout << "x1 =  i" << sqrt(-x1) << endl;
				cout << "x1 = -i" << sqrt(-x1) << endl;
			}
		}
	}
	else if (fabs(c) < EPSILON) { // ax^2+bx=0
		x1 = (-b) / a;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = 0" << endl;
	}
	else { // ax^2+bx+c=0; (a,b,c) != 0:
		d = double(b * b - 4 * a * c);
		if (d > 0) {
			cout << "Answer according to classic 'school' formula:" << endl;
			x1 = double((-b) + sqrt(d)) / (2 * a);
			x2 = double((-b) - sqrt(d)) / (2 * a);
			cout << "x1 = " << x2 << endl;
			cout << "x2 = " << x1 << endl;
			int sign_b = b / fabs(b);
			x1 = (-b - sign_b * sqrt(d)) / (2 * a);
			x2 = c / (x1 * a);
			cout << "Formula that takes into account 'catastrophic cancellation' yields this result:" << endl;
			cout << "x1 = " << x1 << endl;
			cout << "x2 = " << x2 << endl;
		}
		else if (d < 0) {
			Re = (-b) / (2 * a);
			Im = (sqrt(-d)) / (2 * a);
			cout << "x1 = " << Re << " + i" << Im << endl;
			cout << "x2 = " << Re << " - i" << Im << endl;
		}
		else {
			x1 = (-b) / (2 * a); // = x2
			cout << "x1 = x2 = " << x1 << endl;
		}
	}

	system("Pause");
	return 1;
}