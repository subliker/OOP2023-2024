#ifndef __CL_BASE__H
#define __CL_BASE__H
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

class cl_base;

#define SIGNAL_D(signal_f)(TYPE_SIGNAL)(&signal_f)
#define HANDLER_D(handler_f)(TYPE_HANDLER)(&handler_f)
typedef void (cl_base ::* TYPE_SIGNAL)(string&);
typedef void (cl_base ::* TYPE_HANDLER)(string);


class cl_base {
protected:
	string s_object_name;
	cl_base* p_head_object;
	vector < cl_base* > subordinate_objects;
	int state = 0;
	int cl_n = 0;

	// КВ 4
	struct o_sh {
		TYPE_SIGNAL p_signal;
		cl_base* p_cl_base;
		TYPE_HANDLER p_handler;
	};
public:
	string getName();
	cl_base* getParent();
	bool setParent(cl_base*);
	bool editName(string new_name);
	cl_base* getChild(string);
	void removeChild(string);
	cl_base* find_on_branch(string, int* = nullptr);
	cl_base* find_on_tree(string);
	cl_base(cl_base* p_head_object, string s_object_name);
	~cl_base();
	void output_children(int = 3);
	void output_state(int = 3);
	void set_state(int);
	cl_base* get(string);

	// КВ4

	// Метод получения абсолютного пути
	string path();
	// Вектор для хранения установленных связей
	vector < o_sh* > connects;
	// Метод установи связи
	void set_connect(TYPE_SIGNAL, cl_base*, TYPE_HANDLER);
	// Метод выдачи сигнала и отработки соответствующих обработчиков
	void emit_signal(TYPE_SIGNAL, string&);
	// Метод удаления (разрыва) связи между сигналом текущего объекта и обработчиком целевого объекта
	void break_connection(TYPE_SIGNAL, cl_base*, TYPE_HANDLER);

	// Получение состояния
	int get_state();
	// Получение номера класса
	int get_cl_n();
	// Установка готовности дереву объектов
	void set_ready_branch();
};

#endif
