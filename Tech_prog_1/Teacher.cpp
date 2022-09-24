#include "lib.h"

using namespace std;

Teacher::Teacher()
{
	cout << "Constructor Teacher without attributes was called." << endl;
}

Teacher::~Teacher()
{
	cout << "Destructor Teacher was called." << endl;
}

Teacher::Teacher(const Teacher& Teacher_copy)
{
	name = Teacher_copy.name;
	groups = Teacher_copy.groups;
	subs = Teacher_copy.subs;
}

Teacher::Teacher(string name)
{
	this->name = name;
}

string Teacher::get_name() const { return name; }

void Teacher::set_name(string name_ch) { name = name_ch; }

string Teacher::get_groups() const { return groups; }

void Teacher::set_groups(string groups_ch) { groups = groups_ch; }

string Teacher::get_subs() const { return subs; }

void Teacher::set_subs(string subs_ch) { subs = subs_ch; }

void Teacher::show()
{
	cout << "------------------------------------" << endl;
	cout << "Person: TEACHER" << endl;
	cout << "Name: " << name << endl;
	cout << "Groups: " << groups << endl;
	cout << "Subjects: " << subs << endl;
	cout << "------------------------------------" << endl;
}

void Teacher::rewrite()
{
	cout << "------------------------------------" << endl;
	cin.ignore(32767, '\n');
	cout << "Teacher: " << endl;
	cout << "Input new name: ";
	getline(cin, name);
	cout << "Input new groups: ";
	getline(cin, groups);
	cout << "Input new subs: ";
	getline(cin, subs);
	cout << "------------------------------------" << endl;
}

void Teacher::saving()
{
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile)
	{
		throw "Error opening!";
		system("pause");
		exit(1);
	}
	else
	{
		outfile << 2 << endl << name << endl << groups << endl << subs << endl;
		outfile.close();
	}
}

void Teacher::redact_str(int num_str, string red_str)
{
	switch (num_str)
	{
	case 1:
		this->name = red_str;
		break;
	case 2:
		this->groups = red_str;
		break;
	case 3:
		this->subs = red_str;
		break;
	default:
		throw "Incorrect number of string!";
		break;
	}
}

