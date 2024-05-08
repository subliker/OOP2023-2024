#ifndef __CL_SYSTEM__H
#define __CL_SYSTEM__H

#include "cl_input.h"
#include "cl_controller.h"
#include "cl_output.h"
#include <iostream>
using namespace std;

// Класс объекта «система».
class cl_system : public cl_base {
	// Метод сигнала
	void signal_output(string&);
	void signal_display_ATC(string&);
	void signal_controller(string&);
	void signal_read_cmnd(string&);
	void signal_display_phone(string&);
	void signal_call_request(string&);

	// Метод обработчика
	void handler_cmnd(string);
	// Текущий такт
	int t = 0;
public:
	// Конструктор класса
	cl_system(cl_base*);
	// Метод построение дерева иерархии
	void build_tree_objects();
	// Метод запуска приложения
	int exec_app();
};

#endif