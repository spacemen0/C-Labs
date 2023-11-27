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
	CHECK(is_valid(a));
	CHECK_FALSE(is_valid(b));
}

TEST_CASE("to_string")
{
	Time a{13, 11, 11};
	CHECK(to_string(a) == "13:11:11");
	CHECK(to_string(a, false) == "01:11:11[pm]");
}
TEST_CASE("io")
{
	std::istringstream invalid{"random- dsadas dsa"};
	std::istringstream valid{"12:12:12"};
	std::ostringstream oss{};
	Time a{};
	invalid >> a;
	CHECK(invalid.fail());
	CHECK(to_string(a) == "00:00:00");
	valid >> a;
	CHECK(to_string(a) == "12:12:12");
	oss << a << std::endl;
	CHECK(oss.str() == "12:12:12\n");
}

TEST_CASE("addition")
{
	Time a{12, 58, 59};
	Time b{a + 1};
	Time c{a - (86400 * 3)};
	CHECK(to_string(b) == "12:59:00");
	CHECK(to_string(c) == "12:58:59");
}
