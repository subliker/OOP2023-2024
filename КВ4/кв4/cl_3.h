#ifndef __CL_3__H
#define __CL_3__H
#include "cl_base.h"

class cl_3 : public cl_base {
public:
	cl_3(cl_base*, string);

	// Метод сигнала
	void signal(string&);
	// Метод обработчика
	void handler(string);
};

#endif
