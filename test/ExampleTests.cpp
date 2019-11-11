#include <gtest/gtest.h>
#include "../Example.hpp"

int gValue = 42;
bool f() {
    return true;
}

TEST(ExampleTests, DemonstrateGTestMacro) {

    EXPECT_EQ(true, f()) << " but value " << gValue;
    EXPECT_EQ(5, MAC(2,3,0));
}