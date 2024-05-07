#include "cl_system.h"

cl_system::cl_system(cl_base* head) :cl_base(head, "SYSTEM") {}

void cl_system::build_tree_objects() {
	set_state(1);

	// Новый объект ввода
	cl_base* ob_input = new cl_input(this);
	ob_input->set_state(1);
	// Новый объект пульта управления
	cl_base* ob_controller = new cl_controller(this);
	ob_controller->set_state(1);
	// Новый объект вывода
	cl_base* ob_output = new cl_output(this);
	ob_output->set_state(1);

	// input number => add number in controller list
	ob_input->set_connect(SIGNAL_D(cl_input::read_data), ob_controller, HANDLER_D(cl_controller::add_phone));
	string in;
	while (ob_input->get_state()) ob_input->emit_signal(SIGNAL_D(cl_input::read_data), in);
	ob_input->break_connection(SIGNAL_D(cl_input::read_data), ob_controller, HANDLER_D(cl_controller::add_phone));
	ob_input->set_state(1);

	// message => display
	set_connect(SIGNAL_D(cl_system::signal_output), ob_output, HANDLER_D(cl_output::print));
	ob_controller->set_connect(SIGNAL_D(cl_controller::signal_output), ob_output, HANDLER_D(cl_output::print));

	// display ATC
	set_connect(SIGNAL_D(cl_system::signal_display_ATC), ob_controller, HANDLER_D(cl_controller::display_ATC));

	// input cmnd => handle cmnd
	set_connect(SIGNAL_D(cl_system::signal_read_cmnd), ob_input, HANDLER_D(cl_input::read_command));
	ob_input->set_connect(SIGNAL_D(cl_input::signal_cmnd_handler), this, HANDLER_D(cl_system::handler_cmnd));

	// ready to work сообщение	
	string msg = "Ready to work";
	emit_signal(SIGNAL_D(cl_system::signal_output), msg);
}

int cl_system::exec_app() {
	string s;
	while (get_state()) {
		emit_signal(SIGNAL_D(cl_system::signal_read_cmnd), s);
	}

	return 0;
}

void cl_system::handler_cmnd(string cmnd) {
	if (cmnd == "Turn off the system") {
		set_state(0);
		string msg = "Turn off the ATM";
		emit_signal(SIGNAL_D(cl_system::signal_output), msg);
	}
	else if (cmnd == "Display system status information") {
		emit_signal(SIGNAL_D(cl_system::signal_display_ATC), cmnd);
	}
}

void cl_system::signal_output(string) {}
void cl_system::signal_read_cmnd(string){}
void cl_system::signal_display_ATC(string){}
void cl_system::signal_controller(string) {}