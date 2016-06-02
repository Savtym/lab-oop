#include <fstream>
#include "BinTree.h"
#include "TreeNode.h"

int main() {
	idint bookNumber;
	char author[256];
	char title[256];
	int year;
	int quantity;
	CBinaryTree tree;
	string file = "input.csv";
	ifstream f(file);
	if (f.is_open()) {
		while (!f.eof()) {
			f >> bookNumber;
			f.get();
			f.getline(author, 256, ';');
			f.getline(title, 256, ';');
			f >> year;
			f.get();
			f >> quantity;
			tree.AddElement(bookNumber, author, title, year, quantity);
		}
		f.close();
		tree.ShowTree();
		tree.AddElement(5, "Rey Bredbery", "451 F",2002, 9);
		tree.ShowTree();
		tree.DeleteNode(2);
		tree.ShowTree();
		tree.ShowBookAuthor("Yesenin");
		tree.ShowBookTitle("451 F");
	}
	else
		cout << "ERROR: don`t can open the file";
	return 0;
}