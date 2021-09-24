#pragma once
//Класс вектор. Реализовать: три точки, точка зед по умолчанию пусть будет равна нулю
//перегрузить сложение, вычитание, скалярное и векторное произведения. 

class r
{
private:
	double x, y, z; //three coordinates of radius-vector
public:
	r();
	~r();
	r(const r& r_copy);
	r(double x, double y, double z);

	double get_x() const;
	double get_y() const;
	double get_z() const;
	double set_x(double& value);
	double set_y(double& value);
	double set_z(double& value);

	friend r operator^ (const r& l_op, const r& r_op); //векторное произвеление
	friend r operator+ (const r& l_op, const r& r_op); //векторная сумма
	friend r operator- (const r& l_op, const r& r_op); //векторное вычитание
	friend double operator* (const r& l_op, const r& r_op); //скалярное проиведение
};