#ifndef MANAGER_MODE_H
#define MANAGER_MODE_H
#include "manager.h"
#include <vector>
using namespace std;
class ManagerMode
{
public:
	virtual ~ManagerMode(void){}
	virtual void load(vector<Manager>& mng)=0;
	virtual void save(vector<Manager>& mng)=0;
};

#endif //MANAGER_MODE_H
