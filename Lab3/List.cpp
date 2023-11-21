#include "List.h"
using namespace std;

// TODO: Complementary work needed: Your assignment operator(s) don’t
// handle self-assignment, as in a_list = a_list.

// TODO: Complementary work needed: Code duplication. Can you perhaps
// reuse the code from clear() for destructor?

void List::remove(int value)
{
    Node *beforeTemp = head;
    Node *temp = head->next;
    while (temp != nullptr)
    {
        if (temp->value == value)
        {
            beforeTemp->next = temp->next;
            delete temp;
            return;
        }
        beforeTemp = temp;
        temp = temp->next;
    }
}

void List::remove_at(int index)
{
    Node *beforeTemp = head;
    Node *temp = head->next;
    if (index < 0)
    {
        throw invalid_argument("Index can not be negative");
    }
    while (index > 0)
    {
        index--;
        if (temp != nullptr)
        {
            beforeTemp = temp;
            temp = temp->next;
        }
        else
        {
            throw invalid_argument("Index out of length");
        }
    }
    beforeTemp->next = temp->next;
    delete temp;
}

/// <summary>
/// Inserts values into the list in ascending order
/// </summary>
/// <param name="value"></param>
void List::insert(int value)
{
    Node *newNode = new Node(value);
    Node *current = head;
    while (current->next != nullptr && current->next->value <= value)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

/// <summary>
/// Get the value of the list at the given index;
/// index shoud be [0, length)
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
int List::at(int index)
{
    Node *temp = head->next;
    if (index < 0)
    {
        throw invalid_argument("Index can not be negative");
    }
    while (index > 0)
    {
        index--;
        if (temp != nullptr)
        {
            temp = temp->next;
        }
        else
        {
            throw invalid_argument("Index out of length");
        }
    }
    return temp->value;
}

std::string List::to_string()
{
    string str;
    Node *temp = head->next;
    return to_string(temp);
}

std::string List::to_string(Node *temp)
{
    string str;
    if (temp->next != nullptr)
    {
        return std::to_string(temp->value) + " " + to_string(temp->next);
    }
    if (temp != nullptr)
    {
        return std::to_string(temp->value);
    }
    return "";
}

// List::Node* List::getHead()
// {
//     Node* temp = head->next;
//     return temp;
// }

void List::clear()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

List::List()
{
    head = new Node(0);
}
List::List(List const &other)
{
    clear();
    head = new Node(0);
    Node *otherCurrent = other.head->next;
    Node *current = head;

    while (otherCurrent != nullptr)
    {
        Node *newNode = new Node(otherCurrent->value);
        current->next = newNode;
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}

List::List(List &&other) noexcept
{
    this->head = other.head;
    other.head = nullptr;
}

List::List(std::initializer_list<int> list)
{
    head = new Node(0);
    for (int i : list)
    {
        insert(i);
    }
}

List::~List()
{
    clear();
}

List::Node::Node(int value)
{
    this->value = value;
    next = nullptr;
}

List &List::operator=(List const &other)
{
    clear();
    head = new Node(0);
    Node *otherCurrent = other.head->next;
    Node *current = head;

    while (otherCurrent != nullptr)
    {
        Node *newNode = new Node(otherCurrent->value);
        current->next = newNode;
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    return *this;
}

List &List::operator=(List &&other) noexcept
{
    if (this != &other)
    {
        clear();
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}
