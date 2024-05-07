#include "cl_base.h"

// Метод установи связи между сигналом текущего объекта и обработчиком целевого объекта
void cl_base::set_connect(TYPE_SIGNAL p_signal, cl_base* p_object, TYPE_HANDLER   p_ob_handler) {
	o_sh* p_value;
	for (unsigned int i = 0; i < connects.size(); i++)
	{
		if (connects[i]->p_signal == p_signal &&
			connects[i]->p_cl_base == p_object &&
			connects[i]->p_handler == p_ob_handler)
		{
			return;
		}
	}

	p_value = new o_sh();                 // создание объекта структуры для
	// хранения информации о новой связи
	p_value->p_signal = p_signal;
	p_value->p_cl_base = p_object;
	p_value->p_handler = p_ob_handler;

	connects.push_back(p_value);          // добавление новой связи                 
}

// Метод выдачи сигнала от текущего объекта с передачей строковой переменной
void cl_base::emit_signal(TYPE_SIGNAL p_signal, string& s_command) {
	TYPE_HANDLER   p_handler;
	cl_base* p_object;
	// если отключен
	if (this->state == 0) return;

	(this->*p_signal) (s_command);  // вызов метода сигнала

	for (unsigned int i = 0; i < connects.size(); i++) // цикл по всем обработчикам
	{
		if (connects[i]->p_signal == p_signal)      // определение допустимого обработчика
		{
			p_object = connects[i]->p_cl_base;
			if (p_object->state == 0) continue;

			p_handler = connects[i]->p_handler;

			(p_object->*p_handler) (s_command);      // вызов метода обработчика
		}
	}
}

// Метод удаления (разрыва) связи между сигналом текущего объекта и обработчиком целевого объекта
void cl_base::break_connection(TYPE_SIGNAL p_signal, cl_base* p_object, TYPE_HANDLER p_ob_handler) {
	for (auto i = connects.begin(); i != connects.end(); i++) {
		o_sh* c = *i;
		if (c->p_cl_base == p_object &&
			c->p_handler == p_ob_handler &&
			c->p_signal == p_signal) {
			connects.erase(i);
			delete c;
			return;
		}
	}
}
