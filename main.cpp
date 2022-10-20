#include <iostream>
#include "tools.h"
#include "emis.h"
using namespace std;

int main(int argc,const char* argv[])
{
	Emis& emis=Emis::getemis();	
	emis.login();
}
