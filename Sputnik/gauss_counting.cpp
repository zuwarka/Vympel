#pragma warning(suppress : 4834)
#include "gauss_counting.h"
#include "Vector.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

const long double k = 0.07436574; //постоянная, равная корню произведению графитационной постоянной на массу Земли (Э.Р/МИН)
const long double pi = 3.14159265;
const long double mu = 1.000952348;

//const double N = 2;

Vector gauss_counting(Vector& r1_vec, Vector& r2_vec, long double& t1, long double& t2, long double N)
{
	clock_t cl;
	//---------------------------------------------------------------------------------------БЛОК ПЕРЕМЕННЫХ
	Vector r_point; //искомый второй компонент орбиты
	long double r1 = r1_vec.length(); //значение длины вектора r1
	long double r2 = r2_vec.length(); //значение длины вектора r2
	long double fi; //fi = u2 - u1. Это угол косинуса
	long double l, m, f, g, a; //постоянные гауссовского уравнения
	long double X = 1, x = 1, y = 1;
	long double eks_raz, denom, divisor; //E2 - E1 - разность эксцентрических аномалий
	long double tau; //модифицированное время
	//---------------------------------------------------------------------------------------БЛОК ПЕРЕМЕННЫХ

	//---------------------------------------------------------------------------------------БЛОК ПОДСЧЕТА

	system_clock::time_point start = system_clock::now(); //начало времени для алгоритма

	tau = k * (t2 - t1); 
	fi = acos((r1_vec * r2_vec) / (r1 * r2)); //fi = u2 - u1. Это угол косинуса

	denom = r1 + r2;
	divisor = 4 * sqrt(r1 * r2) * cos(fi / 2);
	l = (denom / divisor) - 0.5;

	denom = mu * tau * tau;
	divisor = (2 * sqrt(r1 * r2) * cos(fi / 2)) * (2 * sqrt(r1 * r2) * cos(fi / 2)) * (2 * sqrt(r1 * r2) * cos(fi / 2));

	m = denom / divisor;

	for (int i = 1; i < N; i++)
	{
		x = m / (y * y) - l;
		
		x = abs(x); //ПРОБЛЕМА:	икс получается меньше нуля, и корни дальше не извлекаются
		
		eks_raz = asin(2 * sqrt(4 * x * (1 - x))); //(E2-E1)
		denom = eks_raz - sin(eks_raz); //E2-E1-sin(E2-E1)
		divisor = pow(sqrt(4 * x * (1 - x)), 3);//sin^3((E2-E1)/2)
		X = denom / divisor;
		y = 1 + X * (l + x);

		if (y >= N)
		{
			break;
		}
	}

	a = (tau * sqrt(mu)) / (2 * y * sqrt(r1 * r2) * cos(fi / 2) * sqrt(4 * x * (1 - x)));
	pow(a, 2);
	f = 1 - (a / r1) * (1 - cos(eks_raz));
	g = tau - (pow(a, 1.5) / sqrt(mu)) * (eks_raz - sin(eks_raz));

	r_point = (1 / g) ^ (r2_vec - (f ^ r1_vec));
	//---------------------------------------------------------------------------------------БЛОК ПОДСЧЕТА
	system_clock::time_point end = system_clock::now(); //конец измерения времени алгоритма
	cout << "The time is: " << duration_cast<microseconds>(end - start).count() << " us" << endl;
	return r_point;
}

//ПРОБЛЕМЫ
//1. Икс при первом вхождении может стать отрицательным, следовательно, корни не могут быть найдены вещественно - нан(инд)
//2. Если второй вектор (1; 1; 1), то тоже выдает нан(инд)
