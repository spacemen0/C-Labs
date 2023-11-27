#ifndef List_H
#define List_H
#include <iostream>
#include <string>

/// <summary>
/// The head pointer is only symbolic and not part of the actual value of the list,
/// thus the length of the list is equal to "number of Nodes it contains" - 1
/// </summary>

// From assignment:
// “The link class and any functions pertaining to it should thus be stashed
// away and be inaccessible to the programmer.”

// TODO: Complementary work needed: Use reference to constant for input parameters of
// class type.

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

public:
	List();						 // default constructor
	List(const List &other);	 // copy constructor
	List(List &&other) noexcept; // move constructor
	List(std::initializer_list<int> list);
	~List();								// destructor
	List &operator=(const List &other);		// copy assignment operator
	List &operator=(List &&other) noexcept; // move assignment operator
	void remove(int value);
	void remove_at(int index);
	void insert(int value);
	int at(int index) const;					   // declare as const
	std::string to_string() const;				   // declare as const
	std::string to_string(const Node *temp) const; // declare as const
	void clear();
};
#endif // !List_H