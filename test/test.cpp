#include <gtest/gtest.h>
#include "../MOG/lib/Hello/Hello.h"
TEST(HelloWorld,hello){
    const char* x="Hello,world";
    ASSERT_EQ(*Hello_world(),*x);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}