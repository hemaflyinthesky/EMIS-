#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <getch.h>
#include <vector>
#include "emis.h"
#include "manager_view_impl.h"
#include "tools.h"
using namespace std;

void ManagerViewImpl::loginManager(void)
{
	cout << "请输入帐号:" << endl;
	char name[20]={},pwd[20]={};
	get_str(name,20);
	vector<Manager>::iterator it;
	for(it=mgrCtrl->listMgr().begin();it!=mgrCtrl->listMgr().end();it++)
	{
		if(strcmp(it->getName(),name)==0)
		{
			cout << "请输入密码" << endl;
			get_pass(pwd,20,true);
			if(strcmp(it->getPwd(),pwd)==0)
			{
				cout << "登录成功！" << endl;
				menuMgr();
				return;
			}
			else
			{
				cout << "密码错误，请重新输入！" << endl;
				return;
			}
		}
	}
	cout << "用户不存在，请重新输入！" << endl;
	return;
}
void ManagerViewImpl::loginService(void)
{
	cout << "请输入帐号:" << endl;
	char name[20]={},pwd[20]={};
	get_str(name,20);
	vector<Manager>::iterator it;
	for(it=mgrCtrl->listMgr().begin();it!=mgrCtrl->listMgr().end();it++)
	{
		if(strcmp(it->getName(),name)==0)
		{
			cout << "请输入密码" << endl;
			get_pass(pwd,20,true);
			if(strcmp(it->getPwd(),pwd)==0)
			{
				cout << "登录成功！" << endl;
				srcView->menuSrc();
				return;
			}
			else
			{
				cout << "密码错误，请重新输入！" << endl;
				return;
			}
		}
	}
	cout << "用户不存在，请重新输入！" << endl;
	return;
}
void ManagerViewImpl::menuMgr(void)
{
	while(true)
	{
		system("clear");
		puts("	         欢迎您，尊敬的超级管理员，请选择您要进行的业务");
		puts("********************************************************************");
		puts("1.添加管理员");
		puts("2.删除管理员");
		puts("3.展示所有管理员");
		puts("4.退出");
		char cmd=getch();
		switch(cmd)
		{
			case '1':addMgr();break;
			case '2':delMgr();break;
			case '3':listMgr();break;
			case '4':return;
		}
	}
}
void ManagerViewImpl::addMgr(void)
{
	cout << "请输入要添加管理员的帐号、密码" << endl;
	char name[20]={},pwd[20]={};
	get_str(name,20);
	get_pass(pwd,20,false);
	Manager mng(name,pwd);
	if(mgrCtrl->addMgr(mng)) cout << "添加成功！" << endl;
	else 
	{
		cout << "帐号已存在，添加失败！" << endl;
		Mgrid--;
	}
	anykey_continue();
}
void ManagerViewImpl::delMgr(void)
{
	cout << "请输入要删除管理员的ID号" << endl;
	int id=0;
	cin >> id;
	if(mgrCtrl->delMgr(id)) cout << "删除成功！" << endl;
	else cout << "账户不存在" << endl;
	anykey_continue();
}
void ManagerViewImpl::listMgr(void)
{
	vector<Manager>::iterator it;
	for(it=mgrCtrl->listMgr().begin();it!=mgrCtrl->listMgr().end();it++)
	{
		cout << it->getName() << " " << it->getPwd() << " " << it->getid() << endl;
	}
	anykey_continue();
}
