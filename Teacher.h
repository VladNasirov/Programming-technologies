#pragma once
#include "Base.h"
#include "singly_linked_list.h"
class Teacher : public Base
{
private:
	singly_linked_list group_student;
	singly_linked_list subjects;
public:
	Teacher();
	Teacher(int a);
	void add_group();
	void add_subject();
	void add_group(char* mas);

	void add_subject(char* mas);

	void show_group_student();

	void show_subjects();

	void remove_group();

	void edit_group();

	void remove_subject();

	void edit_subject();

	void remove_all_subjects();
	void remove_all_group();



	string Me() override;
	string save_file() override;
	~Teacher();
	

};

