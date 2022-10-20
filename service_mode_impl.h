#ifndef SERVICE_MODE_IMPL_H
#define SERVICE_MODE_IMPL_H
#include <vector>
#include "department.h"
#include "service_mode.h"

using namespace std;

class ServiceModeImpl:public ServiceMode
{
public:
	void load(vector<Department>& dept);
	void save(vector<Department>& dept);
};

#endif //SERVICE_MODE_IMPL_H
