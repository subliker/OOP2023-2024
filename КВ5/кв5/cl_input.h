#ifndef __CL_INPUT__H
#define __CL_INPUT__H

#include "cl_base.h"

// Класс объекта для чтения данных и команд.
class cl_input : public cl_base {
public:
	// Метод сигнала
	void signal(string s);
	// Метод обработчика
	void handler(string& s);
	// Конструктор
	cl_input(cl_base*, TYPE_HANDLER);
	// Метод чтения данных
	void read();
};

#endif