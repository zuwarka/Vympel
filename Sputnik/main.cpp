//��� ��������� �������� �����. ��������� ������ ������� ������. �� ������: ���������.

#include <iostream>
#include "Vector.h"
#include "gauss_counting.h"
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

//��������� �� �������
//const double k = 0.07436574; //����������, ������ ����� ������������ �������������� ���������� �� ����� ����� (�.�/���)
//const double pi = 3.14159265;
//const double mu = 1.000952348;

int main()
{
	//-----------------------------------------------------------����������
	double value; //��, ���� �� ������
	double t1, t2; //������� ���������� �������
	Vector r1_vec, r2_vec, r_res; //������-������� ��������� ��������
	/*
	double r1 = r1_vec.length(); //�������� ����� ������� r1
	double r2 = r2_vec.length(); //�������� ����� ������� r2
	double fi; //fi = u2 - u1. ��� ���� ��������
	double l, m, f, g; //���������� ������������ ���������
	*/
	string basefile = "data.txt"; //���� � �������
	ifstream infile; //������ �� �����
	ofstream outfile; //������ � ����
	//-----------------------------------------------------------����������

	int c;
	cout << "Gauss method for finding orbit - console version" << endl;
	cout << "How you going to input data?" << endl;
	cout << "1 - Manually" << endl;
	cout << "2 - From file" << endl;
	cout << "0 - Exit" << endl;
	cout << "-> ";
	cin >> c;

	switch (c)
	{
	case 1: //�������
		system("cls");
		cout << "Input your values:" << endl;

		cout << "\tvector r1:\tx = ";
		cin >> value;
		r1_vec.set_x(value);
		cout << "\n\t          \ty = ";
		cin >> value;
		r1_vec.set_y(value);
		cout << "\n\t          \tz = ";
		cin >> value;
		r1_vec.set_z(value);

		cout << "\tvector r2:\tx = ";
		cin >> value;
		r2_vec.set_x(value);
		cout << "\n\t          \ty = ";
		cin >> value;
		r2_vec.set_y(value);
		cout << "\n\t          \tz = ";
		cin >> value;
		r2_vec.set_z(value);

		cout << "\n\ttime for vector r1:\tt1 = ";
		cin >> t1;
		cout << "\n\ttime for vector r2:\tt1 = ";
		cin >> t2;

		r_res = gauss_counting(r1_vec, r2_vec, t1, t2);
		break;
	case 2: //�� �����
		system("cls");
		infile.open(basefile);
		if (!infile)
		{
			cout << "������ �������� �����!" << endl;
			exit(1);
		}
		//infile >> x_str >> k_str >> b_str >> x_ell >> a_ell >> b_ell >> x_hyp >> k_hyp >> b_hyp;
		infile.close();
		break;	
	case 0:
		exit(0);
		break;
	default:
		break;
	}


	return 0;
}