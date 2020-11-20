#include "graph.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>


using namespace main_savitch_15;
using namespace std;

set<string>  friends(const graph<string>& network, const string& name)
{
	set<string> persons;
	size_t i;
	int source = 0;

	for (i = 0; i < network.size(); i++)
	{
		if (network.operator[](i) == name)
		{
			source = i;
			break;
		}

	}

	for (i = 0; i < network.size(); ++i)
	{
		if (i == source)
		{
			continue;
		}
		else
		{
			if (network.is_edge(source, i))
			{
				persons.insert(network.operator[](i));
			}
		}
	}
	return persons;
}

set<string>  common_friends(const graph<string>& network, const string& name1, const string& name2)
{
	set<string> common;
	set<string> friends1;
	set<string> friends2;


	friends1 = friends(network, name1);
	friends2 = friends(network, name2);

	for (set<string>::iterator iter = friends1.begin(); iter != friends1.end(); ++iter)
	{
		for (set<string>::iterator iter2 = friends2.begin(); iter2 != friends2.end(); ++iter2)
		{
			if (*iter == *iter2)
			{
				common.insert(*iter);
				break;
			}
		}
	}
	return common;

}

set<string>  friends_of_friends(const graph<string>& network, const string& my_name)
{
	set<string> friendlies;
	set<string> f_o_f;
	set<string> fluff;

	friendlies = friends(network, my_name);

	for (set<string>::iterator iter2 = friendlies.begin(); iter2 != friendlies.end(); ++iter2)
	{
		fluff = friends(network, *iter2);
		for (set<string>::iterator iter3 = fluff.begin(); iter3 != fluff.end(); ++iter3)
		{
			f_o_f.insert(*iter3);
		}
	}
	return f_o_f;

}

void add_friend(graph<string>& network, const string& my_name, const string& new_friend)
{
	int source = -1;
	int source2 = -1;
	for (int i = 0; i < network.size(); i++)
	{
		if (source >= 0 && source2 >= 0)
		{
			break;
		}
		if (network.operator[](i) == my_name)
		{
			source = i;

		}

		if (network.operator[](i) == new_friend)
		{
			source2 = i;
		}
	}

	network.add_edge(source, source2);
}

void remove_friend(graph<string>& network, const string& my_name, const string& ex_friend)
{
	int source = -1;
	int source2 = -1;
	for (int i = 0; i < network.size(); i++)
	{
		if (source >= 0 && source2 >= 0)
		{
			break;
		}
		if (network.operator[](i) == my_name)
		{
			source = i;

		}

		if (network.operator[](i) == ex_friend)
		{
			source2 = i;
		}
	}

	network.remove_edge(source, source2);
}

bool  is_friend(const graph<string>& network, const string& my_name, const string& maybe_friend)
{
	int source = -1;
	int source2 = -1;
	for (int i = 0; i < network.size(); i++)
	{
		if (source >= 0 && source2 >= 0)
		{
			break;
		}
		if (network.operator[](i) == my_name)
		{
			source = i;

		}

		if (network.operator[](i) == maybe_friend)
		{
			source2 = i;
		}
	}

	return network.is_edge(source, source2);
}


void tokenize(const string& s, string& first, string& second)
{
	stringstream ss(s);
	ss >> first;
	ss >> second;
}

size_t get_index(const graph<string>& g, const string& target)
{
	size_t i = 0;
	while (i < g.size() && g[i] != target)
		++i;
	assert(i < g.size());
	return i;
}


graph<string>* create_graph(const string& file_name)
{
	graph<string>* g = new graph<string>;
	ifstream input(file_name.c_str());
	size_t num;
	input >> num;
	string temp;
	getline(input, temp);
	assert(num <= g->MAXIMUM);
	string* names = new string[num];
	for (size_t i = 0; i < num; ++i)
	{
		string s;
		getline(input, s);
		names[i] = s;
		g->add_vertex(s);
	}
	string line;
	while (getline(input, line))
	{
		string first, second;
		tokenize(line, first, second);
		g->add_edge(get_index(*g, first), get_index(*g, second));
	}
	input.close();
	return g;
}


int main()
{
	graph<string> * world = create_graph("A7_test.txt");
	set<string> test;
	test = friends(*world, "Bob");
	cout << "Bob's Friends:" << endl;
	for (set<string>::iterator iter2 = test.begin(); iter2 != test.end(); ++iter2)
	{
		cout << *iter2 << " ";
	}
	cout << endl;

	test = friends_of_friends(*world, "Barbara");
	cout << "Friends of Barbara's Friends:" << endl;
	for (set<string>::iterator iter2 = test.begin(); iter2 != test.end(); ++iter2)
	{
		cout << *iter2 << " ";
	}
	cout << endl;

	test = common_friends(*world, "Barbara", "Bob");
	cout << "Common Friends of Barbara and Bob:" << endl;
	for (set<string>::iterator iter2 = test.begin(); iter2 != test.end(); ++iter2)
	{
		cout << *iter2 << " ";
	}
	cout << endl;
	add_friend(*world, "Barbara", "Bob");
	add_friend(*world, "Bob", "Barbara");
	cout << "There seems to be a new relationship between Bob and Barbara. Are they friends?:" << endl;
	if (is_friend(*world, "Bob", "Barbara") == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	remove_friend(*world, "Steve", "Bob");
	add_friend(*world, "Steve", "Sally");
	test = friends(*world, "Steve");

	cout << "Steve doesn't seem to like how Bob is now friends with his ex, but he has found a new friend. Who may the be?:" << endl;
	for (set<string>::iterator iter2 = test.begin(); iter2 != test.end(); ++iter2)
	{
		cout << *iter2 << " ";
	}
	cout << endl;
	system("PAUSE");


	return 0;
}