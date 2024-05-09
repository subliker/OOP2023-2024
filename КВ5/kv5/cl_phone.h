#ifndef __CL_PHONE__H
#define __CL_PHONE__H

#include "cl_base.h"

// ����� ������� ��� ������ ������ � ������.
class cl_phone : public cl_base {
	// ����� �� �������
	bool busy = false;
	// ������ ������ �������
	vector<string> calls;
	// ���������� �������
	int call_count = 0;
	// ���������� ����������
	int conversation_count = 0;
	// ���������� �������
	int dial_count = 0;
public:
	bool get_busy();
	// �����������
	cl_phone(cl_base*, string);

	int get_call_count();
	int get_conversation_count();
	int get_dial_count();

	void add_call_count();

	void signal_call(string&);
	void call(string);
};

#endif