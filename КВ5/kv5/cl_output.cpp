#include "cl_output.h"

cl_output::cl_output(cl_base* system_ob) :cl_base(system_ob, "OUTPUT") {}

// ����� ������ ������
void cl_output::print(string d) {
	cout << d << endl;
}