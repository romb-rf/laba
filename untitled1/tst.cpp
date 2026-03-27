#include <gtest/gtest.h>
#include "recursionVar1.h"

class TestRecursionFixture : public ::testing::Test {
protected:
    void SetUp() override {
        testObj = new ::Test();
    }

    void TearDown() override {
        delete testObj;
    }

    ::Test* testObj;
};


TEST_F(TestRecursionFixture, Var1_Values) {
    testObj->onComboIndexChanged(0);
    testObj->reset();

    testObj->calculate(0);
    EXPECT_EQ(testObj->result(), 1);

    testObj->calculate(1);
    EXPECT_EQ(testObj->result(), 1);

    testObj->calculate(2);
    EXPECT_EQ(testObj->result(), 3);

    testObj->calculate(3);
    EXPECT_EQ(testObj->result(), 12);

    testObj->calculate(4);
    EXPECT_EQ(testObj->result(), 36);

    testObj->calculate(5);
    EXPECT_EQ(testObj->result(), 53);
}


TEST_F(TestRecursionFixture, Var2_Values) {
    testObj->onComboIndexChanged(1);
    testObj->reset();

    testObj->calculate(1);
    EXPECT_EQ(testObj->result(), 1);

    testObj->calculate(2);
    EXPECT_EQ(testObj->result(), 2);

    testObj->calculate(3);
    EXPECT_EQ(testObj->result(), 2);

    testObj->calculate(4);
    EXPECT_EQ(testObj->result(), 3);

    testObj->calculate(5);
    EXPECT_EQ(testObj->result(), 4);

    testObj->calculate(6);
    EXPECT_EQ(testObj->result(), 4);

    testObj->calculate(7);
    EXPECT_EQ(testObj->result(), 6);

    testObj->calculate(8);
    EXPECT_EQ(testObj->result(), 6);
}

TEST_F(TestRecursionFixture, CallCountTest) {
    testObj->onComboIndexChanged(0);
    testObj->reset();
    testObj->calculate(2);

    EXPECT_EQ(testObj->callCnt(), 2);
}

TEST_F(TestRecursionFixture, ExecutionTimeTest) {
    testObj->onComboIndexChanged(0);
    testObj->reset();
    testObj->calculate(5);
    EXPECT_GT(testObj->cnt(), 0);
}
