#ifndef __CL_6__H
#define __CL_6__H
#include "cl_base.h"

class cl_6 : public cl_base {
public:
	cl_6(cl_base*, string);

	// Метод сигнала
	void signal(string&);
	// Метод обработчика
	void handler(string);
};


#endif
