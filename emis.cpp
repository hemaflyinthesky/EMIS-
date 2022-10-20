#include <iostream>
#include <getch.h>
#include <stdlib.h>
#include <fstream>
#include "emis.h"
#include "manager_view_impl.h"
#include "manager_view.h"
#include "manager.h"

#define ID_FILE "id.dat"
using namespace std;
int Mgrid;
int Deptid;
int Empid;

Emis Emis::emis;

Emis::Emis(void)
{
	mgrView=new ManagerViewImpl;
	
	ifstream fin;
	fin.open(ID_FILE);
	if(!fin.good())
	{
		cout << "配置文件出错！请检查！" << endl;
		exit(0);
	}
	fin >> Mgrid;
	fin >> Deptid;
	fin >> Empid;
	fin.close();
}

Emis::~Emis(void)
{
	ofstream fout;
	fout.open(ID_FILE);
	if(!fout.good())
	{
		cout << "文件存储出错！请检查！" << endl;
	}
	fout << Mgrid << endl;
	fout << Deptid << endl;
	fout << Empid << endl;
	fout.close();
	delete mgrView;
}

Emis& Emis::getemis(void)
{
	return emis;
}

void Emis::login(void)
{	
	while(true)
	{
		system("clear");
		puts("                 欢迎使用河马企业管理系统");
 		puts("********************************************************");
		puts("1.超级管理员");
		puts("2.业务管理员");
		puts("3.退出");
		char cmd=getch();
		
		switch(cmd)
		{
			case '1':mgrView->loginManager();break;
			case '2':mgrView->loginService();break;
			case '3':return;
		}
	}	
}
