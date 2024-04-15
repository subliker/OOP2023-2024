#include "cl_base.h"
#include <iostream>
using namespace std;

cl_base::~cl_base() {
	for (auto child : subordinate_objects) {
		delete child;
	}
}

bool cl_base::editName(string new_name) {
	if (getParent() != nullptr && getParent()->getChild(new_name) != nullptr) {
		return false;
	}
	s_object_name = new_name;
	return true;
}

cl_base* cl_base::find_on_branch(string name, int* s) {
	int a = 0;
	if (s == nullptr) {
		s = &a;
	}
	cl_base* fnd = nullptr;
	if (s_object_name == name) {
		fnd = this;
		(*s)++;
	}

	for (cl_base* child : subordinate_objects) {
		cl_base* f_child = child->find_on_branch(name, s);
		if (f_child) {
			fnd = f_child;
		}
	}
	if ((*s) == 1 && fnd) {
		return fnd;
	}
	return nullptr;
}

cl_base* cl_base::find_on_tree(string name) {
	cl_base* f_head = this;
	while (f_head->getParent() != nullptr) {
		f_head = f_head->getParent();
	}
	return f_head->find_on_branch(name);
}

void cl_base::output_children(int spaces) {
	cout << s_object_name;
	if (!subordinate_objects.empty()) {
		for (cl_base* child : subordinate_objects) {
			cout << endl;
			for (int i = 0; i <= spaces; i++) {
				cout << " ";
			}
			child->output_children(spaces + 4);
		}
	}
}

void cl_base::output_state(int spaces) {
	cout << s_object_name;
	if (state == 0) {
		cout << " is not ready";
	}
	else {
		cout << " is ready";
	}

	if (!subordinate_objects.empty()) {
		for (cl_base* child : subordinate_objects) {
			cout << endl;
			for (int i = 0; i <= spaces; i++) {
				cout << " ";
			}
			child->output_state(spaces + 4);
		}
	}
}

cl_base* cl_base::getChild(string s_object_name) {
	for (int i = 0; i < this->subordinate_objects.size(); i++) {
		if (s_object_name == this->subordinate_objects[i]->s_object_name) {
			return 	this->subordinate_objects[i];
		}
	}
	return nullptr;
}

string cl_base::getName() {
	return this->s_object_name;
}

cl_base* cl_base::getParent() {
	return p_head_object;
}

void cl_base::set_state(int state) {
	if (p_head_object && p_head_object->state == 0) {
		this->state = 0;
	}
	else {
		this->state = state;
	}
	if (state == 0) {
		for (cl_base* child : subordinate_objects) {
			child->set_state(0);
		}
	}
}

bool cl_base::setParent(cl_base* head) {
	if (p_head_object == nullptr || head == nullptr) return false;
	if (head->getChild(getName())) return false;
	cl_base* current = head;
	while (current->getParent()) {
		if (current == this) return false;
		current = current->getParent();
	}

	for (auto i = (p_head_object->subordinate_objects).begin(); i != (p_head_object->subordinate_objects).end(); i++) {
		if (*i == this) {
			(p_head_object->subordinate_objects).erase(i);
			break;
		}
	}
	p_head_object = head;
	(p_head_object->subordinate_objects).push_back(this);
	return true;
}

void cl_base::removeChild(string name) {
	cl_base* el = getChild(name);
	for (auto i = subordinate_objects.begin(); i != subordinate_objects.end(); i++) {
		if ((*i) == el) {
			subordinate_objects.erase(i);
			delete el;
			return;
		}
	}
	return;
}

cl_base* cl_base::get(string path) {
	cl_base* current = this;
	string next;
	if (path.substr(0, 1) == "/") {
		if (path.substr(1, 1) == "/") {
			return find_on_tree(path.substr(2));
		}
		while (current->getParent() != nullptr) {
			current = current->getParent();
		}
		path = path.substr(1);
	}
	else if (path.substr(0, 1) == ".") {
		if (path == ".") {
			return current;
		}
		else {
			return find_on_branch(path.substr(1));
		}
	}
	stringstream sPath(path);
	while (getline(sPath, next, '/')) {
		current = current->getChild(next);
		if (!current) {
			return nullptr;
		}
	}
	return current;
}

// КВ4

// Метод получения абсолютного пути
string cl_base::path() {
	if (!getParent()) {
		return "/";
	}
	string p = getName();
	cl_base* current = getParent();
	while (current&&current->getParent()) {
		p = current->getName() + "/" + p;
		current = current->getParent();
	}
	return "/" + p;
}

// Метод установи связи между сигналом текущего объекта и обработчиком целевого объекта
void cl_base::set_connect(TYPE_SIGNAL p_signal, cl_base* p_object, TYPE_HANDLER   p_ob_handler)
{
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
void cl_base::emit_signal(TYPE_SIGNAL p_signal, string & s_command){
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

cl_base::cl_base(cl_base* p_head_object, string s_object_name, int cl_n) {
	this->p_head_object = p_head_object;
	this->s_object_name = s_object_name;
	this->cl_n = cl_n;
	if (p_head_object) {
		p_head_object->subordinate_objects.push_back(this);
	}
}

// Получение состояния
int cl_base::get_state() { 
	return state;
}

// Получение номера класса
int cl_base::get_cl_n() {
	return cl_n;
}

// Установка готовности дереву объектов
void cl_base::set_ready_branch() {
	this->set_state(1);
	for (auto child : subordinate_objects) {
		child->set_ready_branch();
	}
}