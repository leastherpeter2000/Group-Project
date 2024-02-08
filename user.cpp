#include <iostream>
#include "user.h"

using namespace std;

//setters
void User::setFName(string fn) {
	fname = fn;
}

void User::setSName(string sn) {
	sname = sn;
}

void User::setUsername(string un) {
	username = un;
}

void User::setPass(string p) {
	password = p;
}

void User::setEmail(string e) {
	email = e;
}

void User::setAddress(string a) {
	address = a;
}

void User::setUType(string ut) {
	userType = ut;
}

void User::setMobileNo(int no) {
	mobileNo = no;
}

void User::setBNo(int bno) {
	businessNo = bno;
}

void User::setBAdd(string badd) {
	businessAdd = badd;
}

//getters
string User::getFName() {
	return fname;
}

string User::getSName() {
	return sname;
}

string User::getUsername() {
	return username;
}

string User::getPass() {
	return password;
}

string User::getEmail() {
	return email;
}

string User::getAddress() {
	return address;
}

string User::getUType() {
	return userType;
}

string User::getMobileNo() {
	return mobileNo;
}

string User::getBNo() {
	return businessNo;
}

string User::getBAdd() {
	return businessAdd;
}