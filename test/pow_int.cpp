//
// Created by Peter Westerstrom on 2020-12-18.
//

#include <westerstrom/pow_int.h>

#include <catch2/catch.hpp>

TEST_CASE("pow_int, normal positive cases", "[pow_int]")
{
	REQUIRE(pow(3, 3) == 27);
	REQUIRE(pow(3, 4) == 81);
}

TEST_CASE("Anything with power 0 is 1", "[pow_int]")
{
	REQUIRE(pow(1, 0) == 1);
	REQUIRE(pow(2, 0) == 1);
	REQUIRE(pow(3, 0) == 1);

	REQUIRE(pow(-1, 0) == 1);
	REQUIRE(pow(-2, 0) == 1);
	REQUIRE(pow(-3, 0) == 1);
}

TEST_CASE("Negative with odd power is negative", "[pow_int]")
{
	REQUIRE(pow(-2, 1) == -2);
	REQUIRE(pow(-2, 3) == -8);
}

TEST_CASE("Negative with even power is positive", "[pow_int]")
{
	REQUIRE(pow(-2, 2) == 4);
	REQUIRE(pow(-2, 4) == 16);
}

TEST_CASE("Medium large power shall be ok", "[pow_int]")
{
	REQUIRE(pow(2, 10) == 1024);
	REQUIRE(pow(3, 12) == 531441);
}
