#include "lib.h"

using namespace std;

Employee::Employee()
{
    cout << "Constructor Employee without attributes was called." << endl;
}

Employee::~Employee()
{
    cout << "Destructor Employee was called." << endl;
}


Employee::Employee(const Employee& Employee_copy)
{
    name = Employee_copy.name;
    post = Employee_copy.post;
    tnumber = Employee_copy.tnumber;
    respons = Employee_copy.respons;

}

Employee::Employee(string name)
{
    this->name = name;
}

string Employee::get_name() const { return name; }

void Employee::set_name(string name_ch) { name = name_ch; }

string Employee::get_post() const { return post; }

void Employee::set_post(string post_ch) { post = post_ch; }

string Employee::get_tnumber() const { return tnumber; }

void Employee::set_tnumber(string tnumber_ch) { tnumber = tnumber_ch; }

string Employee::get_respons() const { return respons; }

void Employee::set_respons(string response_ch) { respons = response_ch; }

void Employee::show()
{
    cout << "------------------------------------" << endl;
    cout << "Person: Employee" << endl;
    cout << "Name: " << name << endl;
    cout << "Post: " << post << endl;
    cout << "Telephone: " << tnumber << endl;
    cout << "Responsible area: " << respons << endl;
    cout << "------------------------------------" << endl;
}

void Employee::rewrite()
{
    cout << "------------------------------------" << endl;
    cin.ignore(32767, '\n');
    cout << "Person: Employee" << endl;
    cout << "Input new name: ";
    getline(cin, name);
    cout << "Input new post: ";
    getline(cin, post);
    cout << "Input new telephone number: ";
    getline(cin, tnumber);
    cout << "Input new area of resnosible: ";
    getline(cin, respons);
    cout << "------------------------------------" << endl;
}

void Employee::saving()
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
    outfile << 3 << endl << name << endl << post << endl << tnumber << endl << respons << endl;
    outfile.close();
}

void Employee::redact_str(int num_str, string red_str)
{
    switch (num_str)
    {
    case 1:
        this->name = red_str;
        break;
    case 2:
        this->post = red_str;
        break;
    case 3:
        this->tnumber = red_str;
        break;
    case 4:
        this->respons = red_str;
        break;
    default:
        throw "Incorrect number of string!";
        break;
    }
}

