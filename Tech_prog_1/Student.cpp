#include "lib.h"

using namespace std;

Student::Student()
{
    cout << "Constructor Student without attributes was called." << endl;
}

Student::~Student()
{
    cout << "Destructor Student was called." << endl;
}


Student::Student(const Student& Student_copy)
{
    name = Student_copy.name;
    group = Student_copy.group;
    spec = Student_copy.spec;
    course = Student_copy.course;
    av_ball = Student_copy.av_ball;
}

Student::Student(string name)
{
    this->name = name;
}

string Student::get_name() const { return name; }

void Student::set_name(string name_ch) { name = name_ch; }

string Student::get_group() const { return group; }

void Student::set_group(string groups_ch) { group = groups_ch; }

string Student::get_spec() const { return spec; }

void Student::set_spec(string spec_ch) { spec = spec_ch; }

string Student::get_course() const { return course; }

void Student::set_course(string course_ch) { course = course_ch; }

string Student::get_av_ball() const { return av_ball; }

void Student::set_av_ball(string avb_ch) { av_ball = avb_ch; }

void Student::show()
{
    cout << "------------------------------------" << endl;
    cout << "Person: Student" << endl;
    cout << "Name: " << name << endl;
    cout << "Group: " << group << endl;
    cout << "Specialization: " << spec << endl;
    cout << "Course: " << course << endl;
    cout << "Average ball: " << av_ball << endl;
    cout << "------------------------------------" << endl;
}

void Student::rewrite()
{
    cout << "------------------------------------" << endl;
    cin.ignore(32767, '\n');
    cout << "Person: Student" << endl;
    cout << "Input new name: ";
    getline(cin, name);
    cout << "Input new group: ";
    getline(cin, group);
    cout << "Input new spec: ";
    getline(cin, spec);
    cout << "Input new course: ";
    getline(cin, course);
    cout << "Input new av_ball: ";
    getline(cin, av_ball);
    cout << "------------------------------------" << endl;
}

void Student::saving()
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
    outfile << 1 << endl << name << endl << group << endl << spec << endl << course << endl << av_ball << endl;
    outfile.close();
}

void Student::redact_str(int num_str, string red_str)
{
    switch (num_str)
    {
    case 1:
        this->name = red_str;
        break;
    case 2:
        this->group = red_str;
        break;
    case 3:
        this->spec = red_str;
        break;
    case 4:
        this->course = red_str;
        break;
    case 5:
        this->av_ball = red_str;
        break;
    default:
        throw "Incorrect number of string!";
        break;
    }
}
