#ifndef __CL_4__H
#define __CL_4__H
#include "cl_base.h"

class cl_4 : public cl_base {
public:
	cl_4(cl_base*, string);

	// Метод сигнала
	void signal(string&);
	// Метод обработчика
	void handler(string);
};

#endif
