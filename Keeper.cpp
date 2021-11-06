#include "Keeper.h"
Keeper::Keeper()
{
	setlocale(LC_ALL, "Russian");
	size_student = 0;
	size_adm = 0;
	size_teacher = 0;
	value_student = nullptr;
	value_teacher = nullptr;
	value_adm = nullptr;
	cout << "Класс Keeper создан!\n";
}

Keeper::Keeper(int size)
{
	setlocale(LC_ALL, "Russian");
	if (size >= 0)
	{
		this->size_student = size;
		this->size_teacher = size;
		this->size_adm = size;
		value_student = new Student[size];
		value_adm = new adm[size];
		value_teacher = new Teacher[size];

		cout << "Класс Keeper создан!\n";
	}
	else
	{
		value_student = nullptr;
		value_adm = nullptr;
		value_student = nullptr;
		cout << "Класс Keeper может быть отрицательной длины!\n";
		system("pause");

	}
}


void Keeper::add_student(Student* new_element, int pos)
{
	if (pos < 0 || pos > size_student)
	{
		cout << "Позиция в классе Keeper отсутствует!\n";

	}
	else
	{
		Student* temp = new Student[size_student + 1];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = value_student[i];
		}
		temp[pos] = *new_element;
		for (int j = pos; j < size_student; j++)
		{
			temp[j + 1] = value_student[j];
		}
		delete[] value_student;
		value_student = temp;
		size_student++;
	}
}

void Keeper::add_teacher(Teacher* new_element, int pos)
{
	if (pos < 0 || pos > size_teacher)
	{
		cout << "Позиция в классе Keeper отсутствует!\n";

	}
	else
	{
		Teacher* temp = new Teacher[size_teacher + 1];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = value_teacher[i];
		}
		temp[pos] = *new_element;
		for (int j = pos; j < size_teacher; j++)
		{
			temp[j + 1] = value_teacher[j];
		}
		delete[] value_teacher;
		value_teacher = temp;
		size_teacher++;
	}
}

void Keeper::add_adm(adm* new_element, int pos)
{
	if (pos < 0 || pos > size_adm)
	{
		cout << "Позиция в классе Keeper отсутствует!\n";

	}
	else
	{
		adm* temp = new adm[size_adm + 1];
		for (int i = 0; i < pos; i++)
		{
			temp[i] = value_adm[i];
		}
		temp[pos] = *new_element;
		for (int j = pos; j < size_adm; j++)
		{
			temp[j + 1] = value_adm[j];
		}
		delete[] value_adm;
		value_adm = temp;
		size_adm++;
	}
}


void Keeper::remove_student(int pos)
{
	if (size_student == 0)
	{
		cout << "Контейнер и так пуст!\n";
	}
	else
	{

		if (pos < 0 || pos > size_student)
		{
			cout << "Позиция в классе Keeper отсутствует!\n";

		}
		else
		{

			if (size_student == 1)
			{
				remove_all_student();
				return;
			}
			Student* temp = new Student[size_student - 1];
			for (int i = 0; i < pos; i++)
			{
				temp[i] = value_student[i];
			}
			for (int j = pos + 1; j < size_student; j++)
			{
				temp[j - 1] = value_student[j];
			}
			delete[] value_student;
			value_student = temp;
			size_student--;
		}
	}
}

void Keeper::remove_teacher(int pos)
{
	if (size_teacher == 0)
	{
		cout << "Контейнер и так пуст!\n";
	}
	else
	{

		if (pos < 0 || pos > size_teacher)
		{
			cout << "Позиция в классе Keeper отсутствует!\n";

		}
		else
		{

			if (size_teacher == 1)
			{
				remove_all_teacher();
				return;
			}
			Teacher* temp = new Teacher[size_teacher - 1];
			for (int i = 0; i < pos; i++)
			{
				temp[i] = value_teacher[i];
			}
			for (int j = pos + 1; j < size_teacher; j++)
			{
				temp[j - 1] = value_teacher[j];
			}
			delete[] value_teacher;
			value_teacher = temp;
			size_teacher--;
		}
	}
}

void Keeper::remove_adm(int pos)
{
	if (size_adm == 0)
	{
		cout << "Контейнер и так пуст!\n";
	}
	else
	{

		if (pos < 0 || pos > size_adm)
		{
			cout << "Позиция в классе Keeper отсутствует!\n";

		}
		else
		{

			if (size_adm == 1)
			{
				remove_all_adm();
				return;
			}
			adm* temp = new adm[size_adm - 1];
			for (int i = 0; i < pos; i++)
			{
				temp[i] = value_adm[i];
			}
			for (int j = pos + 1; j < size_adm; j++)
			{
				temp[j - 1] = value_adm[j];
			}
			delete[] value_adm;
			value_adm = temp;
			size_adm--;
		}
	}
}


void Keeper::resize_student(int newsize)
{
	if (newsize == size_student)
	{
		return;
	}
	if (newsize < 0)
	{
		remove_all_student();
		return;
	}
	Student* temp = new Student[newsize];
	if (size_student >= 0)
	{
		int count = 0;
		if (newsize > size_student)
		{
			count = size_student;
		}
		else
		{
			count = newsize;
		}
		for (int i = 0; i < count; i++)
		{
			temp[i] = value_student[i];
		}
		delete[] value_student;
		value_student = temp;
		size_student = newsize;

	}
}

void Keeper::resize_teacher(int newsize)
{
	if (newsize == size_teacher)
	{
		return;
	}
	if (newsize < 0)
	{
		remove_all_teacher();
		return;
	}
	Teacher* temp = new Teacher[newsize];
	if (size_teacher >= 0)
	{
		int count = 0;
		if (newsize > size_teacher)
		{
			count = size_teacher;
		}
		else
		{
			count = newsize;
		}
		for (int i = 0; i < count; i++)
		{
			temp[i] = value_teacher[i];
		}
		delete[] value_teacher;
		value_teacher = temp;
		size_teacher = newsize;

	}
}

void Keeper::resize_adm(int newsize)
{
	if (newsize == size_adm)
	{
		return;
	}
	if (newsize < 0)
	{
		remove_all_adm();
		return;
	}
	adm* temp = new adm[newsize];
	if (size_adm >= 0)
	{
		int count = 0;
		if (newsize > size_adm)
		{
			count = size_adm;
		}
		else
		{
			count = newsize;
		}
		for (int i = 0; i < count; i++)
		{
			temp[i] = value_adm[i];
		}
		delete[] value_adm;
		value_adm = temp;
		size_adm = newsize;

	}
}

void Keeper::reallocate_student(int newsize)
{
	remove_all_student();
	if (newsize <= 0)
	{
		return;
	}
	value_student = new Student[newsize];
	size_student = newsize;
}

void Keeper::reallocate_teacher(int newsize)
{
	remove_all_teacher();
	if (newsize <= 0)
	{
		return;
	}
	value_teacher = new Teacher[newsize];
	size_teacher = newsize;
}

void Keeper::reallocate_adm(int newsize)
{
	remove_all_adm();
	if (newsize <= 0)
	{
		return;
	}
	value_adm = new adm[newsize];
	size_adm = newsize;
}


void Keeper::remove_all_student()
{

	delete[] value_student;
	value_student = nullptr;
	size_student = 0;
}

void Keeper::remove_all_teacher()
{

	delete[] value_teacher;
	value_teacher = nullptr;
	size_teacher = 0;
}

void Keeper::remove_all_adm()
{

	delete[] value_adm;
	value_adm = nullptr;
	size_adm = 0;
}

int Keeper::get_size_student()
{
	return size_student;
}
int Keeper::get_size_teacher()
{
	return size_teacher;
}
int Keeper::get_size_adm()
{
	return size_adm;
}

void Keeper::show_all_student()
{
	for (int i = 0; i != size_student; i++)
	{
		cout << i << ". " << value_student[i] << endl;
	}
}

void Keeper::show_all_teacher()
{
	for (int i = 0; i != size_teacher; i++)
	{
		cout << i << ". " << value_teacher[i] << endl;
	}
}

void Keeper::show_all_adm()
{
	for (int i = 0; i != size_adm; i++)
	{
		cout << i << ". " << value_adm[i] << endl;
	}
}

Student* Keeper::get_array_student()
{
	return value_student;
}
Teacher* Keeper::get_array_teacher()
{
	return value_teacher;
}
adm* Keeper::get_array_adm()
{
	return value_adm;
}
Base& Keeper::operator[](int pos)
{
	if (pos < 0 || pos > size_student)
	{
		cout << "Позиция в классе Keeper отсутствует!\n";
		exit(1);
	}
	else
	{
		return value_student[pos];
	}
}

void Keeper::save(const char* filename)
{
	ofstream myout;
	const char* exception_open_file = "Не удается открыть файл для сохранения!\n";
	myout.open(filename, ios::out);
	try
	{
		if (!myout.is_open())
		{
			throw exception_open_file;
		}
		myout << "License by Vlad Nasyrov group 1941 start\n";
		for (int i = 0; i != size_student; i++)
		{

			myout << value_student[i].save_file();
		}
		for (int i = 0; i != size_teacher; i++)
		{
			myout << value_teacher[i].save_file();
		}
		for (int i = 0; i != size_adm; i++)
		{
			myout << value_adm[i].save_file();
		}
		myout << "License by Vlad Nasyrov group 1941 end";
		myout.close();
		cout << "Файл успешно загружен!\n";
	}
	catch (const char* exception_open_file)
	{
		cout << exception_open_file << " " << filename << endl;
		system("pause");
		myout.close();

	}
}

void Keeper::load(const char* filename)
{
	ifstream myin;
	const char* exception_open_file = "Не удается открыть файл для сохранения!\n";
	const char* error = "В строке недостаточно спец.символов.Файл изменен, либо записан неверно!\n";
	myin.open(filename, ios::in);
	try
	{
		if (!myin.is_open())
		{
			throw exception_open_file;
		}
		string line;
		int i = 0;

		int cnt_license = 0;

		while (getline(myin, line))
		{
			int cnt_reshsetok = 0;
			int cnt_and = 0;
			int cnt_dog = 0;

			const char* buffer = line.c_str();
			if (strcmp(buffer, "License by Vlad Nasyrov group 1941 start") == 0)
			{
				cnt_license++;
				continue;
			}
			if (strcmp(buffer, "License by Vlad Nasyrov group 1941 end") == 0)
			{
				cnt_license++;
				break;
			}

			for (int i = 0; i != strlen(buffer); i++)
			{
				if (buffer[i] == '@')
				{
					cnt_dog++;
				}
				if (buffer[i] == '#')
				{
					cnt_reshsetok++;
				}
				if (buffer[i] == '&')
				{
					cnt_and++;
				}
			}

			try
			{
				if (cnt_dog == 1)
				{
					char* buffer2 = (char*)calloc(strlen(buffer), sizeof(char*));
					strcpy(buffer2, buffer);
					char* istr = strtok(buffer2, "@");
					if (strcmp(istr, "Student") == 0)
					{

						if (cnt_reshsetok == 6)
						{
							Student* example = new Student();
							istr = strtok(NULL, "#");
							example->set_last_name(istr);
							istr = strtok(NULL, "#");
							example->set_name(istr);
							istr = strtok(NULL, "#");
							example->set_middle_name(istr);
							istr = strtok(NULL, "#");
							example->set_group_name(istr);
							istr = strtok(NULL, "#");
							example->set_speciality(istr);
							istr = strtok(NULL, "#");
							example->set_course(istr);
							istr = strtok(NULL, "#");
							example->set_average_score(istr);



							add_student(example, size_student);
							resize_student(size_student);
							continue;

						}
						else
						{
							throw error;
						}



					}
					if (strcmp(istr, "Teacher") == 0)
					{
						if (cnt_reshsetok == 4)
						{
							Teacher* example = new Teacher();
							istr = strtok(NULL, "#");
							example->set_last_name(istr);
							istr = strtok(NULL, "#");
							example->set_name(istr);
							istr = strtok(NULL, "#");
							example->set_middle_name(istr);
							istr = strtok(NULL, "#");




							istr = strtok(istr, "&");

							while (istr != NULL)
							{

								example->add_group(istr);
								istr = strtok(NULL, "&");
							}
							char* buffer3 = (char*)calloc(strlen(buffer), strlen(buffer) * sizeof(char*));
							strcpy(buffer3, buffer);
							char* istr2 = strtok(buffer3, "@");
							istr2 = strtok(NULL, "#");
							istr2 = strtok(NULL, "#");
							istr2 = strtok(NULL, "#");
							istr2 = strtok(NULL, "#");
							istr2 = strtok(NULL, "#");

							istr2 = strtok(istr2, "&");
							while (istr2 != NULL)
							{

								example->add_subject(istr2);
								istr2 = strtok(NULL, "&");
							}
							free(buffer3);





							add_teacher(example, size_teacher);
							resize_teacher(size_teacher);
							continue;
						}
						else
						{
							throw error;
						}

					}
					if (strcmp(istr, "adm") == 0)
					{
						if (cnt_reshsetok == 5)
						{
							adm* example = new adm();
							istr = strtok(NULL, "#");
							example->set_last_name(istr);
							istr = strtok(NULL, "#");
							example->set_name(istr);
							istr = strtok(NULL, "#");
							example->set_middle_name(istr);
							istr = strtok(NULL, "#");
							example->set_position(istr);
							istr = strtok(NULL, "#");
							example->set_telephone(istr);

							istr = strtok(NULL, "&");
							while (istr != NULL)
							{
								example->add_responsibility(istr);
								istr = strtok(NULL, "&");
							}
							//дописать запись в массив

							add_adm(example, size_adm);
							resize_adm(size_adm);
							continue;
						}
						else
						{
							throw error;
						}
					}
					free(buffer2);
					cout << "Файл успешно загружен!\n";
				}
				else
				{
					throw error;
				}
			}
			catch (const char* error)
			{
				cout << error << " " << filename << endl;
				myin.close();
				system("pause");
			}



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
