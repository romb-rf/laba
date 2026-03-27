#ifndef INTVALIDATOR_H
#define INTVALIDATOR_H
#include <QObject>
#include <QString>
class IntValidator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString lastError READ lastError NOTIFY lastErrorChanged)
public:
    explicit IntValidator(QObject *parent = nullptr);
    QString lastError() const;
signals:
    void errorOccurred(const QString &message);
    void lastErrorChanged();

public slots:
    bool checkInt(const QString &str);
    void clearError();

private:
    QString m_lastError;
};
#endif
