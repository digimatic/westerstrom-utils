//
// Created by Peter Westerstrom on 2020-12-18.
//

#include <westerstrom/set_cross.h>

#include <catch2/catch.hpp>

TEST_CASE("cross of three sets", "[set_cross]")
{

	std::vector<int> is = {2, 5, 9};
	std::vector<char const*> cps = {"foo", "bar"};
	std::vector<double> ds = {1.5, 3.14, 2.71};
	auto res = westerstrom::set_cross(is, cps, ds);

	REQUIRE(res.size() == 18);

	REQUIRE(find(std::begin(res), std::end(res), std::make_tuple(9, "foo", 3.14)) != std::end(res));
}
