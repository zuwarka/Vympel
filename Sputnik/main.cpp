//Два положения спутника Земли. Построить орбиту методом Гаусса. На выходе: параметры.

#include <iostream>
#include "Vector.h"
#include "gauss_counting.h"
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

//константы по условию
//const double k = 0.07436574; //постоянная, равная корню произведению графитационной постоянной на массу Земли (Э.Р/МИН)
//const double pi = 3.14159265;
//const double mu = 1.000952348;

int main()
{
	//-----------------------------------------------------------ПЕРЕМЕННЫЕ
	double value; //то, куда мы вводим
	double t1, t2; //моменты всемирного времени
	Vector r1_vec, r2_vec, r_res; //радиус-векторы положения спутника
	string basefile = "data.txt"; //файл с данными
	ifstream infile; //чтение из файла
	ofstream outfile; //запись в файл
	//-----------------------------------------------------------ПЕРЕМЕННЫЕ

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

		r_res = gauss_counting(r1_vec, r2_vec, t1, t2);
		break;
	case 2: //Из файла
		system("cls");
		infile.open(basefile);

		if (!infile)
		{
			cout << "Ошибка открытия файла!" << endl;
			exit(1);
		}


		infile.close();
		break;	
	case 0:
		exit(0);
		break;
	default:
		break;
	}

	system("pause");
	system("cls");
	cout << "The orbit has been founded!\n\nr1 = (" << r1_vec << "), r2 = (" << r_res << ")\n";
	return 0;
}
