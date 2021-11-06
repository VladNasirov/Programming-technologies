#include "adm.h"
string adm::Me()
{
	return this->get_last_name() + " " + this->get_name() + " " + this->get_middle_name() + " " + this->get_position() + " " + this->get_telephone() + " " + this->responsibilty.get_all_element() + '\n';
}

string adm::save_file()
{
	return "adm@" + this->get_last_name() + "#" + this->get_name() + "#" + this->get_middle_name() + "#" + this->get_position() + "#" + this->get_telephone() + "#" + this->responsibilty.get_all_element_save() + '\n';
}
adm::adm() : Base()
{
	position = "*";
	telephone = "*";
	cout << "Объект административного персонала создан!\n";
}
adm::adm(int a) : Base(1)
{
	set_position();
	set_telephone();
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
		add_responsibility();
	}
}
void adm::set_position()
{
	cout << "Введите должность:\n";
	cin >> position;
}
void adm::set_position(char* mas)
{
	position = (string)mas;
}
string adm::get_position()
{
	return position;
}

void adm::set_telephone()
{
	cout << "Введите номер телефона. Помните, номер телефона состоит из 11 цифр!\n";
	int length;
	string buffer;
	do
	{
		cin >> buffer;
		const char* buffer1 = buffer.c_str();
		length = strlen(buffer1);
		if (length != 11)
		{
			cout << "Введен неверный номер телефона!\n";
		}
	} while (length != 11);
	telephone = buffer;
}
void adm::set_telephone(char* mas)
{
	telephone = (string)mas;
}

string adm::get_telephone()
{
	return telephone;
}

void adm::add_responsibility()
{
	cout << "Введите область отвественности:\n";
	responsibilty.add_element();

}
void adm::add_responsibility(char* mas)
{
	responsibilty.add_element((string)mas);
}
void adm::show_responsibility()
{
	cout << "Области отвественности:\n";
	responsibilty.show();
}
void adm::remove_responsibility()
{
	if (responsibilty.getCount() == 0)
	{
		cout << "У этого объекта нету объектов ответственности!\n";
	}
	else
	{
		cout << "У этого объекта всего " << responsibilty.getCount() << " областей ответственности:\n";
		responsibilty.show();
		cout << "Какую область будем удалять?\n";
		int pos;
		do {

			cin >> pos;
			if (pos < 0 || pos > responsibilty.getCount())
			{
				cout << "Выбрана неверная позиция!\n";
			}
		} while (pos < 0 || pos > responsibilty.getCount());
		responsibilty.remove_element(pos);
	}
}

void adm::edit_responsibility()
{
	if (responsibilty.getCount() == 0)
	{
		cout << "У этого объекта нету областей ответственности!\n";
	}
	else
	{
		cout << "У этого объекта всего " << responsibilty.getCount() << " областей ответственности:\n";
		responsibilty.show();
		cout << "Какую область будем редактировать?\n";
		int pos;
		do {

			cin >> pos;
			if (pos < 0 || pos > responsibilty.getCount())
			{
				cout << "Выбрана неверная позиция!\n";
			}
		} while (pos < 0 || pos > responsibilty.getCount());
		responsibilty.edit_element(pos);
	}
}
void adm::remove_all_responsibility()
{
	for (int i = 0; i != responsibilty.getCount(); i++)
	{
		responsibilty.remove_element(0);
	}
}
adm:: ~adm()
{
	cout << "Объект административного персонала удален" << endl;
}