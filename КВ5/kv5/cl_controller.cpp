#include "cl_controller.h"

cl_controller::cl_controller(cl_base* system_ob) :cl_base(system_ob, "CONTROLLER") {}

// Метод добавления номера в базу номеров
void cl_controller::add_phone(string n) {
	if (n != "") {
		phones.push_back(new cl_phone(this, n));
	}
}

// Метод отображения АТС 
void cl_controller::display_ATC(string) {
	string msg;
	for (cl_phone* phone : phones) {
		msg = "telephone " + phone->getName() + " " + to_string(phone->get_call_count()) + " " + to_string(phone->get_conversation_count()) + " " + to_string(phone->get_dial_count());
		emit_signal(SIGNAL_D(cl_controller::signal_output), msg);
	}
}

// Метод отображения телефона
void cl_controller::display_phone(string d) {
	string fnd = "Display phone information ";
	int i = d.find(fnd);
	if (i == -1) {
		return;
	}
	// get phone n
	string phone_n = d.replace(i, fnd.length(), "");

	string msg;
	for (cl_phone* phone : phones) {
		if (phone->getName() == phone_n) {
			msg = "Phone log: " + phone_n;
			emit_signal(SIGNAL_D(cl_controller::signal_output), msg);
			return;
		}
	}
}

// Метод запроса вызова
void cl_controller::call_request(string d) {

}

void cl_controller::signal_output(string&){}