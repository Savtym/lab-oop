/*!
* file: Database.cpp
* written: 05/03/2015
* synopsis: Database class implementation
* Copyright (c) 2015 by Yu.Zorin
*/
#include "Database.h"
// Database Class Implemantation

bool Database::LoadFromFile(const char *file) {
	int poz;
	int age;
	int id;
	int salary;
	char f_Name[256];
	char l_Name[256];
	char depart[256];
	ifstream f(file);
	if (f.is_open()) {
		while (!f.eof()) {
			f >> poz;
			f.get();
			f >> id;
			f.get();
			f.getline(f_Name, 256, ';');
			f.getline(l_Name, 256, ';');
			f >> age;
			f.get();
			f.getline(depart, 256, ';');
			f >> salary;
			if (poz == 0) {
				Employee* e = new Employee(f_Name, l_Name, age, id);
				e->SetDepartment(depart);
				e->SetSalary(salary);
				employees.push_back(e);
			}
			else if (poz == 1) {
				Manager* m = new Manager(f_Name, l_Name, age, id);
				m->SetDepartment(depart);
				m->SetSalary(salary);
				employees.push_back(m);
			}
		}
		return true;
	}
	else
		return false;
}

void Database::ArrangeSubordinates() {
	vector<Person*>::iterator it = employees.begin();
	vector<Person*>::iterator itEml;
	while (it != employees.end()) {
		if (typeid(**it) == typeid(Manager)) {  //manager 
			string dept = dynamic_cast<Manager*>(*it)->GetDepartment();
			itEml = employees.begin();
			while (itEml != employees.end()) {
				if ((dept == dynamic_cast<Employee*>(*itEml)->GetDepartment()) && (typeid(**itEml) != typeid(Manager)))
					dynamic_cast<Manager*>(*it)->AddSubordinate(*itEml);
				++itEml;
			}
		}
		++it;
	}
}

Person* Database::HireEmployee(Person *p) {
	int poz;
	int age;
	int id;
	int salary;
	char f_Name[256];
	char l_Name[256];
	char depart[256];
	cout << "Employee type: ";
	cin >> poz;
	cout << "\nage: ";
	cin >> age;
	cout << "\nid: ";
	cin >> id;
	cout << "\nsalary: ";
	cin >> salary;
	cout << "\nFirst name: ";
	cin >> f_Name;
	cout << "\nLast name: ";
	cin >> l_Name;
	cout << "\nDepartment: ";
	cin >> depart;
	cout << endl;
	if (poz == 0) {
		Employee* e = new Employee(f_Name, l_Name, age, id);
		e->SetDepartment(depart);
		e->SetSalary(salary);
		employees.push_back(e);
	}
	else if (poz == 1) {
		Manager* m = new Manager(f_Name, l_Name, age, id);
		m->SetDepartment(depart);
		m->SetSalary(salary);
		employees.push_back(m);
	}
	return p;
}

void Database::DisplayDepartmentEmployees(string _department) {
	vector<Person*>::iterator it = employees.begin();
	while (it != employees.end()) {
		if (_department == dynamic_cast<Employee*>(*it)->GetDepartment()) {
			dynamic_cast<Employee*>(*it)->Display(true);
			cout << endl;
		}
		++it;
	}
}

bool Database::FireEmployee(int id) {
	vector<Person*>::iterator it = employees.begin();
	while (it != employees.end()) {
		if (typeid(**it) == typeid(Manager))
			dynamic_cast<Manager*>(*it)->DeleteSub(id);
		++it;
	}
	it = employees.begin();
	while (it != employees.end()) {
		if (id == dynamic_cast<Employee*>(*it)->GetId()) {
			employees.erase(it);
			return true;
		}
		++it;
	}
	return false;
}

void Database::DisplayAll() {
	vector<Person*>::iterator it = employees.begin(); 
	while (it != employees.end()) {
		if (typeid(**it) == typeid(Manager)) {  //manager
			dynamic_cast<Manager*>(*it)->Display(true);
			dynamic_cast<Manager*>(*it)->DisplaySubordinates();
		}
		if (typeid(**it) == typeid(Employee)) {  //employee
			dynamic_cast<Employee*>(*it)->Display(true);
		}
		cout << "\n\n";
		++it;
	}
}








