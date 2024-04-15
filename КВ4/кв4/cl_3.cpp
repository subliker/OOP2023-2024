#include "cl_3.h"

cl_3::cl_3(cl_base* header, string name) : cl_base(header, name, 3) {}

// ����� �������
void cl_3::signal(string& d) {
	cout << endl << "Signal from " << path();
	d += " (class: 3)";
}


// ����� �����������
void cl_3::handler(string d) {
	cout << endl << "Signal to " << path() << "   Text: " << d;
}