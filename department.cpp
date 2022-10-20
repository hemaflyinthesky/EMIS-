#include "department.h"  

using namespace std;

void Department::setid(int id)
{
	m_ild=id;
}

void Department::setName(char* name)
{
	strcpy(m_strName,name);
}

int Department::getid(void)
{
	return m_ild;
}

char* Department::getName(void)
{
	return m_strName;
}
