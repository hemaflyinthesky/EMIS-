#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include "manager_mode_impl.h"
#include "manager.h"
using namespace std;

#define MNG_FILE "managers.dat"

void ManagerModeImpl::load(vector<Manager>& mng)
{
	
	ifstream fin;
	fin.open(MNG_FILE);
	if(!fin.good())
	{
		cout << "配置文件出错！请检查！" << endl;
		exit(0);
	}
	Manager new_manager;
	int id=0;
	char name[20]={};
	char pwd[20]={};
	while(true)
	{
		fin >> id;
		fin >> name;
		fin >> pwd;	
		if(fin.eof()) break;
		new_manager.setid(id);
		new_manager.setName(name);
		new_manager.setPwd(pwd);
		mng.push_back(new_manager);
	}
	fin.close();
}
void ManagerModeImpl::save(vector<Manager>& mng)
{
	ofstream fout;
	fout.open(MNG_FILE);
	vector<Manager>::iterator it;
	while(!mng.empty())
	{
		it=mng.end();
		it--;
		fout << it->getid() << " " << it->getName() << " " << it->getPwd() << endl;
		mng.pop_back();
	}
	fout.close();
}
