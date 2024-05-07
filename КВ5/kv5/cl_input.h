#ifndef __CL_INPUT__H
#define __CL_INPUT__H

#include "cl_base.h"

// ����� ������� ��� ������ ������ � ������.
class cl_input : public cl_base {
public:
	// �����������
	cl_input(cl_base*);
	// ����� ������ ������
	void read_data(string&);
	// ����� ������ �������
	void read_command(string&);
	// ����� �������
	void signal_cmnd_handler(string&);
};

#endif