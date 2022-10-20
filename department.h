#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>    
#include <vector>
#include <string.h>
#include "tools.h"
#include "employee.h"
using namespace std;

class Department
{
	int m_ild;
	char m_strName[20];
public:
	vector<Employee> empArr;
	Department(void){}
	Department(const char* name)
	{
		m_ild=get_deptid();
		strcpy(m_strName,name);
	}
	~Department(void){}
	void setid(int id);
	void setName(char* name);
	int getid(void);
	char* getName(void);
	friend ostream& operator<<(ostream& os,const Department& dept)
	{
		return os << dept.m_ild << " " << dept.m_strName << " " << dept.empArr.size();
	}
	friend istream& operator>>(istream& is,Department& dept)
	{
		return is >> dept.m_ild >> dept.m_strName;
	}
};

#endif //DEPARTMENT_H
