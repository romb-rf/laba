#include <gtest/gtest.h>
#include <QSignalSpy>
#include "datamanager.h"

class DataManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        manager = new DataManager();
    }

    void TearDown() override {
        delete manager;
    }

    DataManager* manager;
};

TEST_F(DataManagerTest, SetAndGetUserInput) {
    const QString testData = "Hello, world!";
    manager->setUserInput(testData);
    EXPECT_EQ(manager->userInput(), testData);
}

TEST_F(DataManagerTest, SetSameValueDoesNotEmitSignal) {
    const QString initialData = "Initial";
    manager->setUserInput(initialData);

    QSignalSpy spy(manager, &DataManager::userInputChanged);
    manager->setUserInput(initialData);

    EXPECT_EQ(spy.count(), 0);
    EXPECT_EQ(manager->userInput(), initialData);
}


TEST_F(DataManagerTest, SaveDataEmitsSignal) {
    const QString newData = "Saved data";
    QSignalSpy spy(manager, &DataManager::userInputChanged);

    manager->saveData(newData);

    EXPECT_EQ(spy.count(), 1);
    EXPECT_EQ(manager->userInput(), newData);
}


TEST_F(DataManagerTest, SaveDataEmitsSignalEvenIfSame) {
    const QString data = "Some data";
    manager->saveData(data);
    QSignalSpy spy(manager, &DataManager::userInputChanged);

    manager->saveData(data);

    EXPECT_EQ(spy.count(), 1);
    EXPECT_EQ(manager->userInput(), data);
}
