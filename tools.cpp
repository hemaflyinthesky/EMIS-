#include <getch.h>
#include <stdlib.h>
#include <iostream>
#include "tools.h"
#include "emis.h"

using namespace std;

int get_mgrid(void)  //生成唯一管理员id
{
	return Mgrid=Mgrid+1;
}
int get_deptid(void) //生成唯一部门id
{
	return Deptid=Deptid+1;
}
int get_empid(void)  //生成唯一员工id
{
	return Empid=Empid+1;
}
char* get_str(char* str,size_t len)//从键盘获取字符串
{
	if(str==NULL || len==0) return NULL;
	size_t index=0;
	while(index<len-1)
	{
		char key_val=getch();
		if(key_val==10) break;
		if(key_val==127)
		{
			if(0<index)
			{
				index--;
				printf("\b \b");	//显示退格效果
			}
			continue;
		}
		printf("%c",key_val);
		str[index++]=key_val;
	}
	str[index]='\0';
	printf("\n");
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	return str;
}
char* get_pass(char* pass,size_t len,bool is_show)//从键盘获取密码
{
	if(pass==NULL || len==0) return NULL;
	size_t index=0;
	while(index<len-1)
	{
		char key_val=getch();
		if(key_val==10) break;
		if(key_val==127)
		{
			if(0<index)
			{
				index--;
				if(is_show) printf("\b \b");	//显示退格效果
			}
			continue;
		}
		if(is_show) printf("*");
		pass[index++]=key_val;
	}
	pass[index]='\0';
	printf("\n");
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	return pass;
}
void anykey_continue(void)//按任意键继续
{
	printf("请按任意键继续...");
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	getch();
}
