#ifndef MANAGER_H
#define MANAGER_H

#include <vector>

class Manager
{
	int m_ild;           //管理员id
	char m_strName[20];	 //管理员帐号
	char m_strPwd[20];   //管理员密码
public:
	Manager(void){}
	Manager(const char* name,const char* pwd);
	int getid(void)const;
	const char* getName(void)const;
	const char* getPwd(void)const;
	void setid(int id);
	void setName(const char* name);
	void setPwd(const char* pwd);
};

#endif //MANAGER_H
