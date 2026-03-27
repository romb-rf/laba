#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <QObject>
#include <QString>
using namespace std;

class DataManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userInput READ userInput WRITE setUserInput NOTIFY userInputChanged)
public:
    explicit DataManager(QObject *parent = nullptr);
    QString userInput() const;
    void setUserInput(const QString &newUserInput);


signals:
    void userInputChanged();
public slots:
    void saveData(const QString &data);

private:
    QString m_userInput;


};

#endif // DATAMANAGER_H
