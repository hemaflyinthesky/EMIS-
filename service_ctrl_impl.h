#ifndef SERVICE_CTRL_IMPL_H
#define SERVICE_CTRL_IMPL_H

#include <vector>
#include "service_ctrl.h"
#include "service_mode.h"
#include "service_mode_impl.h"
using namespace std;
class ServiceCtrlImpl:public ServiceCtrl
{
	ServiceMode* srcMode;
	vector<Department> deptArr;
public:
	ServiceCtrlImpl(void)
	{
		
		srcMode=new ServiceModeImpl;
		srcMode->load(deptArr);
	}
	~ServiceCtrlImpl(void)
	{
		srcMode->save(deptArr);
		delete srcMode;
	}
	bool addDept(Department& dept);
	int delDept(int id);
	vector<Department>& listDept(void);
	bool addEmp(int id,Employee& emp);
	bool delEmp(int id);
	bool modEmp(int id,Employee& emp);
	Department* listEmp(int id);
	vector<Department>& listAllEmp(void);
};

#endif //SERVICE_CTRL_IMPL_H
