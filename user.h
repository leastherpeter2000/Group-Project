#pragma once
#include <string>

using namespace std;


class User {
protected: 
	int userID;
	string fname;
	string sname;
	string username;
	string password;
	string email;
	string address;
	string businessAdd;
	string userType;
	string mobileNo;
	string businessNo;
public:
	//setter
	void setFName(string fn);
	void setSName(string sn);
	void setUsername(string un);
	void setPass(string p);
	void setEmail(string e);
	void setAddress(string a);
	void setUType(string ut);
	void setMobileNo(int no);
	void setBNo(int bno);
	void setBAdd(string badd);

	//getter
	string getFName();
	string getSName();
	string getUsername();
	string getPass();
	string getEmail();
	string getAddress();
	string getUType();
	string getMobileNo();
	string getBNo();
	string getBAdd();
};