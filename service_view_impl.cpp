#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <getch.h>
#include <vector>
#include "service_view_impl.h"
#include "tools.h"
#include "department.h"
#include "employee.h"
#include "emis.h"
using namespace std;

void ServiceViewImpl::menuSrc(void)
{
	while(true)
	{
		system("clear");
		puts("	         欢迎您，尊敬的业务管理员，请选择您要进行的业务");
		puts("********************************************************************");
		puts("1.添加部门");
		puts("2.删除部门");
		puts("3.查看所有部门");
		puts("4.添加员工");
		puts("5.删除员工");	
		puts("6.修改员工信息");
		puts("7.查看部门内员工");
		puts("8.查看所有员工");
		puts("9.退出");
		char cmd=getch();
		switch(cmd)
		{
			case '1':addDept();break;
			case '2':delDept();break;
			case '3':listDept();break;
			case '4':addEmp();break;
			case '5':delEmp();break;
			case '6':modEmp();break;
			case '7':listEmp();break;
			case '8':listAllEmp();break;
			case '9':return;
		}
	}
}

void ServiceViewImpl::addDept(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	cout << "请输入要添加的部门名称" << endl;
	char name[20]={};
	cin >> name;
	Department dept(name);
	if(srcCtrl->addDept(dept)) cout << "添加成功！" << endl;
	else 
	{
		cout << "该部门已存在！" << endl;
		Deptid--;
	}
	anykey_continue();
}

void ServiceViewImpl::delDept(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	cout << "请输入要删除部门的ID号" << endl;
	int id=0;
	cin >> id;
	if(srcCtrl->delDept(id)) cout << "删除成功！" << endl;
	else cout << "部门号不存在" << endl;
	anykey_continue();
}

void ServiceViewImpl::listDept(void)
{
	vector<Department>::iterator it;
	for(it=srcCtrl->listDept().begin();it!=srcCtrl->listDept().end();it++)
	{
		cout << *it << endl;
	}
	anykey_continue();
}

void ServiceViewImpl::addEmp(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	cout << "请输入要添加员工的姓名、性别、年龄、所属部门的ID号" << endl;
	char name[20]={},sex=0;
	int id=0,age=0;
	cin >> name >> sex >> age >> id;
	Employee emp(name,sex,age);
	if(srcCtrl->addEmp(id,emp)) cout << "添加成功！" << endl;
	else 
	{
		cout << "部门不存在，添加失败！" << endl;
		Empid--;
	}
	anykey_continue();
}

void ServiceViewImpl::delEmp(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	cout << "请输入要删除员工的ID号" << endl;
	int id=0;
	cin >> id;
	if(srcCtrl->delEmp(id)) cout << "删除成功！" << endl;
	else cout << "员工ID号不存在！" << endl;
	anykey_continue();
}

void ServiceViewImpl::modEmp(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	cout << "请输入要修改的员工的ID号" << endl;
	int id=0,age=0;
	char name[20]={},sex=0;
	cin >> id;
	cout << "请输入修改后员工的姓名、性别、年龄" << endl;
	cin >> name >> sex >>age;
	Employee emp;
	emp.setid(id);
	emp.setAge(age);
	emp.setName(name);
	emp.setSex(sex);
	if(srcCtrl->modEmp(id,emp)) cout << "修改成功！" << endl;
	else
	{
		cout << "员工ID号不存在，修改失败！" << endl;	
	}
	anykey_continue();
}
void ServiceViewImpl::listEmp(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	cout << "请输入部门ID" << endl;
	int id=0;
	cin >> id;
	Department* dept=srcCtrl->listEmp(id);
	if(dept==NULL)
	{
	 	cout << "部门不存在" << endl;
		anykey_continue();
		return;
	}
	vector<Employee>::iterator it;
	for(it=dept->empArr.begin();it!=dept->empArr.end();it++)
	{
		cout << *it << endl;
	} 
	anykey_continue();
}
void ServiceViewImpl::listAllEmp(void)
{
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	vector<Department>::iterator it_dept;
	vector<Employee>::iterator it_emp;
	for(it_dept=srcCtrl->listAllEmp().begin();it_dept!=srcCtrl->listAllEmp().end();it_dept++)
	{
		cout << *it_dept << endl;
		for(it_emp=it_dept->empArr.begin();it_emp!=it_dept->empArr.end();it_emp++)
		{
			cout << *it_emp << endl;		
		}
		cout << endl;
	}
	anykey_continue();
}
