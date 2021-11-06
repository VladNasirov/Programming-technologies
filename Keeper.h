#pragma once
#include "Student.h"
#include "adm.h"
#include "Teacher.h"
#include "Base.h"
#include <fstream>
#pragma warning(disable: 4996)
class Keeper
{
private:
	int size_student;
	int size_adm;
	int size_teacher;
	Student* value_student;
	adm* value_adm;
	Teacher* value_teacher;
public:
	Keeper();
	Keeper(int size);
	void add_student(Student* new_element, int pos);
	void add_teacher(Teacher* new_element, int pos);
	void add_adm(adm* new_element, int pos);
	void remove_student(int pos);
	void remove_teacher(int pos);
	void remove_adm(int pos);
	void resize_student(int newsize);
	void resize_teacher(int newsize);
	void resize_adm(int newsize);
	void reallocate_student(int newsize);
	void reallocate_teacher(int newsize);
	void reallocate_adm(int newsize);
	void remove_all_student();
	void remove_all_teacher();
	void remove_all_adm();
	int get_size_student();
	int get_size_teacher();
	int get_size_adm();
	void show_all_student();
	void show_all_teacher();
	void show_all_adm();
	Student* get_array_student();
	Teacher* get_array_teacher();
	adm* get_array_adm();
	Base& operator[](int pos);
	void save(const char* filename);
	void load(const char* filename);
};

