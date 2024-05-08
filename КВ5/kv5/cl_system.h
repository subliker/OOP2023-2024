#ifndef __CL_SYSTEM__H
#define __CL_SYSTEM__H

#include "cl_input.h"
#include "cl_controller.h"
#include "cl_output.h"
#include <iostream>
using namespace std;

// ����� ������� ��������.
class cl_system : public cl_base {
	// ����� �������
	void signal_output(string&);
	void signal_display_ATC(string&);
	void signal_controller(string&);
	void signal_read_cmnd(string&);
	void signal_display_phone(string&);
	void signal_call_request(string&);

	// ����� �����������
	void handler_cmnd(string);
	// ������� ����
	int t = 0;
public:
	// ����������� ������
	cl_system(cl_base*);
	// ����� ���������� ������ ��������
	void build_tree_objects();
	// ����� ������� ����������
	int exec_app();
};

#endif