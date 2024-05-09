#ifndef __CL_CONTROLLER__H
#define __CL_CONTROLLER__H

#include "cl_base.h"
#include "cl_phone.h"

// Класс объекта для чтения данных и команд.
class cl_controller : public cl_base {
	cl_phone* get_phone(string);
	vector <cl_phone*> phones;
public:
	// Метод добавления номера в базу номеров
	void add_phone(string);
	// Метод отображения АТС
	void display_ATC(string);
	// Метод отображения телефона
	void display_phone(string);
	// Метод запроса вызова
	void call_request(string);
	// Метод сигнала
	void signal_output(string&);
	// Конструктор
	cl_controller(cl_base*);
};

#endif