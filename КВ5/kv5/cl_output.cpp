#include "cl_output.h"

cl_output::cl_output(cl_base* system_ob) :cl_base(system_ob, "OUTPUT") {}

// Метод чтения данных
void cl_output::print(string d) {
	string l = d;
	cout << d << endl;
}