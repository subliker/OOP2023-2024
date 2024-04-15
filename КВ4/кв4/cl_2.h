#ifndef __CL_2__H
#define __CL_2__H
#include "cl_base.h"

class cl_2 : public cl_base {
public:
	cl_2(cl_base*, string);

	// Метод сигнала
	void signal(string&);
	// Метод обработчика
	void handler(string);
};

#endif
