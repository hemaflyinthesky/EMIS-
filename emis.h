#ifndef EMIS_H
#define EMIS_H

#include "manager_view.h"
#include "service_view.h"
#include "service_view_impl.h"

class Emis
{
	ManagerView* mgrView;
	static Emis emis;
	Emis(void);
	Emis(const Emis& that){}
public:
	~Emis(void);
	static Emis& getemis(void);
	void login(void);
};


extern int Mgrid;
extern int Deptid;
extern int Empid;

#endif //EMIS_H
