#include <gtest/gtest.h>
#include "../MOG/lib/Hello/Hello.h"
#include "../MOG/lib/point2d/point2d.h"
#include "../MOG/lib/diff/functionaudi.h"
#ifndef mathpi
#define mathpi 3.14159265358979323846264338
#endif
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
    ASSERT_EQ(A.mvx,0);
    ASSERT_EQ(A.mvy,0);
    ASSERT_EQ(B.mvx,0);
    ASSERT_EQ(B.mvy,0);
    ASSERT_EQ(C.theta,mathpi/2);
    ASSERT_EQ(D.theta,-mathpi/2);
    ASSERT_EQ(E.mvy,0.5);
    ASSERT_EQ(F.mvx,0.5);
    ASSERT_EQ(G.mvx,1.5);
    ASSERT_EQ(B.l1norm(),0);
    ASSERT_EQ(C.l1norm(),mathpi/2);
}
TEST(Rotation,multipling){
    Drotation A(0,0,mathpi/2);
    Drotation B(0,0,-mathpi/2);
    Drotation C(0,0,0,1,0);
    Drotation D(0,0,0,0,1);
    ASSERT_DOUBLE_EQ((C*A).mvx,1);
    ASSERT_DOUBLE_EQ((C*A).mvy,0);
    EXPECT_NEAR((A*C).mvx,0,1.0/(1<<14));
    EXPECT_NEAR((A*C).mvy,1,1.0/(1<<14));
}
TEST(Rotation,division){
    Drotation A(0,0,mathpi/2);
    Drotation B(0,0,-mathpi/2);
    Drotation C(0,0,0,1,0);
    Drotation D(0,0,0,0,1);
    ASSERT_DOUBLE_EQ(((C/A)*A).mvx,1);
    ASSERT_DOUBLE_EQ(((C/A)*A).mvy,0);
    EXPECT_NEAR(((A/C)*C).mvx,0,1.0/(1<<14));
    EXPECT_NEAR(((A/C)*C).mvy,0,1.0/(1<<14));
}
TEST(BasicFunctionTest, BasicScalar) {
    defineid(x);
    ASSERT_EQ((x*2+1).value(1), 3);
    ASSERT_EQ((((x-2)/4).value(1)), -0.25);
    ASSERT_EQ((x*2+1).der(1), 2);
    ASSERT_EQ((((x-2)/4).der(1)), 0.25);
}
TEST(BasicFunctionTest, BasicComputation) {
    defineid(x);
    ASSERT_EQ((x*2+x*3).value(2), 10);
    ASSERT_EQ(((x/2 -x/4).value(4)), 1);
    ASSERT_EQ(((x/2) *(x*2)).value(4), 16);
    ASSERT_EQ((x^x).value(1), 1);
    ASSERT_EQ((x*2+x*3).der(2), 5);
    ASSERT_EQ(((x/2 -x/4).der(4)), 0.25);
    ASSERT_EQ(((x/2) *(x*2)).der(4), 8);
    ASSERT_EQ((x^x).der(1), 1);
}
TEST(BasicFunctionTest, BasicFunction) {
    defineid(x);
    ASSERT_EQ((x*2+1).value(1), 3);
    ASSERT_EQ((((x-2)/4).value(1)), -0.25);
    ASSERT_EQ((x*2+1).der(1), 2);
    ASSERT_EQ((((x-2)/4).der(1)), 0.25);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}