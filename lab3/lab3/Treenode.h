#pragma once
#include <string>
#include <iostream>

using namespace std;

typedef unsigned int idint;

class CTreeNode {
public:
	CTreeNode();
	~CTreeNode() {};

	CTreeNode & operator=(const CTreeNode &);
	void SetData(idint BookNumber, string Author, string Title, int Year, int Quantity);

	CTreeNode *left;
	CTreeNode *right;

	idint m_BookNumber;
	string m_Author;
	string m_Title;
	int m_Year;
	int m_Quantity;
};

