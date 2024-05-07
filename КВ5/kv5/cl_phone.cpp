#include "cl_phone.h"

cl_phone::cl_phone(cl_base* head, string phone_n) :cl_base(head, phone_n) {};

int cl_phone::get_call_count() { return call_count; }

int cl_phone::get_conversation_count() { return conversation_count; }

int cl_phone::get_dial_count() { return dial_count; }