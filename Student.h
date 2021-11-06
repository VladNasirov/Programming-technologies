#pragma once
#include "Base.h"
class Student : public Base

{
private:
	string group_name;
	string speciality;
	int course;
	float average_score;
public:
	Student();
	Student(int a);

	void set_group_name();
	void set_speciality();
	void set_course();
	void set_average_score();

	void set_group_name(char* mas);
	void set_speciality(char* mas);
	void set_course(char* mas);
	void set_average_score(char* mas);

	string get_group_name();
	string get_speciality();
	int get_course();
	float get_average_score();
	string Me() override;
	string save_file() override;

	~Student();
	
	
	
};

