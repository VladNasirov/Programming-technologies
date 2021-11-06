#include "Base.h"
#include "singly_linked_list.h"
#pragma once
class adm : public Base
{
private:
	string position;
	string telephone;
	singly_linked_list responsibilty;
public:
	adm();
	adm(int a);
	void set_position();
	void set_position(char* mas);
	string get_position();
	void set_telephone();
	void set_telephone(char* mas);
	string get_telephone();
	void add_responsibility();
	void add_responsibility(char* mas);
	void show_responsibility();
	void remove_responsibility();
	void edit_responsibility();
	void remove_all_responsibility();
	string Me() override;
	string save_file() override;
	~adm();
};

