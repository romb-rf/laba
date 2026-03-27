#include <gtest/gtest.h>
#include <QSignalSpy>
#include "doptask.h"

class DopTaskTest : public ::testing::TestWithParam<std::pair<int, QString>> {
protected:
    DopTask task;
};

TEST_P(DopTaskTest, factorization) {
    auto [input, expected] = GetParam();
    task.calculate(input);
    EXPECT_EQ(task.res(), expected);
}

INSTANTIATE_TEST_SUITE_P(
    FactorizationTests,
    DopTaskTest,
    ::testing::Values(
        std::make_pair(12, "2 2 3"),
        std::make_pair(17, "17"),
        std::make_pair(1, ""),
        std::make_pair(100, "2 2 5 5"),
        std::make_pair(13, "13"),
        std::make_pair(18, "2 3 3")
        )
    );

TEST(DopTaskSignalTest, signalEmittedOnlyOnChange) {
    DopTask task;
    QSignalSpy spy(&task, &DopTask::resChanged);

    task.calculate(12);
    EXPECT_EQ(spy.count(), 1);

    task.calculate(12);
    EXPECT_EQ(spy.count(), 1);

    task.calculate(18);
    EXPECT_EQ(spy.count(), 2);
}
