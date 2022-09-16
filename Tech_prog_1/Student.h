#pragma once
#include "Human.h"
class Student : public Human
{
private:
	string name;
	string group;
	string spec;
	int course;
	int av_ball;

	string get_name() const;
	void set_name(string name_ch);
	string get_group() const;
	void set_group(string group_ch);
	string get_spec() const;
	void set_spec(string spec_ch);
	int get_course() const;
	void set_course(int course_ch);
	int get_av_ball() const;
	void set_av_ball(int avb_ch);

	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);

};

