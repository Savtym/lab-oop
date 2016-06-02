#include "TreeNode.h"

CTreeNode::CTreeNode() {
	left = nullptr;
	right = nullptr;
}

CTreeNode & CTreeNode::operator=(const CTreeNode &ct) {
	if (this != &ct) {
		m_BookNumber = ct.m_BookNumber;
		m_Author = ct.m_Author;
		m_Title = ct.m_Title;
		m_Year = ct.m_Year;
		m_Quantity = m_Quantity;
	}
	return *this;
}

void CTreeNode::SetData(idint BookNumber, string Author, string Title, int Year, int Quantity) {
	m_BookNumber = BookNumber;
	m_Author = Author;
	m_Title = Title;
	m_Year = Year;
	m_Quantity = Quantity;
}