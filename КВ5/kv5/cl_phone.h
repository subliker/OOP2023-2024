#ifndef __CL_PHONE__H
#define __CL_PHONE__H

#include "cl_base.h"

// Класс объекта для чтения данных и команд.
class cl_phone : public cl_base {
	// Количество вызовов
	int call_count = 0;
	// Количество разговоров
	int conversation_count = 0;
	// Количество звонков
	int dial_count = 0;
public:
	// Конструктор
	cl_phone(cl_base*, string);

	int get_call_count();
	int get_conversation_count();
	int get_dial_count();
};

#endif