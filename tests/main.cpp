#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

#include "alloc_guard/alloc_guard.h"

#include <memory>

TEST_CASE("DefaultAllocGuardWithNoAlloc", "[allocguard]")
{
	AllocGuard guard;
}

TEST_CASE("DefaultAllocGuardWithAlloc", "[allocguard]")
{
	AllocGuard guard;

	std::unique_ptr<int>(new int);
}