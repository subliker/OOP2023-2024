#ifndef __CL_INPUT__H
#define __CL_INPUT__H

#include "cl_base.h"

// ����� ������� ��� ������ ������ � ������.
class cl_input : public cl_base {
public:
	// ����� �������
	void signal(string s);
	// ����� �����������
	void handler(string& s);
	// �����������
	cl_input(cl_base*, TYPE_HANDLER);
	// ����� ������ ������
	void read();
};

#endif