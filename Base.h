#pragma once
#include <string>
#include <iostream>
using namespace std;
class Base
{
private:
	string last_name;
	string middle_name;
	string name;
public:
	Base()
	{
		last_name = "=";
		middle_name = "=";
		name = "=";
		cout << "Базовый класс создан!\n";
	}
	Base(int a) 
	{
		set_last_name();
		set_name();
		set_middle_name();
		cout << "Базовый класс создан!\n";
	}
	void set_last_name();
	void set_last_name(char* mas);
	void set_middle_name();
	void set_middle_name(char* mas);
	void set_name();
	void set_name(char* mas);

	string get_last_name();
	string get_middle_name();
	string get_name();
	virtual ~Base();
	virtual string Me() = 0;
	virtual string save_file() = 0;
	friend ostream& operator << (ostream& out, Base& object);
	
};

