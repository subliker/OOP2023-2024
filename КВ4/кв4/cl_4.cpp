#include "cl_4.h"

cl_4::cl_4(cl_base* header, string name) : cl_base(header, name, 4) {}

// Метод сигнала
void cl_4::signal(string& d) {
	cout << endl << "Signal from " << path();
	d += " (class: 4)";
}


// Метод обработчика
void cl_4::handler(string d) {
	cout << endl << "Signal to " << path() << "   Text: " << d;
}