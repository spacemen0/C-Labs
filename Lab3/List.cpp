#include "List.h"
using namespace std;

const int List::ERROR_OUT_OF_LENGTH = -1;
const int List::ERROR_NEGATIVE_INDEX = -2;
const int List::ERROR_EMPTY_LIST = -3;
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
        cerr << "Index can not be negative" << endl;
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
            cerr << "Index out of length" << endl;
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
/// index should be [0, length)
/// </summary>
/// <param name="index"></param>
/// <returns></returns>
int List::at(int index) const
{
    if (head == nullptr)
    {
        cerr << "List is destroyed" << endl;
        return ERROR_EMPTY_LIST;
    }
    Node *temp = head->next;
    if (index < 0)
    {
        cerr << "Index can not be negative" << endl;
        return ERROR_NEGATIVE_INDEX;
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
            cerr << "Index out of length" << endl;
            return ERROR_OUT_OF_LENGTH;
        }
    }
    if (temp != nullptr)
        return temp->value;
    cerr << "Index out of length" << endl;
    return ERROR_OUT_OF_LENGTH;
}

std::string List::to_string() const
{
    string str;
    if (head == nullptr)
    {
        return "";
    }
    Node *temp = head->next;
    return to_string(temp);
}

void List::print() const
{
    cout << to_string() << endl;
}

std::string List::to_string(const Node *temp) const
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

void List::clear()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
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

List &List::operator=(const List &other)
{
    if (this != &other)
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
