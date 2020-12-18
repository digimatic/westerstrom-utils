//
// Created by Peter Westerstrom on 2020-12-18.
//

#include <algorithm>
#include <catch2/catch.hpp>
#include <tuple>
#include <westerstrom/grid.h>

TEST_CASE("neighbors", "[neighbors]")
{
	using namespace westerstrom;
	using namespace std;

	auto v = neighbors(make_tuple(100, 200));
	sort(begin(v), end(v));

	vector<tuple<int, int>> v2 = {{99, 199},  {100, 199}, {101, 199}, {99, 200},
	                              {101, 200}, {99, 201},  {100, 201}, {101, 201}};
	sort(begin(v2), end(v2));
	REQUIRE(v == v2);
}
