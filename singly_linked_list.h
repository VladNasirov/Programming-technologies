#pragma once
#include "Uzel.h"
#include <iostream>
using namespace std;
class singly_linked_list
{
private:
	Uzel* head;
	int cnt;

public:
	singly_linked_list()
	{
		head = nullptr;
		cnt = 0;
	}
	void add_element();
	void add_element(string mas);
	void remove_element(int i);
	void edit_element(int i);
	void show();
	string get_element(int i);
	string get_all_element();
	string get_all_element_save();
	int getCount();
	~singly_linked_list()
	{
		cout << "Объект список удален\n";
	}
};

