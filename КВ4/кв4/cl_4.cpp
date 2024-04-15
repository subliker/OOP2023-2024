#include "cl_4.h"

cl_4::cl_4(cl_base* header, string name) : cl_base(header, name, 4) {}

// ����� �������
void cl_4::signal(string& d) {
	cout << endl << "Signal from " << path();
	d += " (class: 4)";
}


// ����� �����������
void cl_4::handler(string d) {
	cout << endl << "Signal to " << path() << "   Text: " << d;
}