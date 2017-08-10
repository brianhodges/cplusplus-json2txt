// cplusplus-json2txt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Person.h"
#include <cstdio>
#include <stdlib.h> 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"


int _tmain(int argc, _TCHAR* argv[])
{
	using boost::property_tree::ptree;
	std::ifstream jsonFile("data.json");
	ptree pt;
	read_json(jsonFile, pt);
	vector<Person> people;

	for (auto & array_element : pt) {
		int id;
		std::string firstName, lastName, email, btcAddress, ipAddress;
		for (auto & property : array_element.second) {
			if (property.first == "id") { id = property.second.get_value<int>(); }
			else if (property.first == "first_name") { firstName = property.second.get_value<std::string>(); }
			else if (property.first == "last_name") { lastName = property.second.get_value<std::string>(); }
			else if (property.first == "email") { email = property.second.get_value<std::string>(); }
			else if (property.first == "btc_address") { btcAddress = property.second.get_value<std::string>(); }
			else if (property.first == "ip_address") { ipAddress = property.second.get_value<std::string>(); }
		}
		Person p;
		p.set_values(id, firstName, lastName, email, btcAddress, ipAddress);
		people.push_back(p);
	}

	ofstream out_data("log.txt");
	for (vector<int>::size_type i = 0; i != people.size(); i++) {
		out_data << "ID: " << people[i].ID << endl;
		out_data << "Full Name: " << people[i].full_name() << endl;
		out_data << "Email: " << people[i].Email << endl;
		out_data << "BTC Address: " << people[i].BTCAddress << endl;
		out_data << "IP Address: " << people[i].IPAddress << endl;
		out_data << endl;
	}
	return 0;
}

