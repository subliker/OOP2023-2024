#ifndef __CL_CONTROLLER__H
#define __CL_CONTROLLER__H

#include "cl_base.h"
#include "cl_phone.h"

// ����� ������� ��� ������ ������ � ������.
class cl_controller : public cl_base {
	vector <cl_phone*> phones;
public:
	// ����� ���������� ������ � ���� �������
	void add_phone(string);
	// ����� ����������� ���
	void display_ATC(string);
	// ����� �������
	void signal_output(string);
	// �����������
	cl_controller(cl_base*);
};

#endif