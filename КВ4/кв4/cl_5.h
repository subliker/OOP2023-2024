#ifndef __CL_5__H
#define __CL_5__H
#include "cl_base.h"

class cl_5 : public cl_base {
public:
	cl_5(cl_base*, string);

	// Метод сигнала
	void signal(string&);
	// Метод обработчика
	void handler(string);
};

#endif
