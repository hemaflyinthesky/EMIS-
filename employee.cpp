#include <iostream>
#include <string.h>
#include "employee.h"
#include "tools.h"

using namespace std;

Employee::Employee(const char* name,const char sex,int age)
{
	m_ild=get_empid();
	strcpy(m_strName,name);
	m_cSex=sex;
	m_iAge=age;
}

void Employee::setid(int id)
{
	m_ild=id;
}

void Employee::setAge(int age)
{
	m_iAge=age;
}

void Employee::setName(const char* name)
{
	strcpy(m_strName,name);
}

void Employee::setSex(char sex)
{
	m_cSex=sex;
}

int Employee::getid(void)
{
	return m_ild;
}

int Employee::getAge(void)
{
	return m_iAge;
}

char* Employee::getName(void)
{
	return m_strName;
}

char Employee::getSex(void)
{
	return m_cSex;
}
