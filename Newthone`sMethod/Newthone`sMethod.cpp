/*Родин Кирилл Денисович
ПТ-19-1*/

#include "stdafx.h"
#include <iostream>
#include "math.h"


using namespace std;

// function 1
double fun_1(double x) {
	double e = 2.71828; //e
	return pow(e, x) + (log(x) / log(e)) - 10 * x;
}

// derivative 1
double fun_der_1(double x) {
	double e = 2.71828; //e
	return pow(e, x) - (1 / pow(x, 2));
}

//function 2
double fun_2(double x) {
	return 3 * pow(log(x), 2) + 6 * log(x) - 5;
}

//derivative 2
double fun_der_2(double x) {
	return (6 * (log(x) + 1)) / x;
}

void newton(double eps, double x0, double(*fun)(double), double(*fun_der)(double)) {

	double e = 2.71828; //epsilon+
	double x = x0;
	int k = 0; // counter

	do {
		double func = fun(x);
		double func_der = fun_der(x);
		x0 = x;
		x = x - func / func_der;
		k++;
	} while (abs(x0 - x) > eps&& k < 10);

	cout << "A number of steps = " << k << endl;
	cout << "Answer is " << x << endl << endl;
}


int main()
{
	double eps = 0.0001; // approximation
	double x0;
	cout << "Enter 'x':" << endl;
	cin >> x0;
	double x = x0;

	double(*pfun1)(double) = fun_1;
	double(*pfunc_der1)(double) = fun_der_1;

	newton(eps, x0, pfun1, pfunc_der1);

	double(*pfun2)(double) = fun_2;
	double(*pfunc_der2)(double) = fun_der_2;
	newton(eps, x0, pfun2, pfunc_der2);


	system("pause");
	return 0;
}


