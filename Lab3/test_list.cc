#include "../catch.hpp"
#include "List.h"

//=======================================================================
// Test cases
//=======================================================================

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
	CHECK(l.to_string() == "1 2 3 4 5 8");
}