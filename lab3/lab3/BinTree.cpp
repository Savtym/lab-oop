#include "BinTree.h"

void CBinaryTree::ShowTree(CTreeNode* curNode) {
	if (curNode != nullptr)	{
		cout << setw(5) << curNode->m_BookNumber << setw(16) << right << curNode->m_Author << setw(32) << curNode->m_Title << setw(6) << curNode->m_Year << "  " << curNode->m_Quantity << endl;
		ShowTree(curNode->left);
		ShowTree(curNode->right);
	}
}

void CBinaryTree::ShowBookAuthor(CTreeNode * curNode, string author) {
	if (curNode != nullptr)	{
		if (curNode->m_Author == author)
			cout << setw(5) << curNode->m_BookNumber << setw(16) << right << curNode->m_Author << setw(32) << curNode->m_Title << setw(6) << curNode->m_Year << "  " << curNode->m_Quantity << endl;
		ShowBookAuthor(curNode->left, author);
		ShowBookAuthor(curNode->right, author);
	}
}

void CBinaryTree::ShowBookTitle(CTreeNode * curNode, string title) {
	if (curNode != nullptr)	{
		if (curNode->m_Title == title)
			cout << setw(5) << curNode->m_BookNumber << setw(16) << right << curNode->m_Author << setw(32) << curNode->m_Title << setw(6) << curNode->m_Year << "  " << curNode->m_Quantity << endl;
		ShowBookTitle(curNode->left, title);
		ShowBookTitle(curNode->right, title);
	}
}

void CBinaryTree::ShowTree() {
	ShowTree(root);
	cout << endl;
}

void CBinaryTree::AddElement(idint BookNumber, string Author, string Title, int Year, int Quantity) {
	CTreeNode temp;
	temp.m_BookNumber = BookNumber;
	temp.m_Author = Author;
	temp.m_Title = Title;
	temp.m_Year = Year;
	temp.m_Quantity = Quantity;

	temp.left = nullptr;
	temp.right = nullptr;

	if (root == nullptr) {
		root = new CTreeNode;
		root->m_Quantity = Quantity;
		*root = temp;
	}
	else
		Insert(root, temp);
}



void CBinaryTree::ShowBookAuthor(string Author) {
	ShowBookAuthor(root, Author);
	cout << endl;
}

void CBinaryTree::ShowBookTitle(string title) {
	ShowBookTitle(root, title);
	cout << endl;
}

void CBinaryTree::DeleteNode(idint bookNumber) {
	if (root->m_BookNumber == bookNumber) {
		CTreeNode *tempParrent = new CTreeNode;
		tempParrent->left = root;
		DeleteNode(tempParrent, true);
	}
	else
		DeleteNode(root, bookNumber);
}

void CBinaryTree::DeleteNode(CTreeNode *&parentNode, bool left) {
	CTreeNode *nodeToDelete;
	CTreeNode *currentNode;

	if (left) 
		nodeToDelete = parentNode->left;
	else	  
		nodeToDelete = parentNode->right;

	if (nodeToDelete->left == nullptr) {
		currentNode = nodeToDelete;
		if (left) 
			parentNode->left = nodeToDelete->right;
		else      
			parentNode->right = nodeToDelete->right;
		delete nodeToDelete;
	}
	else {
		CTreeNode* greatestNode = nodeToDelete->left;
		if (greatestNode->right == nullptr)	{
			nodeToDelete->left->right = nodeToDelete->right;
			if (left) 
				parentNode->left = nodeToDelete->left;
			else      
				parentNode->right = nodeToDelete->left;
		}
		else {
			while (greatestNode->right->right)
				greatestNode = greatestNode->right;
			*nodeToDelete = *greatestNode->right;
			CTreeNode *nodeToDelete2 = greatestNode->right;
			greatestNode->right = greatestNode->right->left;
			delete nodeToDelete2;
		}
	}
}

void CBinaryTree::DeleteNode(CTreeNode * curNode, idint bookNumber) {
	if (curNode != nullptr)	{
		if (curNode->left != nullptr && curNode->left->m_BookNumber == bookNumber)
			DeleteNode(curNode, true);
		else if (curNode->right != nullptr && curNode->right->m_BookNumber == bookNumber)
			DeleteNode(curNode, false);
		DeleteNode(curNode->left, bookNumber);
		DeleteNode(curNode->right, bookNumber);
	}
}

void CBinaryTree::Insert(CTreeNode *& curNode, CTreeNode temp) {
	if (curNode == nullptr) {
		curNode = new CTreeNode;
		*curNode = temp;
		curNode->m_Quantity = temp.m_Quantity;
	}
	else {
		if (curNode->m_BookNumber < temp.m_BookNumber)
			Insert(curNode->left, temp);
		else if (curNode->m_BookNumber > temp.m_BookNumber)
			Insert(curNode->right, temp);
		else
			cout << "ERROR: this key already existing\n";
	}
}