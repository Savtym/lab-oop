#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "MultiString.h"


void main() {
	MultiString st1(2);
	MultiString st2(3);
	MultiString st3(1);
	MultiString st4;
	st1.Setat(0, "0");
	st1.Setat(1, "4");
	st2.Setat(0, "1");
	st2.Setat(1, "2");
	st2.Setat(2, "3");
	cout << "st3 is " << st3.Isempty() << " empty \n";
	st3.Setat(0, "5");
	st3.Printstr(0);
	st3.Empty();
	st3.Printstr(0);
	cout << "st3 is " << st3.Isempty() << " empty \n";
	st1.Printstr(0);
	st1 += st2;
	st1.Setat(0, "9");
	cout << st1.Find("7") << " number \n";
	st1.Printstr(0);
	st1.MergeMultiStringexcl(st4);
	st1.Printstr(2);
	st1.Printstr(5);
};