#ifndef __CL_OUTPUT__H
#define __CL_OUTPUT__H

#include "cl_base.h"
#include "cl_phone.h"

// ����� ������� ��� ������ ������ � ������.
class cl_output : public cl_base {
public:
	// ����� �����������
	void print(string);
	void print_tree(string);
	// �����������
	cl_output(cl_base*);
};

#endif