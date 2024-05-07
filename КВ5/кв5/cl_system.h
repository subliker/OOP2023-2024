#ifndef __CL_SYSTEM__H
#define __CL_SYSTEM__H

#include "cl_input.h"

// ����� ������� ��������.
class cl_system : public cl_base {
	// ����� �������
	void signal_input(string s);
	// ����� �����������
	void handler();
	// ������� ����
	int t = 0;
	// ����� ����������� ������� ������
	void handle_input(string&);
public:
	// ����������� ������
	cl_system();
	// ����� ���������� ������ ��������
	void build_tree_objects();
	// ����� ������� ����������
	int exec_app();
};

#endif