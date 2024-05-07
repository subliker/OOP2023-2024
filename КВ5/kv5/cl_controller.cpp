#include "cl_controller.h"

cl_controller::cl_controller(cl_base* system_ob) :cl_base(system_ob, "CONTROLLER") {}

// Метод добавления номера в базу номеров
void cl_controller::add_phone(string n) {
	phones.push_back(new cl_phone(this, n));
}

// Метод вывода 
void cl_controller::display_ATC(string) {
	string msg;
	for (cl_phone* phone : phones) {
		msg = "telephone " + phone->getName() + " " + to_string(phone->get_call_count()) + " " + to_string(phone->get_conversation_count()) + " " + to_string(phone->get_dial_count());
		emit_signal(SIGNAL_D(cl_controller::signal_output), msg);
	}
}

void cl_controller::signal_output(string d){}