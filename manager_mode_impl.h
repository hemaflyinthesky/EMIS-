#ifndef MANAGER_MODE_IMPL_H
#define MANAGER_MODE_IMPL_H

#include <vector>
#include "manager_mode.h"
class ManagerModeImpl:public ManagerMode
{
public:
	void load(vector<Manager>& mng);
	void save(vector<Manager>& mng);
};


#endif //MANAGER_MODE_IMPL_H
