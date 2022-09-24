#pragma once
#include "lib.h"
class Student : public Human
{
private:
	string name;
	string group;
	string spec;
	string course;
	string av_ball;

public:
	Student();
	Student(string name);
	~Student();
	Student(const Student& Student_copy);

	string get_name() const;
	void set_name(string name_ch);
	string get_group() const;
	void set_group(string group_ch);
	string get_spec() const;
	void set_spec(string spec_ch);
	string get_course() const;
	void set_course(string course_ch);
	string get_av_ball() const;
	void set_av_ball(string avb_ch);

	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
	virtual bool averball(double a);
};
