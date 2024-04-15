#include "cl_6.h"

cl_6::cl_6(cl_base* header, string name) : cl_base(header, name, 6) {}

// Метод сигнала
void cl_6::signal(string& d) {
	cout << endl << "Signal from " << path();
	d += " (class: 6)";
}


// Метод обработчика
void cl_6::handler(string d) {
	cout << endl << "Signal to " << path() << "   Text: " << d;
}