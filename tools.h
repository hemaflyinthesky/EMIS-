#ifndef TOOLS_H
#define TOOLS_H

int get_mgrid(void);  //生成唯一管理员id
int get_deptid(void); //生成唯一部门id
int get_empid(void);  //生成唯一员工id
char* get_str(char* str,size_t len);//从键盘获取字符串
char* get_pass(char* pass,size_t len,bool is_show);//从键盘获取密码
void anykey_continue(void);//按任意键继续

#endif //TOOLS_H
