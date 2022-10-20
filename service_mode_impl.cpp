#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "service_mode_impl.h"
#include <vector>
#include "department.h"
#include "employee.h"

#define SERVI_FILE "services.dat"
using namespace std;
void ServiceModeImpl::load(vector<Department>& dept)
{
	
	ifstream fin;
	fin.open(SERVI_FILE);
	if(!fin.good())
	{
		cout << "配置文件出错！请检查！" << endl;
		exit(0);
	}
	Department new_department;
	
	Employee new_employee;
	int id=0;
	char name[20]={};
	vector<Department>::iterator it_dept;
	dept.reserve(256);
	int buf=0;
	while(true)
	{
		fin >> id;
		fin >> name;
		fin >> buf;	
		if(fin.eof()) break;
		new_department.setid(id);
		new_department.setName(name);
		dept.push_back(new_department);	
		if(dept.size()==1) 
		{
			it_dept=dept.begin();
		}
		for(int i=0;i<buf;i++)
		{
			fin >> new_employee;
			it_dept->empArr.push_back(new_employee);			
		}		
		it_dept++;	
	}
	
	fin.close();
}
void ServiceModeImpl::save(vector<Department>& dept)
{
	ofstream fout;
	fout.open(SERVI_FILE);
	if(!fout.good())
	{
		cout << "部门、员工信息存储出错！请检查！" << endl;
	}
	vector<Department>::iterator it_dept;
	vector<Employee>::iterator it_emp;
	while(!dept.empty())
	{
		it_dept=dept.end();
		it_dept--;
		fout << *it_dept << endl;
		for(it_emp=it_dept->empArr.begin();it_emp!=it_dept->empArr.end();it_emp++)
		{
			fout << *it_emp << endl;
		}
		it_dept->empArr.clear();
		dept.pop_back();
	}
	fout.close();
}
