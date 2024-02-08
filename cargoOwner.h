#pragma once
#include <string>
#include "user.h"

using namespace std;

class cargoOwner : protected User {
protected:
	int caOwID;
public:
	void cargoOwnerDBStart();
	void cargoOwnerReg();
	void cargoOwnerLogin();
	void fetchUserID(string username, string password);
	int getUserID() const { return caOwID; }
};