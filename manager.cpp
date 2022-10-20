#include <iostream>
#include <string.h>
#include "manager.h"
#include "tools.h"
using namespace std;

Manager::Manager(const char* name,const char* pwd)
{
	m_ild=get_mgrid();
	strcpy(m_strName,name);
	strcpy(m_strPwd,pwd);
}
int Manager::getid(void)const
{
	return m_ild;
}
const char* Manager::getName(void)const
{
	return m_strName;
}
const char* Manager::getPwd(void)const
{
	return m_strPwd;
}
void Manager::setid(int id)
{
	m_ild=id;
}
void Manager::setName(const char* name)
{
	strcpy(m_strName,name);
}
void Manager::setPwd(const char* pwd)
{
	strcpy(m_strPwd,pwd);
}
