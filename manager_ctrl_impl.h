#ifndef MANAGER_CTRL_IMPL_H
#define MANAGER_CTrL_IMPL_H

#include <vector>
#include "manager_ctrl.h"
#include "manager_mode.h"
#include "manager_mode_impl.h"
using namespace std;
class ManagerCtrlImpl:public ManagerCtrl
{
	vector<Manager> mgrArr;
	ManagerMode* mgrMode;
public:
	ManagerCtrlImpl(void)
	{
		
		mgrMode=new ManagerModeImpl;
		mgrMode->load(mgrArr);
	}
	~ManagerCtrlImpl(void)
	{
		mgrMode->save(mgrArr);
		delete mgrMode;
	}
	bool addMgr(Manager& mng);
	bool delMgr(int id);
	vector<Manager>& listMgr(void);
};

#endif //MANAGER_CTRL_IMPL_H
