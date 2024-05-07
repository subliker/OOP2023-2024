#ifndef __CL_SYSTEM__H
#define __CL_SYSTEM__H

#include "cl_input.h"

// Класс объекта «система».
class cl_system : public cl_base {
	// Метод сигнала
	void signal_input(string s);
	// Метод обработчика
	void handler();
	// Текущий такт
	int t = 0;
	// Метод обработчика входных данных
	void handle_input(string&);
public:
	// Конструктор класса
	cl_system();
	// Метод построение дерева иерархии
	void build_tree_objects();
	// Метод запуска приложения
	int exec_app();
};

#endif