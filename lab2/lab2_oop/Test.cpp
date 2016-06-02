/*!
* file: Test.cpp
* written: 05/03/2015
* synopsis: Database class test
* Copyright (c) 2015 by Yu.Zorin
*/
#include "Database.h"

int main() {
	Database db;
	if (!db.LoadFromFile("input.csv"))
		cout << "Error input file";
	else {
		db.DisplayAll();
		db.ArrangeSubordinates();
		db.DisplayAll();
	}
}
