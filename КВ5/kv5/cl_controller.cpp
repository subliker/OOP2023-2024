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

// Метод получения указателя объекта телефона по номеру
cl_phone* cl_controller::get_phone(string phone_n) {
	for (cl_phone* phone : phones) {
		if (phone->getName() == phone_n) {
			return phone;
		}
	}
	return nullptr;
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
	cl_phone* phone = get_phone(phone_n);
	if (phone != nullptr) {
		msg = "Phone log: " + phone_n;
		emit_signal(SIGNAL_D(cl_controller::signal_output), msg);
	}
}

// Метод запроса вызова
void cl_controller::call_request(string d) {
	string msg;
	stringstream ss(d.substr(14));
	string n1;
	getline(ss, n1, ' ');
	if (n1.length() != 7) {
		msg = "The subscriber's number was dialed incorrectly: " + n1;
		emit_signal(SIGNAL_D(cl_controller::signal_output), msg);
		return;
	}
	cl_phone* phone1 = get_phone(n1);
	if (phone1 == nullptr) {
		msg = "Subscriber "+n1+" not found";
		emit_signal(SIGNAL_D(cl_controller::signal_output), msg);
		return;
	}
	if (phone1->get_busy()) {
		msg = "The subscriber's number was dialed incorrectly: "+n1;
		emit_signal(SIGNAL_D(cl_controller::signal_output), msg);
		return;
	}
	phone1->add_call_count();

	string n2;
	getline(ss, n2, ' ');
	if (n2.length() != 7) {
		msg = "The phone is busy, a new call is not possible: " + n2;
		emit_signal(SIGNAL_D(cl_controller::signal_output), msg);
		return;
	}
	cl_phone* phone2 = get_phone(n2);
	if (phone2 == nullptr) {
		msg = "Subscriber " + n2 + " not found";
		emit_signal(SIGNAL_D(cl_controller::signal_output), msg);
		return;
	}
	if (phone2->get_busy()) {
		msg = "Subscriber " + n2 + " is busy";
		emit_signal(SIGNAL_D(cl_controller::signal_output), msg);
		return;
	}

	phone1->set_connect(SIGNAL_D(cl_phone::signal_call), phone2, HANDLER_D(cl_phone::call));
	msg = d.substr(14);
	phone1->emit_signal(SIGNAL_D(cl_phone::signal_call), msg);
	phone1->break_connection(SIGNAL_D(cl_phone::signal_call), phone2, HANDLER_D(cl_phone::call));
}

void cl_controller::signal_output(string&){}