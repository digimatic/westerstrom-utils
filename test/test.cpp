#define CATCH_CONFIG_RUNNER
#include <catch2/catch.hpp>

//
// Created by Peter Westerstrom on 2020-12-18.
//
int main(int argc, char* argv[])
{
	int result = Catch::Session().run(argc, argv);
	return result;
}