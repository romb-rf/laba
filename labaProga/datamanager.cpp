#include "datamanager.h"

DataManager::DataManager(QObject *parent) : QObject(parent) {}

QString DataManager::userInput() const
{
    return m_userInput;
}

void DataManager::setUserInput(const QString &newUserInput)
{
    if (m_userInput == newUserInput)
        return;
    m_userInput = newUserInput;
    emit userInputChanged();
}

void DataManager::saveData(const QString &data)
{

    m_userInput = data;
    emit userInputChanged();
}


