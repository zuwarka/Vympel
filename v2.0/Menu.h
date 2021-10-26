#pragma once
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

class Menu
{
private:
	long double value, N; //то, куда мы вводим; точность для у
	long double t1 = 0, t2 = 0; //моменты всемирного времени
	Vector r1_vec, r2_vec, r_res; //радиус-векторы положения спутника
public:
	void main_menu();
	int show_options_method();
	void manually();
	void from_file();
	int show_options_file();
	void add_new_values();
};
