#ifndef __CL_OUTPUT__H
#define __CL_OUTPUT__H

#include "cl_base.h"
#include "cl_phone.h"

// Класс объекта для чтения данных и команд.
class cl_output : public cl_base {
public:
	// Метод обработчика
	void print(string);
	void print_tree(string);
	// Конструктор
	cl_output(cl_base*);
};

#endif