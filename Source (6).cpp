#include "Teacher.h"
#include "Student.h"
#include "Keeper.h"
#include <locale.h>
#include <Windows.h>


void print_menu()
{
	cout << "1.Меню работы со студентами\n2.Меню работы с учителями\n3.Меню работы с административным персоналом\n4.Сохранение и загрузка\n5.Шифр Цезаря\n6.Выход из программы\n";
}
void Keeper_student(Keeper* test)
{
	int select_student;
	do
	{
		system("cls");
		cout << "1.Добавить студента\n2.Редактировать студента\n3.Удалить студента\n4.Распечатать всех студентов\n5.Выйти\n";
		cin >> select_student;
		if (select_student == 1)
		{
			Student* example = new Student(5);
			cout << "Сейчас в контейнере " << test->get_size_student() << " элементов\nВведите индекс по которому будет хрантся новый элемент\n";
			int index;
			do
			{
				cin >> index;
				if (index <= test->get_size_student())
				{
					test->add_student(example, index);
				}
				if (index > test->get_size_student())
				{
					test->resize_student(index);
					test->add_student(example, index);
				}
				if (index < 0)
				{
					cout << "Индекс не может быть отрицательным!\n";
				}
			}
				while (index < 0);
			cout << "Студент успешно добавлен!\n";	
			system("pause");
		}
		if (select_student == 2)
		{
			if (test->get_size_student() == 0)
			{
				cout << "Контейнер студентов пуст!\n";

			}
			else
			{
				cout << "Сейчас в контейнере хрантися " << test->get_size_student() << " элементов" << endl;
				test->show_all_student();
				cout << "Какой элемент будем редактировать?\n";
				int select_elm;
				do
				{
					cin >> select_elm;
					if (select_elm < 0 || select_elm > test->get_size_student() - 1)
					{
						cout << "Выбран неверный элемент!\n";
					}
				} while (select_elm < 0 || select_elm > test->get_size_student() - 1);
				cout << "Как будем редактировать?\n1.Полностью\n2.Частично\n";
				int select_edit;
				do
				{
					cin >> select_edit;
					if (select_edit == 1)
					{
						test->get_array_student()[select_elm].set_last_name();
						test->get_array_student()[select_elm].set_name();
						test->get_array_student()[select_elm].set_middle_name();
						test->get_array_student()[select_elm].set_group_name();
						test->get_array_student()[select_elm].set_speciality();
						test->get_array_student()[select_elm].set_course();
						test->get_array_student()[select_elm].set_average_score();
					}
					if (select_edit == 2)
					{
						cout << "Что будем изменять?\n1.Фамилию\n2.Имя\n3.Отчество\n4.Название группы\n5.Название специальности\n6.Курс\n7.Средний балл\n";
						int select_edit_partially;
						do
						{
							cin >> select_edit_partially;
							if (select_edit_partially == 1)
							{
								test->get_array_student()[select_elm].set_last_name();
							}
							if (select_edit_partially == 2)
							{
								test->get_array_student()[select_elm].set_name();
							}
							if (select_edit_partially == 3)
							{
								test->get_array_student()[select_elm].set_middle_name();
							}
							if (select_edit_partially == 4)
							{
								test->get_array_student()[select_elm].set_group_name();
							}
							if (select_edit_partially == 5)
							{
								test->get_array_student()[select_elm].set_speciality();
							}
							if (select_edit_partially == 6)
							{
								test->get_array_student()[select_elm].set_course();
							}
							if (select_edit_partially == 7)
							{
								test->get_array_student()[select_elm].set_average_score();
							}
							if (select_edit_partially != 1 && select_edit_partially != 2 && select_edit_partially != 3 && select_edit_partially != 4 && select_edit_partially != 5 && select_edit_partially != 6 && select_edit_partially != 7)
							{
								cout << "Выбран неверный пункт!\n";
							}
						} while (select_edit_partially != 1 && select_edit_partially != 2 && select_edit_partially != 3 && select_edit_partially != 4 && select_edit_partially != 5 && select_edit_partially != 6 && select_edit_partially != 7);
					}

					if (select_edit != 1 && select_edit != 2)
					{
						cout << "Выбрана неверная позиция!\n";
					}
				} while (select_edit != 1 && select_edit != 2);
				cout << "Элемент отредактирован!\n";
			}
			system("pause");
		}
		if (select_student == 3)
		{
			if (test->get_size_student() == 0)
			{
				cout << "Контейнер студентов пуст!\n";

			}
			else
			{
				cout << "Сейчас в контейнере хрантися " << test->get_size_student() << " элементов" << endl;
				test->show_all_student();
				cout << "Какой элемент будем удалять?\n";
				

				int select_remove_elm;
				do
				{
					cin >> select_remove_elm;
					if (select_remove_elm < 0 || select_remove_elm > test->get_size_student() - 1)
					{
						cout << "Выбран неверный элемент!\n";
					}
				} while (select_remove_elm < 0 || select_remove_elm > test->get_size_student() - 1);
				test->remove_student(select_remove_elm);
				cout << "Студент удален!\n";
			}
			system("pause");

		}

		if (select_student == 4)
		{
			if (test->get_size_student() == 0)
			{
				cout << "Контейнер студентов пуст!\n";

			}
			else
			{
				test->show_all_student();
			}
			system("pause");
		}
		if (select_student != 1 && select_student != 2 && select_student != 3 && select_student != 4 && select_student != 5)
		{
			cout << "Выбран неверный пункт!\n";
		}
	}
		while (select_student != 5);
}

void Keeper_teacher(Keeper* test)
{
	int select_teacher;
	do
	{
		system("cls");
		cout << "1.Добавить учителя\n2.Редактировать учителя\n3.Удалить учителя\n4.Распечатать всех учителей\n5.Выйти\n";
		cin >> select_teacher;
		if (select_teacher == 1)
		{
			Teacher* example = new Teacher(2);
			cout << "Сейчас в контейнере " << test->get_size_teacher() << " элементов\nВведите индекс по которому будет хрантся новый элемент\n";
			int index;
			do
			{
				cin >> index;
				if (index <= test->get_size_teacher())
				{
					test->add_teacher(example, index);
				}
				if (index > test->get_size_teacher())
				{
					test->resize_teacher(index);
					test->add_teacher(example, index);
				}
				if (index < 0)
				{
					cout << "Индекс не может быть отрицательным!\n";
				}
			} while (index < 0);
			cout << "Учитель успешно добавлен!\n";
			system("pause");
		}
		if (select_teacher == 2)
		{
			if (test->get_size_teacher() == 0)
			{
				cout << "Контейнер с учителями пуст!\n";
			}
			else
			{
				cout << "Сейчас в контейнере хрантися " << test->get_size_teacher() << " элементов" << endl;
				test->show_all_teacher();
				cout << "Какой элемент будем редактировать?\n";
				int select_elm;
				do
				{
					cin >> select_elm;
					if (select_elm < 0 || select_elm > test->get_size_teacher() - 1)
					{
						cout << "Выбран неверный элемент!\n";
					}
				} while (select_elm < 0 || select_elm > test->get_size_teacher() - 1);
				cout << "Как будем редактировать?\n1.Полностью\n2.Частично\n";
				int select_edit;
				do
				{
					cin >> select_edit;
					if (select_edit == 1)
					{
						test->get_array_teacher()[select_elm].set_last_name();
						test->get_array_teacher()[select_elm].set_name();
						test->get_array_teacher()[select_elm].set_middle_name();
						test->get_array_teacher()[select_elm].remove_all_group();
						test->get_array_teacher()[select_elm].remove_all_subjects();
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
							test->get_array_teacher()[select_elm].add_group();
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
							test->get_array_teacher()[select_elm].add_subject();
						}
					}
					if (select_edit == 2)
					{
						cout << "Что будем изменять?\n1.Фамилию\n2.Имя\n3.Отчество\n4.Группы преподавателя\n5.Предметы преподавателя\n";
						int select_edit_partially;
						do
						{
							cin >> select_edit_partially;
							if (select_edit_partially == 1)
							{
								test->get_array_teacher()[select_elm].set_last_name();
							}
							if (select_edit_partially == 2)
							{
								test->get_array_teacher()[select_elm].set_name();
							}
							if (select_edit_partially == 3)
							{
								test->get_array_teacher()[select_elm].set_middle_name();
							}
							if (select_edit_partially == 4)
							{
								test->get_array_teacher()[select_elm].edit_group();
							}
							if (select_edit_partially == 5)
							{
								test->get_array_teacher()[select_elm].edit_subject();
							}

							if (select_edit_partially != 1 && select_edit_partially != 2 && select_edit_partially != 3 && select_edit_partially != 4 && select_edit_partially != 5)
							{
								cout << "Выбран неверный пункт!\n";
							}
						} while (select_edit_partially != 1 && select_edit_partially != 2 && select_edit_partially != 3 && select_edit_partially != 4 && select_edit_partially != 5);
					}
					if (select_edit != 1 && select_edit != 2)
					{
						cout << "Выбрана неверная позиция!\n";
					}
				} while (select_edit != 1 && select_edit != 2);
				cout << "Элемент отредактирован!\n";
			}
			system("pause");
		}

		if (select_teacher == 3)
		{
			if (test->get_size_teacher() == 0)
			{
				cout << "Контейнер с учителями пуст!\n";
			}
			else
			{
				cout << "Сейчас в контейнере хрантися " << test->get_size_teacher() << " элементов" << endl;
				test->show_all_teacher();
				cout << "Какой элемент будем удалять?\n";
				int select_remove_elm;
				do
				{
					cin >> select_remove_elm;
					if (select_remove_elm < 0 || select_remove_elm > test->get_size_teacher() - 1)
					{
						cout << "Выбран неверный элемент!\n";
					}
				} while (select_remove_elm < 0 || select_remove_elm > test->get_size_teacher() - 1);
				test->remove_teacher(select_remove_elm);
				cout << "Учитель удален!\n";
			}
			system("pause");
		}
		if (select_teacher == 4)
		{
			if (test->get_size_teacher() == 0)
			{
				cout << "Контейнер с учителями пуст!\n";
			}
			else
			{
				test->show_all_teacher();
			}
			system("pause");
		}
		if (select_teacher != 1 && select_teacher != 2 && select_teacher != 3 && select_teacher != 4 && select_teacher != 5)
		{
			cout << "Выбран неверный пункт!\n";
		}
	} while (select_teacher != 5);
}

void Keeper_adm(Keeper* test)
{
	int select_adm;
	do
	{
		
		system("cls");
		cout << "1.Добавить административный персонал\n2.Редактировать административный персонал\n3.Удалить административный персонал\n4.Распечатать всю администрацию\n5.Выйти\n";

		cin >> select_adm;
		if (select_adm == 1)
		{
			adm* example = new adm(0);
			cout << "Сейчас в контейнере " << test->get_size_adm() << " элементов\nВведите индекс по которому будет хрантся новый элемент\n";
			int index;
			do
			{
				cin >> index;
				if (index <= test->get_size_adm())
				{
					test->add_adm(example, index);
				}
				if (index > test->get_size_adm())
				{
					test->resize_adm(index);
					test->add_adm(example, index);
				}
				if (index < 0)
				{
					cout << "Индекс не может быть отрицательным!\n";
				}
				cout << "Персонал добавлен!\n";
				system("pause");
			} while (index < 0);

		}
		if (select_adm == 2)
		{
			if (test->get_size_adm() == 0)
			{
				cout << "Контейнер с административным персоналом пуст!\n";
			}
			else
			{
				cout << "Сейчас в контейнере хрантися " << test->get_size_adm() << " элементов" << endl;
				test->show_all_adm();
				cout << "Какой элемент будем редактировать?\n";
				int select_elm;
				do
				{
					cin >> select_elm;
					if (select_elm < 0 || select_elm > test->get_size_adm() - 1)
					{
						cout << "Выбран неверный элемент!\n";
					}
				} while (select_elm < 0 || select_elm > test->get_size_adm() - 1);
				cout << "Как будем редактировать?\n1.Полностью\n2.Частично\n";
				int select_edit;
				do
				{
					cin >> select_edit;
					if (select_edit == 1)
					{
						test->get_array_adm()[select_elm].set_last_name();
						test->get_array_adm()[select_elm].set_name();
						test->get_array_adm()[select_elm].set_middle_name();
						test->get_array_adm()[select_elm].set_position();
						test->get_array_adm()[select_elm].set_telephone();
						test->get_array_adm()[select_elm].remove_all_responsibility();
						int cnt_resp;
						cout << "Сколько областей ответственности у административного песонала?\n";

						do
						{
							cin >> cnt_resp;
							if (cnt_resp < 0 && cnt_resp > 100)
							{
								cout << "Столько областей ответственности быть не может!\nВведите еще раз!\n";
							}
						} while (cnt_resp < 0 && cnt_resp > 100);
						for (int i = 0; i != cnt_resp; i++)
						{
							test->get_array_adm()[select_elm].add_responsibility();
						}

					}
					if (select_edit == 2)
					{
						cout << "Что будем изменять?\n1.Фамилию\n2.Имя\n3.Отчество\n4.Должность\n5.Телефон\n6.Область ответственности\n";
						int select_edit_partially;
						do
						{
							cin >> select_edit_partially;
							if (select_edit_partially == 1)
							{
								test->get_array_adm()[select_elm].set_last_name();
							}
							if (select_edit_partially == 2)
							{
								test->get_array_adm()[select_elm].set_name();
							}
							if (select_edit_partially == 3)
							{
								test->get_array_adm()[select_elm].set_middle_name();
							}
							if (select_edit_partially == 4)
							{
								test->get_array_adm()[select_elm].set_position();
							}
							if (select_edit_partially == 5)
							{
								test->get_array_adm()[select_elm].set_telephone();
							}
							if (select_edit_partially == 6)
							{
								test->get_array_adm()[select_elm].edit_responsibility();
							}

							if (select_edit_partially != 1 && select_edit_partially != 2 && select_edit_partially != 3 && select_edit_partially != 4 && select_edit_partially != 5 && select_edit_partially != 6)
							{
								cout << "Выбран неверный пункт!\n";
							}
						} while (select_edit_partially != 1 && select_edit_partially != 2 && select_edit_partially != 3 && select_edit_partially != 4 && select_edit_partially != 5 && select_edit_partially != 6);


					}

					if (select_edit != 1 && select_edit != 2)
					{
						cout << "Выбрана неверная позиция!\n";
					}
				} while (select_edit != 1 && select_edit != 2);
				cout << "Элемент отредактирован!\n";
			}
			system("pause");
		}
		if (select_adm == 3)
		{
			if (test->get_size_adm() == 0)
			{
				cout << "Контейнер с административным персоналом пуст!\n";
			}
			else
			{
				cout << "Сейчас в контейнере хрантися " << test->get_size_adm() << " элементов" << endl;
				test->show_all_adm();
				cout << "Какой элемент будем удалять?\n";
				int select_remove_elm;
				do
				{
					cin >> select_remove_elm;
					if (select_remove_elm < 0 || select_remove_elm > test->get_size_adm() - 1)
					{
						cout << "Выбран неверный элемент!\n";
					}
				} while (select_remove_elm < 0 || select_remove_elm > test->get_size_adm() - 1);
				test->remove_adm(select_remove_elm);
				cout << "Персонал удален!\n";
			}
			system("pause");
		}
		if (select_adm == 4)
		{
			if (test->get_size_adm() == 0)
			{
				cout << "Контейнер с административным персоналом пуст!\n";
			}
			else
			{
				test->show_all_adm();
			}
			system("pause");
		}
		if (select_adm != 1 && select_adm != 2 && select_adm != 3 && select_adm != 4 && select_adm != 5)
		{
			cout << "Выбран неверный пункт!\n";
		}
	}
		while (select_adm != 5);
}

void load_and_save(Keeper* test)
{
	string filename;
	int flag = 0;
	int flag_load = 0;
	int flag_save = 0;
	do
	{
	system("cls");
	cout << "1.Сохранить\n2.Загрузить\n3.Выйти\n";
	int select;
	do
	{
		cin >> select;
		if (select == 1)
		{
			flag_save = 1;
		}
		if (select == 2)
		{
			flag_load = 1;
		}
		if(select == 3)
		{
			return;
		}
		if(select!= 1 && select !=2 && select !=3)
		{
			cout << "Выбран неверный пункт!\n";
		}
	}
		while (select != 1 && select != 2 && select != 3);
			system("cls");
	cout << "Пожалуйста, введите название файла txt, doc\n";

	cin >> filename;
	const char* filename2 = filename.c_str();
	char* extension = (char*)calloc(4, 4 * sizeof(char*));
	extension[0] = filename[strlen(filename2) - 3];
	extension[1] = filename[strlen(filename2) - 2];
	extension[2] = filename[strlen(filename2) - 1];
	if (strcmp(extension, "txt") == 0 || strcmp(extension, "doc") == 0)
	{
		flag = 1;
		free(extension);
	}
	else
	{
		cout << "Данный формат не поддерживается!\n";
		system("pause");
		free(extension);
		return;
	}
}
	while (flag != 1);

if (flag_load == 1)
{
	test->load(filename.c_str());
	system("pause");
}
if (flag_save == 1)
{
	test->save(filename.c_str());
	system("pause");
}
}
void Cesacr()
{
	cout << "1.Зашифровать файл\n2.Расшифровать файл\n3.Выйти";
	int select = 0;
	do
	{
		string filename;

		cin >> select;
		if (select == 1)
		{
			cout << "Введите пожалуйста полное имя файла:\n";
			cin >> filename;
			const char* filename2 = filename.c_str();
			char* extension = (char*)calloc(4, 4 * sizeof(char*));
			extension[0] = filename[strlen(filename2) - 3];
			extension[1] = filename[strlen(filename2) - 2];
			extension[2] = filename[strlen(filename2) - 1];
			if (strcmp(extension, "txt") == 0 || strcmp(extension, "doc") == 0)
			{
				free(extension);
				ifstream myin;
				ofstream myout;
				const char* exception_open_file = "Не удается открыть файл для сохранения!\n";
				char* filename_output = (char*)calloc(strlen(filename2) + 10, (strlen(filename2) + 10) * sizeof(char*));
				strncpy(filename_output, filename2, strlen(filename2) - 3);
				strcat(filename_output, "cesacr_in.txt");
				myin.open(filename, ios::in);
				myout.open(filename_output, ios::out);
				cout << "Пожалуйста, введите ключ шифрования для Цезаря\nОн не должен быть меньше нуля и больше 4\n";
				int key = 0;
				do
				{
					cin >> key;
					if (key < 0 && key >= 4)
					{
						cout << "Ключ не соответствует диапазону!\n";
					}
				} while (key < 0 && key >= 4);
				try
				{
					if (!myin.is_open())
					{
						throw exception_open_file;
					}
					string line;
					int i = 0;
					while (getline(myin, line))
					{
						const char* buffer5 = line.c_str();
						char* buffer6 = (char*)calloc(strlen(buffer5), strlen(buffer5) * sizeof(char*));
						strcpy(buffer6, buffer5);
						for (int i = 0; i != strlen(buffer5); i++)
						{


							buffer6[i] += key;


						}
						myout << buffer6;
						myout << "\n";
					}
					myin.close();
				}
				catch (const char* exception_open_file)
				{
					cout << exception_open_file << " " << filename << endl;
					myin.close();

					system("pause");

				}
			}
			else
			{
				cout << "Данный формат не поддерживается!\n";
				system("pause");
				return;
			}
		}
		if (select == 2)
		{
			cout << "Введите пожалуйста полный путь к файлу:\n";
			cin >> filename;
			const char* filename2 = filename.c_str();
			char* extension = (char*)calloc(4, 4 * sizeof(char*));
			extension[0] = filename[strlen(filename2) - 3];
			extension[1] = filename[strlen(filename2) - 2];
			extension[2] = filename[strlen(filename2) - 1];
			if (strcmp(extension, "txt") == 0 || strcmp(extension, "doc") == 0)
			{
				free(extension);
				ifstream myin;
				ofstream myout;
				const char* exception_open_file = "Не удается открыть файл для сохранения!\n";
				char* filename_output = (char*)calloc(strlen(filename2) + 10, (strlen(filename2) + 10) * sizeof(char*));
				strncpy(filename_output, filename2, strlen(filename2) - 3);
				strcat(filename_output, "cesacr_out.txt");
				myin.open(filename, ios::in);
				myout.open(filename_output, ios::out);
				cout << "Пожалуйста, введите ключ шифрования для Цезаря\nОн не должен быть меньше нуля и больше 4\n";
				int key = 0;
				do
				{
					cin >> key;
					if (key < 0 || key >= 4)
					{
						cout << "Ключ не соответствует диапазону!\n";
					}
				} while (key < 0 || key >= 4);
				try
				{
					if (!myin.is_open())
					{
						throw exception_open_file;
					}
					string line;
					int i = 0;
					while (getline(myin, line))
					{
						const char* buffer5 = line.c_str();
						char* buffer6 = (char*)calloc(strlen(buffer5), strlen(buffer5) * sizeof(char*));
						strcpy(buffer6, buffer5);
						for (int i = 0; i != strlen(buffer5); i++)
						{
							buffer6[i] -= key;
						}
						myout << buffer6;
					}
					myin.close();
					cout << "Файл расшифрован!\n";
					system("pause");
				}
				catch (const char* exception_open_file)
				{
					cout << exception_open_file << " " << filename << endl;
					myin.close();

					system("pause");

				}
			}
			else
			{
				cout << "Данный формат не поддерживается!\n";
				system("pause");

				return;
			}
		}
		if (select != 1 && select != 2 && select != 3)
		{
			cout << "Выбран неверный пункт!\n";
		}
	} while (select != 1 && select != 2 && select != 3);
}
void Keeper_menu()
{
	int size;
	
	cout << "Введите размер контейнера для начала работы:\n";
	do
	{
		cin >> size;
		if (size < 0)
		{
			cout << "Контейнер не может быть отрицательным!\n";
		}
	}
		while (size < 0);
	Keeper* test = new Keeper(0);
	int select;
	do
	{
		system("cls");
		print_menu();
		cin >> select;
		if (select == 1)
		{
			Keeper_student(test);
		}
		if (select == 2)
		{
			Keeper_teacher(test);
		}
		if (select == 3)
		{
			Keeper_adm(test);
		}
		if (select == 4)
		{
			load_and_save(test);
		}
		if (select == 5)
		{
			Cesacr();
		}
	}
		while (select != 6);
}


int main(void)
{
	SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
	SetConsoleOutputCP(1251);
	Keeper_menu();
}