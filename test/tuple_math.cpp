//
// Created by Peter Westerstrom on 2020-12-18.
//

#include <catch2/catch.hpp>
#include <westerstrom/tuple_math.h>

using std::make_tuple;
using namespace westerstrom;

TEST_CASE("tuple add", "[add]")
{
	REQUIRE(add(make_tuple(1, 10), make_tuple(2, 20)) == make_tuple(3, 30));

	REQUIRE((make_tuple(1, 10) + make_tuple(2, 20)) == make_tuple(3, 30));

	std::tuple<int, int, float> v{10, -5, 3.14f};
	v += make_tuple(20, 1, 4.1f);
	REQUIRE(v == make_tuple(30, -4, 7.24f));
}

TEST_CASE("tuple minus", "[minus]")
{
	REQUIRE((make_tuple(1, 10) - make_tuple(2, 20)) == make_tuple(-1, -10));
}

TEST_CASE("tuple scalar mul", "[tuple_math]")
{
	auto a = make_tuple(2, 3);
	a *= 3;
	REQUIRE(a == make_tuple(6, 9));
}

TEST_CASE("tuple tuple mul assignment", "[tuple_math]")
{
	auto a = make_tuple(2, 3);
	auto b = make_tuple(11, 13);
	a += b;
	REQUIRE(a == make_tuple(13, 16));
}

TEST_CASE("tuple scalar tuple mul", "[tuple_math]")
{
	auto a = make_tuple(2, 3);
	auto c = 5 * a;
	REQUIRE(c == make_tuple(10, 15));
}

TEST_CASE("tuple tuple add", "[tuple_math]")
{
	auto a = make_tuple(2, 3);
	auto b = make_tuple(11, 13);
	auto c = a + b;
	REQUIRE(c == make_tuple(13, 16));
}

TEST_CASE("tuple manhattan distance")
{
	auto a = make_tuple(2, 3);
	auto b = make_tuple(11, 13);
	REQUIRE(tuple_manhattan(a, b) == 19);
}