#include "Keeper.h"
#include "lib.h"

using namespace std;

Keeper::Keeper() : m_size(0), head(nullptr) {}

Keeper::Keeper(int size) : head(nullptr) { this->m_size = size; }

Keeper::~Keeper()
{
	if (head != NULL)
	{
		Elem* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Human();
			delete(buffer);
		}
		head->m_data->~Human();
		delete(head);
	}
}

Human* Keeper::operator[](const int index)
{
	if ((index >= m_size) || index < 0)
	{
		throw "Incorrect index!";
	}
	else
	{
		Elem* buffer = head;
		for (int i = 0; i < m_size - index - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->m_data);
	}
}

int Keeper::get_size() { return m_size; }

void Keeper::insert(Human* new_data)
{
	Elem* tmp;
	if (m_size == 0)
	{
		tmp->m_data = new_data;
		tmp->next = 0;
		++m_size;
	}
	else
	{
		tmp->m_data = new_data;
		tmp->next = head;
		++m_size;
	}
	head = tmp;
}

void Keeper::remove(int index)
{
	if (m_size == 0)
	{
		throw "Nothing to delete!";
		system("pause");
	}
	int counter = 0;
	while (counter < index - 1)
	{
		head = head->next;
		counter++;
	}

	Elem* prev = head;
	prev->next->m_data->~Human();
	prev->next->next;
	delete(prev->next);
	--m_size;
}

void Keeper::save()
{
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile);
	if (!outfile)
	{
		throw "Error opening file!";
		system("pause");
		exit(1);
	}
	else
	{
		outfile << m_size << endl;
		outfile.close();
	}

	Elem* buffer = head;
	for (int i = 0; i < m_size; i++)
	{
		buffer->m_data->saving();
		buffer = buffer->next;
	}

}

// Дописать

void Keeper::load()
{

}