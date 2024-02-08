#pragma once
#include <string>
#include "user.h"

using namespace std;

class transportComp : protected User {
private:
	string companyName;
public:
	void tcDBStart(); //database initialisation for transport company db file
	void tcReg(); //registration form for tc user
	void tcLogin();
};