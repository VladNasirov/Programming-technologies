#include "Teacher.h"
#include "Student.h"
#include "Keeper.h"
#include <locale.h>
#include <Windows.h>


void print_menu()
{
	cout << "1.���� ������ �� ����������\n2.���� ������ � ���������\n3.���� ������ � ���������������� ����������\n4.���������� � ��������\n5.���� ������\n6.����� �� ���������\n";
}
void Keeper_student(Keeper* test)
{
	int select_student;
	do
	{
		system("cls");
		cout << "1.�������� ��������\n2.������������� ��������\n3.������� ��������\n4.����������� ���� ���������\n5.�����\n";
		cin >> select_student;
		if (select_student == 1)
		{
			Student* example = new Student(5);
			cout << "������ � ���������� " << test->get_size_student() << " ���������\n������� ������ �� �������� ����� ������� ����� �������\n";
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
					cout << "������ �� ����� ���� �������������!\n";
				}
			}
				while (index < 0);
			cout << "������� ������� ��������!\n";	
			system("pause");
		}
		if (select_student == 2)
		{
			if (test->get_size_student() == 0)
			{
				cout << "��������� ��������� ����!\n";

			}
			else
			{
				cout << "������ � ���������� �������� " << test->get_size_student() << " ���������" << endl;
				test->show_all_student();
				cout << "����� ������� ����� �������������?\n";
				int select_elm;
				do
				{
					cin >> select_elm;
					if (select_elm < 0 || select_elm > test->get_size_student() - 1)
					{
						cout << "������ �������� �������!\n";
					}
				} while (select_elm < 0 || select_elm > test->get_size_student() - 1);
				cout << "��� ����� �������������?\n1.���������\n2.��������\n";
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
						cout << "��� ����� ��������?\n1.�������\n2.���\n3.��������\n4.�������� ������\n5.�������� �������������\n6.����\n7.������� ����\n";
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
								cout << "������ �������� �����!\n";
							}
						} while (select_edit_partially != 1 && select_edit_partially != 2 && select_edit_partially != 3 && select_edit_partially != 4 && select_edit_partially != 5 && select_edit_partially != 6 && select_edit_partially != 7);
					}

					if (select_edit != 1 && select_edit != 2)
					{
						cout << "������� �������� �������!\n";
					}
				} while (select_edit != 1 && select_edit != 2);
				cout << "������� ��������������!\n";
			}
			system("pause");
		}
		if (select_student == 3)
		{
			if (test->get_size_student() == 0)
			{
				cout << "��������� ��������� ����!\n";

			}
			else
			{
				cout << "������ � ���������� �������� " << test->get_size_student() << " ���������" << endl;
				test->show_all_student();
				cout << "����� ������� ����� �������?\n";
				

				int select_remove_elm;
				do
				{
					cin >> select_remove_elm;
					if (select_remove_elm < 0 || select_remove_elm > test->get_size_student() - 1)
					{
						cout << "������ �������� �������!\n";
					}
				} while (select_remove_elm < 0 || select_remove_elm > test->get_size_student() - 1);
				test->remove_student(select_remove_elm);
				cout << "������� ������!\n";
			}
			system("pause");

		}

		if (select_student == 4)
		{
			if (test->get_size_student() == 0)
			{
				cout << "��������� ��������� ����!\n";

			}
			else
			{
				test->show_all_student();
			}
			system("pause");
		}
		if (select_student != 1 && select_student != 2 && select_student != 3 && select_student != 4 && select_student != 5)
		{
			cout << "������ �������� �����!\n";
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
		cout << "1.�������� �������\n2.������������� �������\n3.������� �������\n4.����������� ���� ��������\n5.�����\n";
		cin >> select_teacher;
		if (select_teacher == 1)
		{
			Teacher* example = new Teacher(2);
			cout << "������ � ���������� " << test->get_size_teacher() << " ���������\n������� ������ �� �������� ����� ������� ����� �������\n";
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
					cout << "������ �� ����� ���� �������������!\n";
				}
			} while (index < 0);
			cout << "������� ������� ��������!\n";
			system("pause");
		}
		if (select_teacher == 2)
		{
			if (test->get_size_teacher() == 0)
			{
				cout << "��������� � ��������� ����!\n";
			}
			else
			{
				cout << "������ � ���������� �������� " << test->get_size_teacher() << " ���������" << endl;
				test->show_all_teacher();
				cout << "����� ������� ����� �������������?\n";
				int select_elm;
				do
				{
					cin >> select_elm;
					if (select_elm < 0 || select_elm > test->get_size_teacher() - 1)
					{
						cout << "������ �������� �������!\n";
					}
				} while (select_elm < 0 || select_elm > test->get_size_teacher() - 1);
				cout << "��� ����� �������������?\n1.���������\n2.��������\n";
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
						cout << "������� ����� ��������� ����� �������������?\n";
						do
						{
							cin >> cnt_group_student;
							if (cnt_group_student < 0 && cnt_group_student > 100)
							{
								cout << "������������� �� ����� ����� ������� �����!\n������� ��� ���!\n";
							}
						} while (cnt_group_student < 0 && cnt_group_student > 100);
						for (int i = 0; i != cnt_group_student; i++)
						{
							test->get_array_teacher()[select_elm].add_group();
						}
						cout << "������� ��������� ����� �������������?\n";
						do
						{
							cin >> cnt_subjects;
							if (cnt_subjects < 0 && cnt_subjects > 50)
							{
								cout << "������������� �� ����� ����� ������� ���������!\n������� ��� ���!\n";
							}
						} while (cnt_subjects < 0 && cnt_subjects > 50);

						for (int i = 0; i != cnt_subjects; i++)
						{
							test->get_array_teacher()[select_elm].add_subject();
						}
					}
					if (select_edit == 2)
					{
						cout << "��� ����� ��������?\n1.�������\n2.���\n3.��������\n4.������ �������������\n5.�������� �������������\n";
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
								cout << "������ �������� �����!\n";
							}
						} while (select_edit_partially != 1 && select_edit_partially != 2 && select_edit_partially != 3 && select_edit_partially != 4 && select_edit_partially != 5);
					}
					if (select_edit != 1 && select_edit != 2)
					{
						cout << "������� �������� �������!\n";
					}
				} while (select_edit != 1 && select_edit != 2);
				cout << "������� ��������������!\n";
			}
			system("pause");
		}

		if (select_teacher == 3)
		{
			if (test->get_size_teacher() == 0)
			{
				cout << "��������� � ��������� ����!\n";
			}
			else
			{
				cout << "������ � ���������� �������� " << test->get_size_teacher() << " ���������" << endl;
				test->show_all_teacher();
				cout << "����� ������� ����� �������?\n";
				int select_remove_elm;
				do
				{
					cin >> select_remove_elm;
					if (select_remove_elm < 0 || select_remove_elm > test->get_size_teacher() - 1)
					{
						cout << "������ �������� �������!\n";
					}
				} while (select_remove_elm < 0 || select_remove_elm > test->get_size_teacher() - 1);
				test->remove_teacher(select_remove_elm);
				cout << "������� ������!\n";
			}
			system("pause");
		}
		if (select_teacher == 4)
		{
			if (test->get_size_teacher() == 0)
			{
				cout << "��������� � ��������� ����!\n";
			}
			else
			{
				test->show_all_teacher();
			}
			system("pause");
		}
		if (select_teacher != 1 && select_teacher != 2 && select_teacher != 3 && select_teacher != 4 && select_teacher != 5)
		{
			cout << "������ �������� �����!\n";
		}
	} while (select_teacher != 5);
}

void Keeper_adm(Keeper* test)
{
	int select_adm;
	do
	{
		
		system("cls");
		cout << "1.�������� ���������������� ��������\n2.������������� ���������������� ��������\n3.������� ���������������� ��������\n4.����������� ��� �������������\n5.�����\n";

		cin >> select_adm;
		if (select_adm == 1)
		{
			adm* example = new adm(0);
			cout << "������ � ���������� " << test->get_size_adm() << " ���������\n������� ������ �� �������� ����� ������� ����� �������\n";
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
					cout << "������ �� ����� ���� �������������!\n";
				}
				cout << "�������� ��������!\n";
				system("pause");
			} while (index < 0);

		}
		if (select_adm == 2)
		{
			if (test->get_size_adm() == 0)
			{
				cout << "��������� � ���������������� ���������� ����!\n";
			}
			else
			{
				cout << "������ � ���������� �������� " << test->get_size_adm() << " ���������" << endl;
				test->show_all_adm();
				cout << "����� ������� ����� �������������?\n";
				int select_elm;
				do
				{
					cin >> select_elm;
					if (select_elm < 0 || select_elm > test->get_size_adm() - 1)
					{
						cout << "������ �������� �������!\n";
					}
				} while (select_elm < 0 || select_elm > test->get_size_adm() - 1);
				cout << "��� ����� �������������?\n1.���������\n2.��������\n";
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
						cout << "������� �������� ��������������� � ����������������� ��������?\n";

						do
						{
							cin >> cnt_resp;
							if (cnt_resp < 0 && cnt_resp > 100)
							{
								cout << "������� �������� ��������������� ���� �� �����!\n������� ��� ���!\n";
							}
						} while (cnt_resp < 0 && cnt_resp > 100);
						for (int i = 0; i != cnt_resp; i++)
						{
							test->get_array_adm()[select_elm].add_responsibility();
						}

					}
					if (select_edit == 2)
					{
						cout << "��� ����� ��������?\n1.�������\n2.���\n3.��������\n4.���������\n5.�������\n6.������� ���������������\n";
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
								cout << "������ �������� �����!\n";
							}
						} while (select_edit_partially != 1 && select_edit_partially != 2 && select_edit_partially != 3 && select_edit_partially != 4 && select_edit_partially != 5 && select_edit_partially != 6);


					}

					if (select_edit != 1 && select_edit != 2)
					{
						cout << "������� �������� �������!\n";
					}
				} while (select_edit != 1 && select_edit != 2);
				cout << "������� ��������������!\n";
			}
			system("pause");
		}
		if (select_adm == 3)
		{
			if (test->get_size_adm() == 0)
			{
				cout << "��������� � ���������������� ���������� ����!\n";
			}
			else
			{
				cout << "������ � ���������� �������� " << test->get_size_adm() << " ���������" << endl;
				test->show_all_adm();
				cout << "����� ������� ����� �������?\n";
				int select_remove_elm;
				do
				{
					cin >> select_remove_elm;
					if (select_remove_elm < 0 || select_remove_elm > test->get_size_adm() - 1)
					{
						cout << "������ �������� �������!\n";
					}
				} while (select_remove_elm < 0 || select_remove_elm > test->get_size_adm() - 1);
				test->remove_adm(select_remove_elm);
				cout << "�������� ������!\n";
			}
			system("pause");
		}
		if (select_adm == 4)
		{
			if (test->get_size_adm() == 0)
			{
				cout << "��������� � ���������������� ���������� ����!\n";
			}
			else
			{
				test->show_all_adm();
			}
			system("pause");
		}
		if (select_adm != 1 && select_adm != 2 && select_adm != 3 && select_adm != 4 && select_adm != 5)
		{
			cout << "������ �������� �����!\n";
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
	cout << "1.���������\n2.���������\n3.�����\n";
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
			cout << "������ �������� �����!\n";
		}
	}
		while (select != 1 && select != 2 && select != 3);
			system("cls");
	cout << "����������, ������� �������� ����� txt, doc\n";

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
		cout << "������ ������ �� ��������������!\n";
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
	cout << "1.����������� ����\n2.������������ ����\n3.�����";
	int select = 0;
	do
	{
		string filename;

		cin >> select;
		if (select == 1)
		{
			cout << "������� ���������� ������ ��� �����:\n";
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
				const char* exception_open_file = "�� ������� ������� ���� ��� ����������!\n";
				char* filename_output = (char*)calloc(strlen(filename2) + 10, (strlen(filename2) + 10) * sizeof(char*));
				strncpy(filename_output, filename2, strlen(filename2) - 3);
				strcat(filename_output, "cesacr_in.txt");
				myin.open(filename, ios::in);
				myout.open(filename_output, ios::out);
				cout << "����������, ������� ���� ���������� ��� ������\n�� �� ������ ���� ������ ���� � ������ 4\n";
				int key = 0;
				do
				{
					cin >> key;
					if (key < 0 && key >= 4)
					{
						cout << "���� �� ������������� ���������!\n";
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
				cout << "������ ������ �� ��������������!\n";
				system("pause");
				return;
			}
		}
		if (select == 2)
		{
			cout << "������� ���������� ������ ���� � �����:\n";
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
				const char* exception_open_file = "�� ������� ������� ���� ��� ����������!\n";
				char* filename_output = (char*)calloc(strlen(filename2) + 10, (strlen(filename2) + 10) * sizeof(char*));
				strncpy(filename_output, filename2, strlen(filename2) - 3);
				strcat(filename_output, "cesacr_out.txt");
				myin.open(filename, ios::in);
				myout.open(filename_output, ios::out);
				cout << "����������, ������� ���� ���������� ��� ������\n�� �� ������ ���� ������ ���� � ������ 4\n";
				int key = 0;
				do
				{
					cin >> key;
					if (key < 0 || key >= 4)
					{
						cout << "���� �� ������������� ���������!\n";
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
					cout << "���� �����������!\n";
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
				cout << "������ ������ �� ��������������!\n";
				system("pause");

				return;
			}
		}
		if (select != 1 && select != 2 && select != 3)
		{
			cout << "������ �������� �����!\n";
		}
	} while (select != 1 && select != 2 && select != 3);
}
void Keeper_menu()
{
	int size;
	
	cout << "������� ������ ���������� ��� ������ ������:\n";
	do
	{
		cin >> size;
		if (size < 0)
		{
			cout << "��������� �� ����� ���� �������������!\n";
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
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251);
	Keeper_menu();
}