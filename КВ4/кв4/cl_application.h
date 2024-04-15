#ifndef __CL_APPLICATION__H
#define __CL_APPLICATION__H
#include <string>
#include "cl_base.h"
#include "cl_1.h"	
#include "cl_2.h"	
#include "cl_3.h"	
#include "cl_4.h"	
#include "cl_5.h"	
#include "cl_6.h"	

using namespace std;

class cl_application : public cl_base {
public:
	cl_application(cl_base*);
	void build_tree_objects();
	int exec_app();
	// ��4
	TYPE_SIGNAL get_signal(cl_base*);
	TYPE_HANDLER get_handler(cl_base*);
};

#endif
