#pragma once
#include "TreeNode.h"
#include <iomanip>

class CBinaryTree {
public:
	CBinaryTree() {};
	~CBinaryTree() {};

	void ShowTree();
	void AddElement(idint BookNumber, string Author, string Title, int Year, int Quantity);
	void ShowBookAuthor(string Author);
	void ShowBookTitle(string title);
	void DeleteNode(idint bookNumber);

private:
	CTreeNode *root;
	void ShowTree(CTreeNode* curNode);
	void DeleteNode(CTreeNode *&parentNode, bool left);
	void DeleteNode(CTreeNode *curNode, idint bookNumber);
	void ShowBookAuthor(CTreeNode *curNode, string author);
	void ShowBookTitle(CTreeNode *curNode, string title);
	void Insert(CTreeNode *&curNode, CTreeNode temp);
};

