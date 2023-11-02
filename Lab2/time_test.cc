#include "../catch.hpp"
#include "time.hpp"
#include <sstream>

TEST_CASE("double_plus")
{
	Time a{11, 59, 59};
	Time b{12, 0, 0};
	CHECK_FALSE(b == a++);
	CHECK(++b == ++a);
}

TEST_CASE("is_valid")
{
	Time a{11, 11, 11};
	Time b{11, 66, 1};
	CHECK(a.is_valid());
	CHECK_FALSE(b.is_valid());
}

TEST_CASE("to_string")
{
	Time a{13, 11, 11};
	CHECK(a.to_string() == "13:11:11");
	CHECK(a.to_string(false) == "1:11:11[pm]");
}
TEST_CASE("io")
{
	std::istringstream iss{"random- dsadas dsa"};
	std::istringstream isss{"12:12:12"};
	std::ostringstream oss{};
	Time a{};
	iss >> a;
	CHECK(iss.fail());
	CHECK(a.to_string() == "0:0:0");
	isss >> a;
	CHECK(a.to_string() == "12:12:12");
	oss << a << endl;
	CHECK(oss.str() == "12:12:12\n");
}

TEST_CASE("addition")
{
	Time a{12, 58, 59};
	Time b{a + 1};
	CHECK(b.to_string() == "12:59:0");
}
