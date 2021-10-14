//Два положения спутника Земли. Построить орбиту методом Гаусса. На выходе: параметры.

#include <iostream>
#include <iomanip>
#include "Vector.h"
#include "gauss_counting.h"
#include <cmath>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

int main()
{
	//-----------------------------------------------------------ПЕРЕМЕННЫЕ
	long double value, N; //то, куда мы вводим; точность для у
	long double t1, t2; //моменты всемирного времени
	Vector r1_vec, r2_vec, r_res; //радиус-векторы положения спутника
	string basefile = "data.txt"; //файл с данными
	ifstream infile; //чтение из файла
	ofstream outfile; //запись в файл
	//-----------------------------------------------------------ПЕРЕМЕННЫЕ

	int c; //счетчики
	cout << "Gauss method for finding orbit - console version" << endl;
	cout << "How you going to input data?" << endl;
	cout << " 1 - Manually" << endl;
	cout << " 2 - From file" << endl;
	cout << " 0 - Exit" << endl;
	cout << "-> ";
	cin >> c;

	switch (c)
	{
	case 1: //Вручную
		system("cls");
		cout << "Input your values:" << endl;

		cout << "\tvector r1:\tx = ";
		cin >> value;
		r1_vec.set_x(value);
		cout << "\t          \ty = ";
		cin >> value;
		r1_vec.set_y(value);
		cout << "\t          \tz = ";
		cin >> value;
		r1_vec.set_z(value);

		cout << "\n\tvector r2:\tx = ";
		cin >> value;
		r2_vec.set_x(value);
		cout << "\t          \ty = ";
		cin >> value;
		r2_vec.set_y(value);
		cout << "\t          \tz = ";
		cin >> value;
		r2_vec.set_z(value);

		cout << "\n\ttime for vector r1:\tt1 = ";
		cin >> t1;
		cout << "\n\ttime for vector r2:\tt1 = ";
		cin >> t2;

		cout << "\n\tInput your accuracy (N) of Gauss-function: N = ";
		cin >> N;

		r_res = gauss_counting(r1_vec, r2_vec, t1, t2, N);
		system("pause");

		break;
	case 2: //Из файла
		system("cls");
		cout << "\n\tInput your accuracy (N) for iteration of Gauss-function: N = ";
		cin >> N;

		infile.open(basefile);

		if (!infile)
		{
			cout << "Error opening!" << endl;
			system("pause");
			exit(1);
		}

		cout << "Getting values..." << endl;
		infile >> value;
		r1_vec.set_x(value);
		infile >> value;
		r1_vec.set_y(value);
		infile >> value;
		r1_vec.set_z(value);
		infile >> value;
		r2_vec.set_x(value);
		infile >> value;
		r2_vec.set_y(value);
		infile >> value;
		r2_vec.set_z(value);
		infile >> value;
		t1 = value;
		infile >> value;
		t2 = value;

		infile.close();

		r_res = gauss_counting(r1_vec, r2_vec, t1, t2, N);
		system("pause");

		break;	
	case 0:
		exit(0);
		break;
	default:
		break;
	}

	system("cls");

	cout << "Would you like to rewrite values of radius-vectors to file?" << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - No (skip this step)" << endl;
	cout << "-> ";
	cin >> c;

	switch (c)
	{
	case 1:

		system("cls");
		cout << "Would you like to add new values or values inputting earlier?" << endl;
		cout << "1 - Add new values" << endl;
		cout << "2 - Add values inputting earlier" << endl;
		cout << "-> ";
		cin >> c;

		switch (c)
		{
		case 1:

			outfile.open(basefile);

			if (!outfile)
			{
				cout << "Error opening!" << endl;
				system("pause");
				exit(1);
			}

			cout << "Input your values:" << endl;

			cout << "\tvector r1:\tx = ";
			cin >> value;
			r1_vec.set_x(value);
			cout << "\t          \ty = ";
			cin >> value;
			r1_vec.set_y(value);
			cout << "\t          \tz = ";
			cin >> value;
			r1_vec.set_z(value);

			cout << "\n\tvector r2:\tx = ";
			cin >> value;
			r2_vec.set_x(value);
			cout << "\t          \ty = ";
			cin >> value;
			r2_vec.set_y(value);
			cout << "\t          \tz = ";
			cin >> value;
			r2_vec.set_z(value);

			cout << "\n\ttime for vector r1:\tt1 = ";
			cin >> t1;
			cout << "\n\ttime for vector r2:\tt1 = ";
			cin >> t2;

			outfile << r1_vec.get_x() << "\n" << r1_vec.get_y() << "\n" << r1_vec.get_z();
			outfile << "\n" << "\n" << r2_vec.get_x() << "\n" << r2_vec.get_y() << "\n" << r2_vec.get_z();
			outfile << "\n" << "\n" << t1 << "\n" << t2 << "\n";
			outfile.close();

			break;
		case 2:

			outfile.open(basefile);

			if (!outfile)
			{
				cout << "Error opening!" << endl;
				system("pause");
				exit(1);
			}

			outfile << r1_vec.get_x() << "\n" << r1_vec.get_y() << "\n" << r1_vec.get_z();
			outfile << "\n" << "\n" << r2_vec.get_x() << "\n" << r2_vec.get_y() << "\n" << r2_vec.get_z();
			outfile << "\n" << "\n" << t1 << "\n" << t2 << "\n";
			outfile.close();

			break;
		case 0:
			break;
		default:
			break;
		}

		break;
	case 2:
		break;
	default:
		break;
	}
	system("cls");
	cout << "The orbit has been founded!\n\nr1 = (" << r1_vec << "),\nr2 = (" << r_res << ")\n";
	system("pause");
	return 0;
}
