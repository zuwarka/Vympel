#pragma once
//����� ������. �����������: ��� �����, ����� ��� �� ��������� ����� ����� ����� ����
//����������� ��������, ���������, ��������� � ��������� ������������. 

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

	friend r operator^ (const r& l_op, const r& r_op); //��������� ������������
	friend r operator+ (const r& l_op, const r& r_op); //��������� �����
	friend r operator- (const r& l_op, const r& r_op); //��������� ���������
	friend double operator* (const r& l_op, const r& r_op); //��������� �����������
};