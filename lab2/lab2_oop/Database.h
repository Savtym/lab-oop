/*!
* file: Database.h
* written: 05/03/2015
* synopsis: Database class definition
* Copyright (c) 2015 by Yu.Zorin
*/

#pragma once
#include "Manager.h"
#include <iostream>
#include <fstream>
#include <vector>

class Database {
public:
	Database() {};
	~Database() {};//no need in destructor
				   //creates �flat� database
	bool LoadFromFile(const char *file);
	//arranges "flat" database after loading from the file
	void ArrangeSubordinates();
	//hire a new employee
	Person* HireEmployee(Person *p);
	void DisplayDepartmentEmployees(string _department);
	//fire the employee
	bool FireEmployee(int id);
	void DisplayAll();
	//Add here whatever you need

private:
	vector<Person*> employees;
};
