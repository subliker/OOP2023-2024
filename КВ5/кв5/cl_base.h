#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <iostream>
#include <vector>
using namespace std;

class cl_base;

#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(&signal_f)
#define HANDLER_D(handler_f)(TYPE_HANDLER)(&handler_f)
typedef void (cl_base ::* TYPE_SIGNAL)(string&);
typedef void (cl_base ::* TYPE_HANDLER)(string);

// Класс объекта, работающего с сигналами и обработчиками
class cl_base {
	struct o_sh {
		TYPE_SIGNAL p_signal;
		cl_base* p_cl_base;
		TYPE_HANDLER p_handler;
	};
protected:
	// Метод сигнала
	void signal();
	// Метод обработчика
	void handler();
	int state;
public:
	// Вектор для хранения установленных связей
	vector < o_sh* > connects;
	// Метод установи связи
	void set_connect(TYPE_SIGNAL, cl_base*, TYPE_HANDLER);
	// Метод выдачи сигнала и отработки соответствующих обработчиков
	void emit_signal(TYPE_SIGNAL, string&);
	// Метод удаления (разрыва) связи между сигналом текущего объекта и обработчиком целевого объекта
	void break_connection(TYPE_SIGNAL, cl_base*, TYPE_HANDLER);
};

#endif