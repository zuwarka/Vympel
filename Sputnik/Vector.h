#pragma once
//Класс вектор. Реализовать: три точки, точка зед по умолчанию пусть будет равна нулю
//перегрузить сложение, вычитание, скалярное и векторное произведения. 

class Vector
{
private:
	double x, y, z; //three coordinates of radius-vector
public:
	Vector();
	~Vector();
	Vector(const Vector& Vector_copy);
	Vector(double x, double y, double z);

	double get_x() const;
	double get_y() const;
	double get_z() const;
	double set_x(double& value);
	double set_y(double& value);
	double set_z(double& value);
	double length() const;

	Vector& operator= (const Vector& r);
	friend Vector operator^ (const double& num, const Vector& r_op); //умножение вектора на число
	friend Vector operator+ (const Vector& l_op, const Vector& r_op); //векторная сумма
	friend Vector operator- (const Vector& l_op, const Vector& r_op); //векторное вычитание
	friend double operator* (const Vector& l_op, const Vector& r_op); //скалярное проиведение
};