#include "Base.h"
void Base::set_last_name()
{
	cout << "¬ведите фамилию человека:\n";
	cin.ignore(32767, '\n');
	cin >> last_name;
	
}

void Base::set_middle_name()
{
	cout << "¬ведите отчество человека:\n";
	cin.ignore(32767, '\n');
	cin >> middle_name;
}

void Base::set_name()
{
	cout << "¬ведите им€ человека:\n";
	cin.ignore(32767, '\n');
	cin >> name;
}

void Base::set_last_name(char* mas)
{
	last_name = (string)mas;
}
void Base::set_middle_name(char* mas)
{
	middle_name = (string)mas;
}
void Base::set_name(char* mas)
{
	name = (string)mas;
}

string Base::get_last_name()
{
	return last_name;
}

string Base::get_middle_name()
{
	return middle_name;
}

string Base::get_name()
{
	return name;
}

Base::~Base()
{
	cout << "Ѕазовый класс удален!\n";
}
ostream& operator << (ostream& out, Base& object)
{
	out << object.Me();
	return out;
}