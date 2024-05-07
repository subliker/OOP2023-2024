#include "cl_input.h"

cl_input::cl_input(cl_base* system_ob, TYPE_HANDLER system_handler) {
	state = 1;
	set_connect(SIGNAL_D(cl_input::signal), system_ob, system_handler);
}

void cl_input::signal(string s) {

}

void cl_input::handler(string& s) {
	int a;
	cout << "ABÐÎÐÀ ÕÓÉÍß";
	cin >> a;
}