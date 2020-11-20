#include "expression_tree.h"
#include <cassert>
#include <sstream>
#include <cctype>

using namespace std;


expression_tree::expression_tree(const std::string& op,
	const expression_tree& left,
	const expression_tree& right)
{
	assert((op == "+") || (op == "*"));
	node = new binary_tree_node<std::string>(op, left.node,
		right.node);
}

bool all_digits(const string& s)
// return whether all characters is s are digits
{
	size_t i = 0;
	while (i < s.length() && isdigit(s[i]))
		i++;
	return i == s.length();
}

expression_tree::expression_tree(const std::string& value)
{

	node = new binary_tree_node<std::string>(value);
}


int recursive(binary_tree_node<std::string>* node)
{
	//If we have reached the bottom, then return data
	if (node->is_leaf()) return stoi(node->data());
	//If the node's data is a *, multiply the left node by the right node
	if (node->data() == "*") return recursive(node->left()) * recursive(node->right());
	//If the node's data is a +, add the left node and the right node
	if (node->data() == "+") return recursive(node->left()) + recursive(node->right());
}

int expression_tree::evaluate() const
{
	return recursive(node);
}


