#ifndef __CL_CONTROLLER__H
#define __CL_CONTROLLER__H

#include "cl_base.h"
#include "cl_phone.h"

// ����� ������� ��� ������ ������ � ������.
class cl_controller : public cl_base {
	cl_phone* get_phone(string);
	vector <cl_phone*> phones;
public:
	// ����� ���������� ������ � ���� �������
	void add_phone(string);
	// ����� ����������� ���
	void display_ATC(string);
	// ����� ����������� ��������
	void display_phone(string);
	// ����� ������� ������
	void call_request(string);
	// ����� �������
	void signal_output(string&);
	// �����������
	cl_controller(cl_base*);
};

#endif