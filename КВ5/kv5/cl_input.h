#ifndef __CL_INPUT__H
#define __CL_INPUT__H

#include "cl_base.h"

// Класс объекта для чтения данных и команд.
class cl_input : public cl_base {
public:
	// Конструктор
	cl_input(cl_base*);
	// Метод чтения данных
	void read_data(string&);
	// Метод чтения комманд
	void read_command(string&);
	// Метод сигнала
	void signal_cmnd_handler(string&);
};

#endif