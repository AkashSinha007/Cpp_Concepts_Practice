#include <gtest/gtest.h>
#include "../Example.hpp"


struct ExampleTests: public::testing::Test
{
    int* x;

    int GetX()
    {
        return *x;
    }

    virtual void SetUp() override
    {
        fprintf(stderr,"Starting up!\n");
        x=new int(42);
    }

    virtual void TearDown() override
    {
        fprintf(stderr,"Tearing down!\n");
        delete x;
    }
};

TEST(ExampleTests,Square)
{
    int x=5;
    int expectedSquare = x*x;
    EXPECT_EQ(
        expectedSquare,
        Square(x)
    );
}

TEST_F(ExampleTests,Square)   //"Fixture"
{
    int x=5;
    int expectedSquare = GetX()*GetX();
    EXPECT_EQ(
        expectedSquare,
        Square(GetX())
    );
}