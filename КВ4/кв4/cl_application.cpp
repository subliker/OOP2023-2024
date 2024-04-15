#include "cl_application.h"
//КВ4 
cl_application::cl_application(cl_base* head) :cl_base(head, "", 1) {}

void cl_application::build_tree_objects() {
	string child_name, parent_path, cmnd;
	int ch;
	cl_base* current = this;
	cin >> parent_path;
	this->editName(parent_path);
	while (true) {
		cin.clear();
		cin >> parent_path;
		if (parent_path == "endtree") break;
		cl_base* parent = get(parent_path);
		if (!parent) {
			cout << "Object tree" << endl;
			output_children();
			cout << endl << "The head object " << parent_path << " is not found";
			exit(1);
		}
		cin >> child_name >> ch;
		cl_base* cr = nullptr;
		if (!parent->getChild(child_name)) {
			switch (ch) {
			case 2:
				cr = new cl_2(parent, child_name);
				break;
			case 3:
				cr = new cl_3(parent, child_name);
				break;
			case 4:
				cr = new cl_4(parent, child_name);
				break;
			case 5:
				cr = new cl_5(parent, child_name);
				break;
			case 6:
				cr = new cl_6(parent, child_name);
				break;
			}
			if (cr != nullptr) {
				cr->set_state(1);
			}
		}
		else {
			cout << parent_path << "     Dubbing the names of subordinate objects" << endl;
		}
	}
	cin >> parent_path;
	while (parent_path != "end_of_connections") {
		cl_base* obj1 = get(parent_path);
		cin >> parent_path;
		cl_base* obj2 = get(parent_path);
		obj1->set_connect(get_signal(obj1), obj2, get_handler(obj2));
		cin >> parent_path;
	}
	cout << "Object tree" << endl;
	output_children();
	cout << endl;
}

int cl_application::exec_app() {
	set_ready_branch();
	string child_name, parent_path, cmnd, msg;
	cl_base* current = this;

	while (true) {
		cin >> cmnd;
		if (cmnd == "END") break;
		cin >> parent_path;
		cl_base* obj = current->get(parent_path);
		getline(cin, msg);
		if (cmnd == "SET") {
			if (obj) {
				current = obj;
				cout << "Object is set: " << obj->getName() << endl;
			}
			else {
				cout << "The object was not found at the specified coordinate: " << parent_path << endl;
			}
		}
		else if (cmnd == "FIND") {
			if (obj) {
				cout << parent_path << "     Object name: " << obj->getName() << endl;
			}
			else {
				cout << parent_path << "     Object is not found" << endl;
			}
		}
		else if (cmnd == "MOVE") {
			if (!obj) {
				cout << parent_path << "     Head object is not found" << endl;

			}
			else if (obj->getParent() != current->getParent() && current->find_on_branch(obj->getName())) {
				cout << parent_path << "     Redefining the head object failed" << endl;
			}
			else if (obj->getChild(current->getName())) {
				cout << parent_path << "     Dubbing the names of subordinate objects" << endl;
			}
			else if (!current->setParent(obj)) {
				cout << parent_path << "     Redefining the head object failed" << endl;
			}
			else {
				cout << "New head object: " << obj->getName() << endl;
			}
		}
		else if (cmnd == "DELETE") {
			if (obj) {
				cl_base* parent = obj->getParent();
				string path;
				current->removeChild(obj->getName());
				while (parent != nullptr) {
					if (parent->getParent()) path += "/" + parent->getName();
					parent = parent->getParent();
				}
				cout << "The object " << path + "/" + parent_path << " has been deleted" << endl;
			}
		}
		else if (cmnd == "EMIT") {
			if (obj->get_state()) {
				obj->emit_signal(get_signal(obj), msg);
			}
		}
		else if (cmnd == "SET_CONDITION") {
			obj->set_state(stoi(msg));
		}
		else {
			cl_base* obj2 = get(msg.substr(1));
			if (obj2 == nullptr) {
				cout << endl << "Handler object " << msg << " not found";
				continue;
			}
			if (cmnd == "SET_CONNECT") {
				obj->set_connect(get_signal(obj), obj2, get_handler(obj2));
			}
			else if (cmnd == "DELETE_CONNECT") {
				obj->break_connection(get_signal(obj), obj2, get_handler(obj2));
			}
		}
	}
	return 0;
}

// Метод получения сигнала
TYPE_SIGNAL cl_application::get_signal(cl_base* obj) {
	switch (obj->get_cl_n()) {
	case 1:
		return SIGNAL_D(cl_1::signal);
	case 2:
		return SIGNAL_D(cl_2::signal);
	case 3:
		return SIGNAL_D(cl_3::signal);
	case 4:
		return SIGNAL_D(cl_4::signal);
	case 5:
		return SIGNAL_D(cl_5::signal);
	case 6:
		return SIGNAL_D(cl_6::signal);
	}
	return nullptr;
}

// Метод получения обработчика
TYPE_HANDLER cl_application::get_handler(cl_base* obj) {
	switch (obj->get_cl_n()) {
	case 1:
		return HANDLER_D(cl_1::handler);
	case 2:
		return HANDLER_D(cl_2::handler);
	case 3:
		return HANDLER_D(cl_3::handler);
	case 4:
		return HANDLER_D(cl_4::handler);
	case 5:
		return HANDLER_D(cl_5::handler);
	case 6:
		return HANDLER_D(cl_6::handler);
	}
	return nullptr;
}