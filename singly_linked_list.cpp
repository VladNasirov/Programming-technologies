#include "singly_linked_list.h"

void singly_linked_list::add_element()
{
	Uzel* buffer = new Uzel;
	string stroka_vvoda;
	cin >> stroka_vvoda;
	buffer->stroka = stroka_vvoda;
	buffer->ptr = head;
	head = buffer;
	cnt++;
}
void singly_linked_list::add_element(string mas)
{
	Uzel* buffer = new Uzel;
	buffer->stroka = mas;
	buffer->ptr = head;
	head = buffer;
	cnt++;
}
void singly_linked_list::remove_element(int i)
{
	Uzel* temp = head;
	if (cnt == 0)
	{
		cout << "Список пуст" << endl;
	}
	else
	{
		int j = 0;
		while (j != i)
		{
			temp = temp->ptr;
			j++;
		}
		Uzel* temp1 = temp;
		temp1 = temp->ptr;
		free(temp);
		if (i == 0)
		{
			head = temp1;
		}
		if (i == 1)
		{
			head->ptr = temp1;
		}
		cnt--;
	}
}
void singly_linked_list:: edit_element(int i)
{
	Uzel* temp = head;
	if (cnt == 0)
	{
		cout << "Список пуст" << endl;
	}
	else
	{
		int j = 0;
		while (j != i)
		{
			temp = temp->ptr;
			j++;
		}
		cout << "Введите данные" << endl;
		cin >> temp->stroka;
		cout << "Редактирование успешно закончено!" << endl;
	}
}

void singly_linked_list:: show()
{
	Uzel* temp = head;
	int i = 0;
	while (i != cnt)
	{
		cout << i << ". " << temp->stroka << endl;

		temp = temp->ptr;
		i++;

	}
}
string singly_linked_list:: get_element(int i)
{
	Uzel* temp = head;
	int j = 0;
	while (j != i)
	{

		temp = temp->ptr;
		j++;
	}
	return temp->stroka;
}

string singly_linked_list:: get_all_element()
{
	string all_element = "";
	Uzel* temp = head;
	int j = 0;
	while (j != cnt)
	{
		all_element += temp->stroka;
		all_element += " ";
		temp = temp->ptr;
		j++;
	}
	return all_element;
}

string singly_linked_list:: get_all_element_save()
{
	string all_element = "";
	Uzel* temp = head;
	int j = 0;
	while (j != cnt)
	{
		if (j == cnt - 1)
		{
			all_element += temp->stroka;
			temp = temp->ptr;
			j++;
		}
		else
		{
			all_element += temp->stroka;
			all_element += "&";
			temp = temp->ptr;
			j++;
		}
	}
	return all_element;
}

int singly_linked_list:: getCount()
{
	return cnt;
}