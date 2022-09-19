#pragma once
#include "Human.h"
class Teacher :
    public Human
{
private:
    string name;
    string groups;
    string subs;

public:
    Teacher();
    ~Teacher();

    Teacher(const Teacher& Teacher_copy);
    Teacher(string name);

    string get_name() const;
    void set_name(string name_ch);
    string get_groups() const;
    void set_groups(string groups_ch);
    string get_subs() const;
    void set_subs(string subs_ch);

    virtual void show();
    virtual void rewrite();
    virtual void saving();
    virtual void redact_str(int num_str, string red_str);
};