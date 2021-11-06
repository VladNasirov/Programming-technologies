#include "Student.h"

void Student::set_group_name()
{
	cout << "������� � ������ ��������:\n";
	cin.ignore();
	getline(cin, group_name);
}

void Student::set_speciality()
{
	cout << "������� ����������� ������������� ��������:\n";
	cin.ignore();
	getline(cin, speciality);
}

void Student::set_course()
{
	cout << "������� �� ����� ����� ������ �������:\n";
	int buffer;
	do
	{
		cin >> buffer;
		if (buffer < 1 || buffer > 8)
		{
			cout << "������� �������� ��������!������� ��� ���!\n";

		}
	}
		while (buffer < 1 || buffer > 8);
	course = buffer;
}

void Student::set_average_score()
{
	cout << "������� ������� ���� ��������:\n";
	float buffer;
	do
	{
		cin >> buffer;
		if (buffer < 1 || buffer > 5)
		{
			cout << "������� �������� ��������!������� ��� ���!\n";
		}
	}
		while (buffer < 1 || buffer > 5);
	average_score = buffer;

}

void Student::set_group_name(char* mas)
{
	group_name = (string)mas;
}

void Student::set_speciality(char* mas)
{
	speciality = (string)mas;
}

void Student::set_course(char* mas)
{
	course = atoi(mas);
}

void Student::set_average_score(char* mas)
{
	average_score = atof(mas);
}

string Student::get_group_name()
{
	return group_name;
}

string Student::get_speciality()
{
	return speciality;
}

int Student::get_course()
{
	return course;
}

float Student::get_average_score()
{
	return average_score;
}
string Student::Me()
{
	return this->get_last_name() + " " + this->get_name() + " " + this->get_middle_name() + " " + group_name + " " + speciality + " " + to_string(course) + " " + to_string(average_score) + "\n";
}
string Student::save_file()
{
	return "Student@" + this->get_last_name() + "#" + this->get_name() + "#" + this->get_middle_name() + "#" + group_name + "#" + speciality + "#" + to_string(course) + "#" + to_string(average_score) + "\n";
}
Student::Student() : Base()
{

	group_name = "=";
	speciality = "=";
	course = 0;
	average_score = 0;
	cout << "������ ��� ��������� ������� ������!\n";

}
Student::Student(int a) : Base(1)
{

	set_course();
	set_speciality();
	set_group_name();
	set_average_score();
	cout << "������ ��� ��������� ������� ������!\n";
}
Student::	~Student()
{
	cout << "������ ��� ��������� ������� ������!\n";
}

