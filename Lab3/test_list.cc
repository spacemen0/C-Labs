#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "List.h"

//=======================================================================
// Test cases
//=======================================================================

// TODO: Complementary work needed: Test cases insufficient, what if a list is
// empty for all functions?

// TODO: Complementary work needed: Test cases insufficient, you should test
// all functionality for copy, such as remove values in the copied list and if this
// affects the original.

// TODO: Complementary work needed: Test cases insufficient, test
// all functionality for insert/remove such as inserting to an empt list and so on

// TODO: Complementary work needed: Test cases insufficient, you should test
// all functions that you have implemented.

TEST_CASE("Create list")
{
	List l{1, 11, 3, 2, 6, 9, 8, 7};

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
	l.remove(7);
	CHECK(l.at(5) == 9);
	l.remove_at(1);
	CHECK(l.at(1) == 3);
}

TEST_CASE("COPY AND TO_STRING")
{
	List l{2, 5, 1, 3, 8, 4};
	List a{l};
	List b = std::move(a);
	CHECK(l.to_string() == "1 2 3 4 5 8");
	CHECK(b.to_string() == "1 2 3 4 5 8");
	List c{};
	c = std::move(b);
	CHECK(c.to_string() == "1 2 3 4 5 8");
	List d = c;
	CHECK(d.to_string() == "1 2 3 4 5 8");
	List e{};
	e = c;
	CHECK(e.to_string() == "1 2 3 4 5 8");
}
