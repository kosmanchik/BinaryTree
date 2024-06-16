#include <iostream>
#include "BTree.h"

int main()
{

	BinaryTree<char, int> mytree;
	mytree.push_in_tree('3', 20);
	mytree.push_in_tree('1', 40);
	mytree.push_in_tree('5', 59);
	mytree.push_in_tree('6', 32);
	mytree.push_in_tree('2', 77);
	mytree.push_in_tree('4', 88);

	
	std::cout << "TEST OF INPUT AND SEARCH: " << std::endl;
	for (auto el : "123456")
	{
		if (el != char())
			std::cout << "key: " << el << " element: " << mytree[el] << std::endl;
	}

	std::cout << '\n' << "TEST OF DELETE" << std::endl;
	mytree.delete_node('2');
	mytree.delete_node('4');
	for (auto el : "123456")
	{
		if (el != char())
			std::cout << "key: " << el << " element: " << mytree[el] << std::endl;
	}

	return 0;
}