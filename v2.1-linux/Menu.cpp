#include <iostream>
#include <iomanip>
#include "Vector.h"
#include "Menu.h"
#include "gauss_counting.h"
#include <cmath>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

void Menu::main_menu()
{
	switch (show_options_method())
	{
	case 1:
		manually();
		break;
	case 2:
		from_file();
		break;
	case 0:
		cout << "You type not 1 nor 2, so an exit was called. Click ENTER to exit." << endl;
		//system("pause");
		//system("clear");
		std::cin.ignore(32767, '\n');
		std::cin.get();
		exit(0);
		break;
	default:
		cout << "You type not 1 nor 2, so an exit was called. Click ENTER to exit." << endl;
		//system("pause");
		//system("clear");
		std::cin.ignore(32767, '\n');
		std::cin.get();
		exit(0);
		break;
	}

	//system("cls");
	system("clear");

	switch (show_options_file())
	{
	case 1:
		add_new_values();
		break;
	case 2:
		cout << "You have skipped this step." << endl;
		break;
	default:
		cout << "You have skipped this step." << endl;
		break;
	}

	system("clear");
	cout << "The orbit has been founded!\n\nr1 = (" << r1_vec << "),\nr2 = (" << r_res << ")\n";
	//system("pause");
	cout << "Click ENTER to continue" << endl;
	std::cin.ignore(32767, '\n');
	std::cin.get();
}

int Menu::show_options_method()
{
	int c; //счетчики
	cout << "Gauss method for finding orbit - console version" << endl;
	cout << "Instruction:" << endl;
	cout << "1. All values has real type!" << endl;
	cout << "2. Restriction on input of the real part of number - 10 symboles" << endl << endl;
	cout << "How you going to input data?" << endl;
	cout << " 1 - Manually" << endl;
	cout << " 2 - From file" << endl;
	cout << " 0 - Exit" << endl;
	cout << "-> ";
	cin >> c;
	return c;
}

void Menu::manually()
{
	system("clear");
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

	cout << "\n\tInput your accuracy (integer N) of Gauss-function: N = ";
	cin >> N;

	r_res = gauss_counting(r1_vec, r2_vec, t1, t2, N);
	cout << "Click ENTER to continue" << endl;
	//system("pause");
	std::cin.ignore(32767, '\n');
	std::cin.get();
}

void Menu::from_file()
{
	string basefile; //файл с данными
	ifstream infile; //чтение из файла
	ofstream outfile; //запись в файл

	cout << "Input file name: ";
	cin >> basefile;
	system("clear");

	infile.open(basefile);
	if (!infile)
	{
		cout << "Error opening! Click ENTER to exit" << endl;
		//system("pause");
		std::cin.ignore(32767, '\n');
		std::cin.get();
		exit(1);
	}
	else //проверка файла на пустоту
	{
		infile.seekg(0, ios::end);
		if (infile.tellg() == 0)
		{
			//fileWasEmpty = 1;
			cout << "The openning file is empty. Click ENTER to exit" << endl;
			//system("pause");
			std::cin.ignore(32767, '\n');
			std::cin.get();
			exit(0);
		}
		infile.close();
	}

	cout << "\n\tInput your accuracy (N) for iteration of Gauss-function: N = ";
	cin >> N;

	infile.open(basefile);
	if (!infile)
	{
		cout << "Error opening! Click ENTER to exit." << endl;
		//system("pause");
		std::cin.ignore(32767, '\n');
		std::cin.get();
		exit(1);
	}

	cout << "Getting values..." << endl;
	infile >> value;
	infile.ignore(32767, '\n');
	r1_vec.set_x(value);
	infile >> value;
	infile.ignore(32767, '\n');
	r1_vec.set_y(value);
	infile >> value;
	infile.ignore(32767, '\n');
	r1_vec.set_z(value);
	infile >> value;
	infile.ignore(32767, '\n');
	r2_vec.set_x(value);
	infile >> value;
	infile.ignore(32767, '\n');
	r2_vec.set_y(value);
	infile >> value;
	infile.ignore(32767, '\n');
	r2_vec.set_z(value);
	infile >> value;
	infile.ignore(32767, '\n');
	t1 = value;
	infile >> value;
	infile.ignore(32767, '\n');
	t2 = value;

	infile.close();

	r_res = gauss_counting(r1_vec, r2_vec, t1, t2, N);
	//system("pause");
	cout << "Click ENTER to continue" << endl;
	std::cin.ignore(32767, '\n');
	std::cin.get();
}

int Menu::show_options_file()
{
	int c;
	cout << "Would you like to rewrite values of radius-vectors to file?" << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - No (skip this step)" << endl;
	cout << "-> ";
	cin >> c;
	return c;
}

void Menu::add_new_values()
{
	int c;
	string basefile; //файл с данными
	ifstream infile; //чтение из файла
	ofstream outfile; //запись в файл
	cout << "Input file name: ";
	cin >> basefile;

	system("clear");
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
			cout << "Error opening! Click ENTER to exit" << endl;
			//system("pause");
			std::cin.ignore(32767, '\n');
			std::cin.get();
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
			cout << "Error opening! Click ENTER to exit." << endl;
			//system("pause");
			std::cin.ignore(32767, '\n');
			std::cin.get();
			exit(1);
		}

		outfile << r1_vec.get_x() << "\n" << r1_vec.get_y() << "\n" << r1_vec.get_z();
		outfile << "\n" << "\n" << r2_vec.get_x() << "\n" << r2_vec.get_y() << "\n" << r2_vec.get_z();
		outfile << "\n" << "\n" << t1 << "\n" << t2 << "\n";
		outfile.close();

		break;
	case 0:
		cout << "You have skipped this step." << endl;
		break;
	default:
		cout << "You have skipped this step." << endl;
		break;
	}
}
