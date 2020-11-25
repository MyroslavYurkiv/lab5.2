#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);
int main()
{
	setlocale(LC_ALL, "Russian");
	double xp, xk, x, dx, eps, s = 0;
	int n = 0;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "--------------------------------------------------------" << endl;
	cout << "|" << setw(5) << "Обчислення суми ряду Тейлора	за допомогою функцiй" << setw(4) << " |" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "|" << setw(5) << "Лабораторна №5.2" << setw(39) << " |" << endl;
	cout << "|" << setw(5) << "Юркiв Мирослав" << setw(41) << " |" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "|" << setw(3) << "x" << setw(9) << " |"
		<< setw(8) << "arcth(x)" << setw(9) << " |"
		<< setw(7) << "S" << setw(9) << " |"
		<< setw(1) << "n" << setw(9) << " |"
		<< endl;
	cout << "--------------------------------------------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		S(x, eps, n, s);
		cout << "|" << setw(10) << setprecision(2) << x << " |"
			<< setw(15) << setprecision(5) << atanh(1 / x) << " |"
			<< setw(14) << setprecision(5) << s << " |"
			<< setw(8) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "--------------------------------------------------------" << endl;
	return 0;
}
void S(const double x, const double eps, int& n, double& s)
{
	n = 0; // вираз залежить від умови завдання варіанту
	double a = 1/x; // вираз залежить від умови завдання варіанту
	s = a;
	do {
		n++;
		A(x, n, a);
		s += a;
	} while (abs(a) >= eps);
}

void A(const double x, const int n, double& a)
{
	double R = (2 * n - 1) / ((2 * n + 1) * pow(x, 2)); // вираз залежить від умови завдання варіанту
	a *= R;
}