//#define DOCTEST_CONFIG_IMPLEMENTATION_IN_DLL
//#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"

TEST_CASE("Test Doctest"){
    CHECK(1>= 0.999999);
}
