#include "r.h"
#include <iostream>

using namespace std;

r::r() : x(0.0), y(0.0), z(0.0) {}
r::~r() {}
r::r(const r& r_copy)
{
	this->x = r_copy.x;
	this->y = r_copy.y;
	this->z = r_copy.z;
}

r::r(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double r::get_x() const { return x; }
double r::get_y() const { return y; }
double r::get_z() const { return z; }
double r::set_x(double& value) { x = value; }
double r::set_y(double& value) { y = value; }
double r::set_z(double& value) { z = value; }

r operator+ (const r& l_op, const r& r_op) //векторная сумма
{
	return r(l_op.x + r_op.x, l_op.y + r_op.y, l_op.z + r_op.z);
}

r operator- (const r& l_op, const r& r_op) //векторное вычитание
{
	return r(l_op.x - r_op.x, l_op.y - r_op.y, l_op.z - r_op.z);
}


r operator^ (const r& l_op, const r& r_op) //векторное произвеление
{
	//как записать векторное произведение с тремя координатами
}

double operator* (const r& l_op, const r& r_op) //скалярное проиведение
{
	return l_op.x * r_op.x + l_op.y * r_op.y + l_op.z * r_op.z;
}

