#include <gtest/gtest.h>
#include "../MOG/lib/Hello.h"
TEST(HelloWorld,hello){
    char* x="Hello,world";
    ASSERT_EQ(*x,*Hello_world());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}