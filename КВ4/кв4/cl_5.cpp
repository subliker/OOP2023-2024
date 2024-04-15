#include "cl_5.h"

cl_5::cl_5(cl_base* header, string name) : cl_base(header, name, 5) {}

// Метод сигнала
void cl_5::signal(string& d) {
	cout << endl << "Signal from " << path();
	d += " (class: 5)";
}


// Метод обработчика
void cl_5::handler(string d) {
	cout << endl << "Signal to " << path() << "   Text: " << d;
}