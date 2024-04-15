#include "cl_1.h"

cl_1::cl_1(cl_base* header, string name) : cl_base(header, name, 1) {}

// Метод сигнала
void cl_1::signal(string& d) {
	cout <<endl<< "Signal from " << path();
	d += " (class: 1)";
}


// Метод обработчика
void cl_1::handler(string d) {
	cout <<endl << "Signal to " << path() << "   Text: " << d;
}