#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <iostream>
#include <vector>
using namespace std;

class cl_base;

#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(&signal_f)
#define HANDLER_D(handler_f)(TYPE_HANDLER)(&handler_f)
typedef void (cl_base ::* TYPE_SIGNAL)(string&);
typedef void (cl_base ::* TYPE_HANDLER)(string);

// ����� �������, ����������� � ��������� � �������������
class cl_base {
	struct o_sh {
		TYPE_SIGNAL p_signal;
		cl_base* p_cl_base;
		TYPE_HANDLER p_handler;
	};
protected:
	// ����� �������
	void signal();
	// ����� �����������
	void handler();
	int state;
public:
	// ������ ��� �������� ������������� ������
	vector < o_sh* > connects;
	// ����� �������� �����
	void set_connect(TYPE_SIGNAL, cl_base*, TYPE_HANDLER);
	// ����� ������ ������� � ��������� ��������������� ������������
	void emit_signal(TYPE_SIGNAL, string&);
	// ����� �������� (�������) ����� ����� �������� �������� ������� � ������������ �������� �������
	void break_connection(TYPE_SIGNAL, cl_base*, TYPE_HANDLER);
};

#endif