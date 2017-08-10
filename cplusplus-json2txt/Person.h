#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;


class Person {
	public:
		int ID;
		string FirstName, LastName, Email, BTCAddress, IPAddress;
		void set_values(int, string, string, string, string, string);
		string full_name();
};

void Person::set_values(int i, string fn, string ln, string em, string btc, string ip) {
	ID = i;
	FirstName = fn;
	LastName = ln;
	Email = em;
	BTCAddress = btc;
	IPAddress = ip;
}

string Person::full_name() {
	return FirstName + " " + LastName;
}

#endif