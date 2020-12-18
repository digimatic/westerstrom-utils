//
// Created by Peter Westerstrom on 2020-12-18.
//

#include <westerstrom/tuple_math.h>

#include <catch2/catch.hpp>

TEST_CASE("tuple add", "[add]")
{
	using std::make_tuple;
	using namespace westerstrom;

	REQUIRE(add(make_tuple(1, 10), make_tuple(2, 20)) == make_tuple(3, 30));

	REQUIRE((make_tuple(1, 10) + make_tuple(2, 20)) == make_tuple(3, 30));

	std::tuple<int, int, float> v{10, -5, 3.14f};
	v += make_tuple(20, 1, 4.1f);
	REQUIRE(v == make_tuple(30, -4, 7.24f));
}
