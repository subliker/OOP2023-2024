#include "cl_input.h"

cl_input::cl_input(cl_base* system_ob):cl_base(system_ob, "INPUT") {}

// Метод чтения данных
void cl_input::read_data(string& d) {
	getline(cin, d);
	if (d == "End of phones") {
		set_state(0);
		d = "";
	}
}

// Метод чтения комманд
void cl_input::read_command(string& d) {
	getline(cin, d);
	emit_signal(SIGNAL_D(cl_input::signal_cmnd_handler), d);
}


void cl_input::signal_cmnd_handler(string& d) {}