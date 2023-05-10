#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

TEST_CASE("expressions should be evaluated only once") {
    int a = 5;
    REQUIRE(++a == 6);
    REQUIRE_EQ(++a, 7);
}