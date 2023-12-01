#include "../catch.hpp"
#include "List.h"

//=======================================================================
// Test cases
//=======================================================================

// TODO: Complementary work needed: You need to test all your functions that you have
// created before you can use them to prove that other lists work.

TEST_CASE("Create list")
{
	List l{1, 11, 3, 2, 6, 9, 8, 7};
	List empty;
	CHECK(empty.at(0) == List::ERROR_OUT_OF_LENGTH);
	empty.insert(1);
	CHECK(empty.at(0) == 1);
	CHECK(l.at(3) == 6);
	CHECK(l.at(5) == 8);
	CHECK(l.at(7) == 11);
	l.insert(5);
	CHECK(l.at(3) == 5);
	CHECK(l.at(5) == 7);
}

TEST_CASE("REMOVE ELEMENTS")
{
	List l{1, 11, 3, 2, 6, 9, 8, 7};
	List empty;
	empty.remove(1);
	CHECK(empty.at(0) == List::ERROR_OUT_OF_LENGTH);
	l.remove(7);
	CHECK(l.at(5) == 9);
	l.remove_at(1);
	CHECK(l.at(1) == 3);
	l.clear();
	CHECK(l.at(0) == List::ERROR_EMPTY_LIST);
}

TEST_CASE("COPY AND TO_STRING")
{
	List moveAssignment;
	moveAssignment = std::move(List{10, 20, 30});
	List moveConstructor = std::move(List{10, 20, 30});
	List copyConstructor{std::move(moveConstructor)};
	List copyAssignment;
	copyAssignment = std::move(copyConstructor);
	CHECK(copyAssignment.to_string() == "10 20 30");
	CHECK(copyConstructor.to_string() == "");
	CHECK(moveAssignment.to_string() == "10 20 30");
	CHECK(moveConstructor.to_string() == "");
	copyAssignment.remove(10);
	copyAssignment.insert(40);
	CHECK(copyConstructor.to_string() == "");
}
