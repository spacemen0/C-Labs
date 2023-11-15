#include<iostream>
#include <string>

/// <summary>
/// The head pointer is only symbolic and not part of the actual value of the list, and is never a nullptr,
/// thus the length of the list is equal to "number of Nodes it contains" - 1
/// </summary>
class List
{
public:
	class Node
	{
	public:
		int value;
		Node* next;
		Node(int value);
	};
	List(); // default constructor
	List(List const& other); // copy constructor
	List(List&& other)noexcept; // move constructor
	List(std::initializer_list<int> list);
	~List(); // destructor
	List& operator=(List const& other); // copy assignment operator
	List& operator=(List&& other) noexcept; // move assignment operator
	void remove(int value);
	void remove_at(int index);
	void insert(int value);
	int at(int index);
	std::string to_string();
	void print();
        void print(Node* temp);// recursive print
        Node* getHead();
	void clear();
private:
	Node* head{};
};
