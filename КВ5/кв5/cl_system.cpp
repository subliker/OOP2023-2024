#include "cl_system.h"


cl_system::cl_system() {
	state = 1;
	cl_base* ob_input = new cl_input(this, HANDLER_D(cl_system::handle_input));
	set_connect(SIGNAL_D(cl_system::signal_input), ob_input, HANDLER_D(cl_input::handler));
}

void cl_system::build_tree_objects() {
	string a = "A";
	emit_signal(SIGNAL_D(cl_system::signal_input), a);
}

int cl_system::exec_app() {
	return 1;
}

void cl_system::signal_input(string s) {

}