#include <gtest/gtest.h>
#include "iteration.h"

class IterationTestFixture : public ::testing::Test {
protected:
    void SetUp() override {
        iterObj = new ::Iteration();
    }

    void TearDown() override {
        delete iterObj;
    }

    ::Iteration* iterObj;
};

TEST_F(IterationTestFixture, Var1_Values) {
    iterObj->onComboIndexChanged(0);
    iterObj->reset();

    iterObj->calculate(0);
    EXPECT_EQ(iterObj->result(), 1);

    iterObj->calculate(1);
    EXPECT_EQ(iterObj->result(), 1);

    iterObj->calculate(2);
    EXPECT_EQ(iterObj->result(), 3);

    iterObj->calculate(3);
    EXPECT_EQ(iterObj->result(), 12);

    iterObj->calculate(4);
    EXPECT_EQ(iterObj->result(), 36);

    iterObj->calculate(5);
    EXPECT_EQ(iterObj->result(), 53);

    iterObj->calculate(6);
    EXPECT_EQ(iterObj->result(), 159);

    iterObj->calculate(7);
    EXPECT_EQ(iterObj->result(), 184);
}

TEST_F(IterationTestFixture, Var2_Values) {
    iterObj->onComboIndexChanged(1);
    iterObj->reset();

    iterObj->calculate(1);
    EXPECT_EQ(iterObj->result(), 1);

    iterObj->calculate(2);
    EXPECT_EQ(iterObj->result(), 2);

    iterObj->calculate(3);
    EXPECT_EQ(iterObj->result(), 2);

    iterObj->calculate(4);
    EXPECT_EQ(iterObj->result(), 3);

    iterObj->calculate(5);
    EXPECT_EQ(iterObj->result(), 4);

    iterObj->calculate(6);
    EXPECT_EQ(iterObj->result(), 4);

    iterObj->calculate(7);
    EXPECT_EQ(iterObj->result(), 6);

    iterObj->calculate(8);
    EXPECT_EQ(iterObj->result(), 6);
}

TEST_F(IterationTestFixture, CallCountTest) {
    iterObj->onComboIndexChanged(0);
    iterObj->reset();
    iterObj->calculate(2);
    EXPECT_EQ(iterObj->callCnt(), 0);

    iterObj->reset();
    iterObj->calculate(3);
    EXPECT_EQ(iterObj->callCnt(), 1);

    iterObj->reset();
    iterObj->calculate(4);
    EXPECT_EQ(iterObj->callCnt(), 2);
}

TEST_F(IterationTestFixture, ExecutionTimeTest) {
    iterObj->onComboIndexChanged(0);
    iterObj->reset();
    iterObj->calculate(10);
    EXPECT_GT(iterObj->cnt(), 0);
}
