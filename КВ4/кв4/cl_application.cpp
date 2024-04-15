#include "cl_application.h"
#include <iostream>
using namespace std;

cl_application::cl_application(cl_base* head) :cl_1(head, "") {}

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
		if (!parent->getChild(child_name)) {
			switch (ch) {
			case 2:
				new cl_2(parent, child_name);
				break;
			case 3:
				new cl_3(parent, child_name);
				break;
			case 4:
				new cl_4(parent, child_name);
				break;
			case 5:
				new cl_5(parent, child_name);
				break;
			case 6:
				new cl_6(parent, child_name);
				break;
			}
		}
		else {
			cout << parent_path << "     Dubbing the names of subordinate objects" << endl;
		}
	}
	cout << "Object tree" << endl;
	output_children();
	cout << endl;
	while (true) {
		cin >> cmnd;
		if (cmnd == "END") break;
		cin >> parent_path;
		cl_base* obj = current->get(parent_path);
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
	}
}

int cl_application::exec_app() {
	cout << "Current object hierarchy tree" << endl;
	output_children();
	return 0;
}