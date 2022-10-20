#include <iostream>
#include <string.h>
#include <vector>
#include "manager_ctrl_impl.h"
#include "tools.h"
using namespace std;

bool ManagerCtrlImpl::addMgr(Manager& mng)
{
	vector<Manager>::iterator it;
	for(it=mgrArr.begin();it!=mgrArr.end();it++)
	{
		if(strcmp(mng.getName(),it->getName())==0)
		{
			return false;
		}
	}
	mgrArr.push_back(mng);
	return true;
}
bool ManagerCtrlImpl::delMgr(int id)
{
	vector<Manager>::iterator it;
	for(it=mgrArr.begin();it!=mgrArr.end();it++)
	{
		if(it->getid()==id)
		{
			mgrArr.erase(it);
			return true;
		}
	}
	return false;
	
}
vector<Manager>& ManagerCtrlImpl::listMgr(void)
{
	return mgrArr;
}
