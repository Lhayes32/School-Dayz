#include <cstdlib>
#include <iostream>
#include <string>
#include "bintree.h"

using namespace std;
using namespace main_savitch_10;

binary_tree_node<std::string>* create_tree();

int main() {
	binary_tree_node<std::string>* bin_tree = create_tree();
	display_complete_tree(bin_tree);
	tree_clear(bin_tree);
	system("PAUSE");
	return EXIT_SUCCESS;
}


binary_tree_node<std::string>* create_tree() {

	//leaves
	binary_tree_node<std::string>* t1 = new binary_tree_node<std::string>("W");
	binary_tree_node<std::string>* t2 = new binary_tree_node<std::string>("A");
	binary_tree_node<std::string>* t3 = new binary_tree_node<std::string>("Q");


	binary_tree_node<std::string>* t9 = new binary_tree_node<std::string>("E", t2, NULL);
	binary_tree_node<std::string>* t10 = new binary_tree_node<std::string>("P", NULL, t3);
	binary_tree_node<std::string>* t11 = new binary_tree_node<std::string>("T", t10, t1);
	binary_tree_node<std::string>* t12 = new binary_tree_node<std::string>("H", t9, NULL);

	//Root
	binary_tree_node<std::string>* t13 = new binary_tree_node<std::string>("M", t12, t11);
	return t13;
}
