#include "cl_2.h"

cl_2::cl_2(cl_base* header, string name) : cl_base(header, name, 2) {}

// Метод сигнала
void cl_2::signal(string& d) {
	cout << endl << "Signal from " << path();
	d += " (class: 2)";
}


// Метод обработчика
void cl_2::handler(string d) {
	cout << endl << "Signal to " << path() << "   Text: " << d;
}