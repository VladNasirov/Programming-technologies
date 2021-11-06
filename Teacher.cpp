#include "Teacher.h"
string Teacher::Me()
{
	return this->get_last_name() + " " + this->get_name() + " " + this->get_middle_name() + " " + this->group_student.get_all_element() + " " + this->subjects.get_all_element() + '\n';
}
string Teacher::save_file()
{
	return "Teacher@" + this->get_last_name() + "#" + this->get_name() + "#" + this->get_middle_name() + "#" + this->group_student.get_all_element_save() + "#" + this->subjects.get_all_element_save() + '\n';
}
Teacher::Teacher() : Base()
{
	cout << "Объект учитель создан!\n";

}
Teacher::Teacher(int a) : Base(1)
{
	int cnt_group_student = 0;
	int cnt_subjects = 0;
	cout << "Сколько групп студентов ведет преподаватель?\n";
	do
	{
		cin >> cnt_group_student;
		if (cnt_group_student < 0 && cnt_group_student > 100)
		{
			cout << "Преподаватель не может вести столько групп!\nВведите еще раз!\n";
		}
	} while (cnt_group_student < 0 && cnt_group_student > 100);
	for (int i = 0; i != cnt_group_student; i++)
	{
		add_group();
	}
	cout << "Сколько предметов ведет преподаватель?\n";
	do
	{
		cin >> cnt_subjects;
		if (cnt_subjects < 0 && cnt_subjects > 50)
		{
			cout << "Преподаватель не может вести столько предметов!\nВведите еще раз!\n";
		}
	} while (cnt_subjects < 0 && cnt_subjects > 50);

	for (int i = 0; i != cnt_subjects; i++)
	{
		add_subject();
	}
	cout << "Объект учитель создан!\n";
}
void  Teacher::add_group()
{
	cout << "Введите номер группы:\n";
	group_student.add_element();
	cout << "Группа успешно добавлена!\n";
}
void  Teacher::add_subject()
{
	cout << "Введите абревиатуру предмета:\n";
	subjects.add_element();
	cout << "Предмет успешно добавлен!\n";
}

void  Teacher::add_group(char* mas)
{
	group_student.add_element(string(mas));
}

void  Teacher::add_subject(char* mas)
{
	subjects.add_element((string)mas);
}

void  Teacher::show_group_student()
{
	cout << "Список групп у преподавателя:\n";
	group_student.show();
}

void  Teacher::show_subjects()
{
	cout << "Список предметов у преподавателя:\n";
	subjects.show();
}

void  Teacher::remove_group()
{
	if (group_student.getCount() == 0)
	{
		cout << "У этого объекта нету групп студентов!\n";
	}
	else
	{
		cout << "У этого объекта всего " << group_student.getCount() << " групп студентов:\n";
		group_student.show();
		cout << "Какую группу будем удалять?\n";
		int pos;
		do {

			cin >> pos;
			if (pos < 0 || pos > group_student.getCount())
			{
				cout << "Выбрана неверная позиция!\n";
			}
		} while (pos < 0 || pos > group_student.getCount());
		group_student.remove_element(pos);
	}
}

void  Teacher::edit_group()
{
	if (group_student.getCount() == 0)
	{
		cout << "У этого объекта нету групп студентов !\n";
	}
	else
	{
		cout << "У этого объекта всего " << group_student.getCount() << " групп студентов:\n";
		group_student.show();
		cout << "Какую группу будем редактировать?\n";
		int pos;
		do {

			cin >> pos;
			if (pos < 0 || pos > group_student.getCount())
			{
				cout << "Выбрана неверная позиция!\n";
			}
		} while (pos < 0 || pos > group_student.getCount());
		group_student.edit_element(pos);
	}
}

void  Teacher::remove_subject()
{
	if (subjects.getCount() == 0)
	{
		cout << "У этого объекта нету предметов для преподавания!\n";
	}
	else
	{
		cout << "У этого объекта всего " << subjects.getCount() << " предметов преподавания:\n";
		subjects.show();
		cout << "Какой предмет будем удалять?\n";
		int pos;
		do {

			cin >> pos;
			if (pos < 0 || pos > subjects.getCount())
			{
				cout << "Выбрана неверная позиция!\n";
			}
		} while (pos < 0 || pos > subjects.getCount());
		subjects.remove_element(pos);
	}
}

void  Teacher::edit_subject()
{
	if (subjects.getCount() == 0)
	{
		cout << "У этого объекта нету предметов для преподавания!\n";
	}
	else
	{
		cout << "У этого объекта всего " << subjects.getCount() << " предметов преподавания:\n";
		subjects.show();
		cout << "Какой предмет будем редактировать?\n";
		int pos;
		do {

			cin >> pos;
			if (pos < 0 || pos > subjects.getCount())
			{
				cout << "Выбрана неверная позиция!\n";
			}
		} while (pos < 0 || pos > subjects.getCount());
		subjects.edit_element(pos);
	}
}

void  Teacher::remove_all_subjects()
{
	for (int i = 0; i != subjects.getCount(); i++)
	{
		subjects.remove_element(0);
	}
}
void  Teacher::remove_all_group()
{
	for (int i = 0; i != group_student.getCount(); i++)
	{
		group_student.remove_element(0);
	}
}
Teacher::~Teacher()
{
	cout << "Объект учитель удален!\n";
}
