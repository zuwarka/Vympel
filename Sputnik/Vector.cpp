#include "Vector.h"
#include <cmath>
#include <iostream>

using namespace std;

Vector::Vector() : x(0.0), y(0.0), z(0.0) {}
Vector::~Vector() {}
Vector::Vector(const Vector& Vector_copy)
{
	this->x = Vector_copy.x;
	this->y = Vector_copy.y;
	this->z = Vector_copy.z;
}

Vector::Vector(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double Vector::get_x() const { return x; }
double Vector::get_y() const { return y; }
double Vector::get_z() const { return z; }
double Vector::set_x(double& value) { x = value; }
double Vector::set_y(double& value) { y = value; }
double Vector::set_z(double& value) { z = value; }
double Vector::length() const
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector operator+ (const Vector& l_op, const Vector& r_op) //векторная сумма
{
	return Vector(l_op.x + r_op.x, l_op.y + r_op.y, l_op.z + r_op.z);
}

Vector operator- (const Vector& l_op, const Vector& r_op) //векторное вычитание
{
	return Vector(l_op.x - r_op.x, l_op.y - r_op.y, l_op.z - r_op.z);
}

Vector operator^ (const double& num, const Vector& r_op) //умножение вектора на число
{
	return Vector(num * r_op.x, num * r_op.y, num * r_op.z);
}

double operator* (const Vector& l_op, const Vector& r_op) //скалярное проиведение
{
	return l_op.x * r_op.x + l_op.y * r_op.y + l_op.z * r_op.z;
}

Vector& Vector::operator= (const Vector& r)
{
	if (this == &r) //проерка на самоприсваивание
		return *this;
	x = r.x; 
	y = r.y; 
	z = r.z;
	return *this;

}