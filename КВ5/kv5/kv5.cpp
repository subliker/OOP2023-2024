#include "cl_system.h"

int main()
{
	cl_system ob_cl_system (nullptr);
	ob_cl_system.build_tree_objects();
	return ob_cl_system.exec_app();
}
