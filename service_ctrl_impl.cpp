#include <iostream>
#include <string.h>
#include "service_ctrl_impl.h"
#include <vector>
#include "tools.h"

using namespace std;

bool ServiceCtrlImpl::addDept(Department& dept)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin();it!=deptArr.end();it++)
	{
		if(strcmp(dept.getName(),it->getName())==0)
		{
			return false;
		}
	}
	deptArr.push_back(dept);
	return true;
}
int ServiceCtrlImpl::delDept(int id)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin();it!=deptArr.end();it++)
	{
		if(id==it->getid())
		{
			deptArr.erase(it);
			return true;
		}
	}
	return false;
}
vector<Department>& ServiceCtrlImpl::listDept(void)
{
	return deptArr;
}
bool ServiceCtrlImpl::addEmp(int id,Employee& emp)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin();it!=deptArr.end();it++)
	{
		if(id==it->getid())
		{
			it->empArr.push_back(emp);
			return true;
		}
	}
	return false;
}
bool ServiceCtrlImpl::delEmp(int id)
{
	vector<Department>::iterator it_dept;
	vector<Employee>::iterator it_emp;
	for(it_dept=deptArr.begin();it_dept!=deptArr.end();it_dept++)
	{
		for(it_emp=it_dept->empArr.begin();it_emp!=it_dept->empArr.end();it_emp++)
		{
			if(id==it_emp->getid())
			{
				it_dept->empArr.erase(it_emp);
				return true;
			}
		}
	}
	return false;
}
bool ServiceCtrlImpl::modEmp(int id,Employee& emp)
{
	vector<Department>::iterator it_dept;
	vector<Employee>::iterator it_emp;
	for(it_dept=deptArr.begin();it_dept!=deptArr.end();it_dept++)
	{
		for(it_emp=it_dept->empArr.begin();it_emp!=it_dept->empArr.end();it_emp++)
		{
			if(id==it_emp->getid())
			{
				it_dept->empArr.push_back(emp);
				it_dept->empArr.erase(it_emp);
				return true;
			}
		}
	}
	return false;
}
Department* ServiceCtrlImpl::listEmp(int id)
{
	vector<Department>::iterator it;
	for(it=deptArr.begin();it!=deptArr.end();it++)
	{
		if(id==it->getid())
		{
			return (Department*)(&(*it));
		}
	}
	return NULL;
}
vector<Department>& ServiceCtrlImpl::listAllEmp(void)
{
	return deptArr;
}

