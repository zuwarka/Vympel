#include "Vector.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

Vector::Vector() : x(0.0), y(0.0), z(0.0) {}
Vector::~Vector() {}
Vector::Vector(const Vector& Vector_copy)
{
	this->x = Vector_copy.x;
	this->y = Vector_copy.y;
	this->z = Vector_copy.z;
}

Vector::Vector(long double x, long double y, long double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

long double Vector::get_x() const { return x; }
long double Vector::get_y() const { return y; }
long double Vector::get_z() const { return z; }
void Vector::set_x(long double& value) { x = value; }
void Vector::set_y(long double& value) { y = value; }
void Vector::set_z(long double& value) { z = value; }
long double Vector::length() const
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

long double operator* (const Vector& l_op, const Vector& r_op) //скалярное проиведение
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

std::ostream& operator<< (std::ostream& out, const Vector& vector)
{
	out << fixed << setprecision(10) << vector.get_x() << "; " << fixed << setprecision(10) << vector.get_y() << "; " << fixed << setprecision(10) << vector.get_z();
	return out;
}
