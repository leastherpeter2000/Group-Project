#pragma once
#include <string>
#include "user.h"

using namespace std;

class Driver : protected User {
private:
	string NIno;
	string licenceNo;
public:
	void driverDBStart();
	void driverReg();
	void driverLogin();
};