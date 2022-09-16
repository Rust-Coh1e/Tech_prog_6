#pragma once
#include "Human.h"
class Employee :
    public Human
{
private:
    string name;
    string post;
    string tnumber;
    string respons;
public:
    Employee();
    ~Employee();
    Employee(const Employee& Employee_copy);
    Employee(string name);

	string get_name() const;
	void set_name(string name_ch);
	string get_post() const;
	void set_post(string post_ch);
	string get_tnumber() const;
	void set_tnumber(string tnumber_ch);
	string get_respons() const;
	void set_respons(string respons_ch);


	virtual void show(); 
	virtual void rewrite(); 
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);

};

