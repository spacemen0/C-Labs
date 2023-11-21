#ifndef List_H
#define List_H
#include <iostream>
#include <string>

/// <summary>
/// The head pointer is only symbolic and not part of the actual value of the list,
/// thus the length of the list is equal to "number of Nodes it contains" - 1
/// </summary>

// TODO: Complementary work needed: include header guards, all includes should be
// inside the guards.

// TODO: Complementary work needed: The Node type should be invisible and
// inaccessible to programmers that use the list.
// From assignment:
// “The link class and any functions pertaining to it should thus be stashed
// away and be inaccessible to the programmer.”

// TODO: Complementary work needed: Member functions that don't modify the
// list should be declared const.

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
	List(List const &other);	 // copy constructor
	List(List &&other) noexcept; // move constructor
	List(std::initializer_list<int> list);
	~List();								// destructor
	List &operator=(List const &other);		// copy assignment operator
	List &operator=(List &&other) noexcept; // move assignment operator
	void remove(int value);
	void remove_at(int index);
	void insert(int value);
	int at(int index);
	std::string to_string();
	std::string to_string(Node *temp);
	// void print();
	//     void print(Node* temp);// recursive print
	// Node* getHead();
	void clear();
};
#endif // !List_H