#include "gauss_counting.h"
#include "Vector.h"
#include <iostream>
#include <cmath>

const double k = 0.07436574; //постоянная, равная корню произведению графитационной постоянной на массу Земли (Э.Р/МИН)
const double pi = 3.14159265;
const double mu = 1.000952348;

const double N = 10;

Vector gauss_counting(Vector& r1_vec, Vector& r2_vec, double& t1, double& t2)
{
	//---------------------------------------------------------------------------------------БЛОК ПЕРЕМЕННЫХ
	Vector r_point; //искомый второй компонент орбиты
	double r1 = r1_vec.length(); //значение длины вектора r1
	double r2 = r2_vec.length(); //значение длины вектора r2
	double fi; //fi = u2 - u1. Это угол косинуса
	double l, m, f, g, a; //постоянные гауссовского уравнения
	double X, x, y = 1;
	double eks_raz, denom, divisor; //E2 - E1 - разность эксцентрических аномалий
	double tau; //модифицированное время
	//---------------------------------------------------------------------------------------БЛОК ПЕРЕМЕННЫХ

	//---------------------------------------------------------------------------------------БЛОК ПОДСЧЕТА
	tau = k * (t2 - t1); 
	fi = (r1_vec * r2_vec) / (r1 * r2); //fi = u2 - u1. Это угол косинуса
	l = ((r1 + r2) / (4 * sqrt(r1 * r2) * cos(fi / 2))) - 1 / 2;
	m = (mu * tau * tau) / pow((2 * sqrt(r1 * r2) * cos(fi / 2)), 3);

	for (int i = 1; i < N; i++)
	{
		x = m / (y * y) - l;
		eks_raz = asin((2 - 4 * x) * sqrt(4 * x * (1 - x)));
		denom = eks_raz - (2 - 4 * x) * sqrt(4 * x * (1 - x));
		divisor = pow((2 - 4 * x) * sqrt(4 * x * (1 - x)), 3);
		X = denom / divisor;
		y = 1 + X * (l + x);

		if (y >= N)
		{
			break;
		}
	}

	a = (tau * sqrt(mu)) / (2 * y * sqrt(r1 * r2) * cos(fi / 2) * sin(eks_raz / 2));
	pow(a, 2);
	f = 1 - (a / r1) * (1 - cos(eks_raz));
	g = tau - (pow(a, 1.5) / sqrt(mu)) * (eks_raz - sin(eks_raz));

	r_point = (1 / g) ^ (r2_vec - (f ^ r1_vec));
	//---------------------------------------------------------------------------------------БЛОК ПОДСЧЕТА
	return r_point;
}