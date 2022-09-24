#pragma warning( disable : 6386 )
#pragma warning( disable : 26451 )
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
	tmp = new Elem;
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
	if (m_size != 0)
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


	ifstream infile;
	int read_size, num_human; //переменная читки размера и персонажа
	string a, b, c, d, e; //считываемые строки
	string initfile = "data.txt";
	Human* humans;

	infile.open(initfile);
	if (!infile)
	{
		throw "Error opening!";
		system("pause");
		exit(1);
	}

	infile >> read_size; //читаем кол-во людей

	for (int i = 0; i < read_size; i++)
	{
		infile >> num_human; //читаем номер персоны
		infile.ignore(32767, '\n');

		if (num_human == 1) //перед нами студени
		{
			//infile >> a >> b >> c >> d >> e;

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			Student* student;
			student = new Student;
			student->set_name(a);
			student->set_group(b);
			student->set_course(c);
			student->set_av_ball(d);
			humans = student;
			insert(humans);
		}

		if (num_human == 2) //перед нами злодей
		{
			//infile >> a >> b >> c >> d >> e >> f >> g;

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			Teacher* teacher;
			teacher = new Teacher;
			teacher->set_name(a);
			teacher->set_groups(b);
			teacher->set_subs(c);
			humans = teacher;
			insert(humans);
		}

		if (num_human == 3) //перед нами монстр
		{
			//infile >> a >> b >> c;

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);

			Employee* emp;
			emp = new Employee;
			emp->set_name(a);
			emp->set_post(b);
			emp->set_tnumber(c);
			emp->set_respons(d);
			humans = emp;
			insert(humans);
		}
	}
}