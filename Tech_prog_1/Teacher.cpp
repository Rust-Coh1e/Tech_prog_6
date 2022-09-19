#include "Teacher.h"

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


