#ifndef List_H
#define List_H
#include <iostream>
#include <string>

/// <summary>
/// The head pointer is only symbolic and not part of the actual value of the list,
/// thus the length of the list is equal to "number of Nodes it contains" - 1
/// </summary>

// TODO: Complementary work needed: The public part should be first, and the
// private part should be below. There should only be one private part.

class List
{
private:
	class Node
	{
	public:
		int value;
		Node *next;
		Node(int value);
	};
	Node *head{};

	std::string to_string(const Node *temp) const; // declare as const
public:
	List();									// default constructor
	List(const List &other);				// copy constructor
	List &operator=(const List &other);		// copy assignment operator
	List(List &&other) noexcept;			// move constructor
	List &operator=(List &&other) noexcept; // move assignment operator
	List(std::initializer_list<int> list);
	~List(); // destructor
	void remove(int value);
	void remove_at(int index);
	void insert(int value);
	int at(int index) const;	   // declare as const
	std::string to_string() const; // declare as const

	void clear();
};
#endif // !List_H