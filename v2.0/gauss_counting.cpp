#pragma warning(suppress : 4834)
#include "gauss_counting.h"
#include "Vector.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

const long double k = 0.07436574; //����������, ������ ����� ������������ �������������� ���������� �� ����� ����� (�.�/���)
const long double pi = 3.14159265;
const long double mu = 1.000952348;

//const double N = 2;

Vector gauss_counting(Vector& r1_vec, Vector& r2_vec, long double& t1, long double& t2, long double N)
{
	clock_t cl;
	//---------------------------------------------------------------------------------------���� ����������
	Vector r_point; //������� ������ ��������� ������
	long double r1 = r1_vec.length(); //�������� ����� ������� r1
	long double r2 = r2_vec.length(); //�������� ����� ������� r2
	long double fi; //fi = u2 - u1. ��� ���� ��������
	long double l, m, f, g, a; //���������� ������������ ���������
	long double X = 1, x = 1, y = 1;
	long double eks_raz, denom, divisor; //E2 - E1 - �������� ��������������� ��������
	long double tau; //���������������� �����
	//---------------------------------------------------------------------------------------���� ����������

	//---------------------------------------------------------------------------------------���� ��������

	system_clock::time_point start = system_clock::now(); //������ ������� ��� ���������

	tau = k * (t2 - t1); 
	fi = acos((r1_vec * r2_vec) / (r1 * r2)); //fi = u2 - u1. ��� ���� ��������

	denom = r1 + r2;
	divisor = 4 * sqrt(r1 * r2) * cos(fi / 2);
	l = (denom / divisor) - 0.5;

	denom = mu * tau * tau;
	divisor = (2 * sqrt(r1 * r2) * cos(fi / 2)) * (2 * sqrt(r1 * r2) * cos(fi / 2)) * (2 * sqrt(r1 * r2) * cos(fi / 2));

	m = denom / divisor;

	for (int i = 1; i < N; i++)
	{
		x = m / (y * y) - l;
		
		x = abs(x); //��������:	��� ���������� ������ ����, � ����� ������ �� �����������
		
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
	//---------------------------------------------------------------------------------------���� ��������
	system_clock::time_point end = system_clock::now(); //����� ��������� ������� ���������
	cout << "The time is: " << duration_cast<microseconds>(end - start).count() << " us" << endl;
	return r_point;
}

//��������
//1. ��� ��� ������ ��������� ����� ����� �������������, �������������, ����� �� ����� ���� ������� ����������� - ���(���)
//2. ���� ������ ������ (1; 1; 1), �� ���� ������ ���(���)