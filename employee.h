#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

class Employee
{
	int m_ild;
	int m_iAge;
	char m_strName[20];
	char m_cSex;
public:
	Employee(void){}
	Employee(const char* name,const char m_cSex,int m_iAge);
	void setid(int id);
	void setAge(int age);
	void setName(const char* name);
	void setSex(char sex);
	int getid(void);
	int getAge(void);
	char* getName(void);
	char getSex(void);
	friend ostream& operator<<(ostream& os,const Employee& emp)
	{
		return os << emp.m_ild << " " << emp.m_strName << " " << emp.m_cSex << " " << emp.m_iAge;
	}
	friend istream& operator>>(istream& is,Employee& emp)
	{
		return is >> emp.m_ild >> emp.m_strName >> emp.m_cSex >> emp.m_iAge;
	}
};


#endif //EMPLOYEE_H
