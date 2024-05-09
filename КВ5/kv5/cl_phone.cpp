#include "cl_phone.h"

cl_phone::cl_phone(cl_base* head, string phone_n) :cl_base(head, phone_n) {};

void cl_phone::call(string) {
	busy = true;
	dial_count++;
}

bool cl_phone::get_busy() { return busy; }

void cl_phone::signal_call(string&){
	busy = true;
	conversation_count++;
}

void cl_phone::add_call_count() {
	call_count++;
}

int cl_phone::get_call_count() { return call_count; }

int cl_phone::get_conversation_count() { return conversation_count; }

int cl_phone::get_dial_count() { return dial_count; }