#include <gtest/gtest.h>
#include "../MOG/lib/Hello/Hello.h"
#include "../MOG/lib/point2d/point2d.h"
#define mathpi 3.14159265358979323846264338
#define Dpoint2d point2d<double>
#define Drotation rotation<double>
TEST(HelloWorld,hello){
    const char* x="Hello,world";
    ASSERT_EQ(*Hello_world(),*x);
}
TEST(Point2d,initializing){
    Dpoint2d A;
    Dpoint2d B(1.5,2.5);
    ASSERT_EQ(A.x,0);
    ASSERT_EQ(A.y,0);
    ASSERT_EQ(B.x,1.5);
    ASSERT_EQ(B.y,2.5);
}
TEST(Point2d,Rotationing){
    Dpoint2d A(1,0);
    Drotation B;
    Drotation C(0,0,mathpi/2);
    Drotation D(0,0,-mathpi/2);
    Drotation E(0,0,mathpi/6,std::sqrt(3.0)/2,0.5);
    Drotation F(0,0,mathpi/3,0.5,std::sqrt(3.0)/2);
    Drotation G(-1,0,mathpi/3,1,0);
    EXPECT_DOUBLE_EQ((A.rotate(B)).x,1);
    EXPECT_DOUBLE_EQ((A.rotate(C)).y,1);
    EXPECT_DOUBLE_EQ((A.rotate(D)).y,-1);
    EXPECT_NEAR((A.rotate(E)).x,0,1.0/(1<<14));
    EXPECT_NEAR((A.rotate(E)).y,0,1.0/(1<<14));
    EXPECT_NEAR((A.rotate(F)).x,0,1.0/(1<<14));
    EXPECT_NEAR((A.rotate(F)).y,0,1.0/(1<<14));
    EXPECT_NEAR((A.rotate(G)).x,-1,1.0/(1<<14));
}
TEST(Rotation,initializing){
    Drotation A;
    Drotation B(1,0,0);
    Drotation C(0,0,mathpi/2);
    Drotation D(0,0,-mathpi/2);
    Drotation E(0,0,mathpi/6,0,0.5);
    Drotation F(0,0,mathpi/3,0.5,0);
    Drotation G(-1,0,mathpi/3,1,0);
    ASSERT_EQ(A.x,0);
    ASSERT_EQ(A.y,0);
    ASSERT_EQ(B.x,1);
    ASSERT_EQ(B.y,0);
    ASSERT_EQ(C.theta,mathpi/2);
    ASSERT_EQ(D.theta,-mathpi/2);
    ASSERT_EQ(E.mvy,0.5);
    ASSERT_EQ(F.mvx,0.5);
    ASSERT_EQ(G.mvx,1);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}