#include "intvalidator.h"
#include <QDebug>
#include <stdexcept>

IntValidator::IntValidator(QObject *parent)
    : QObject(parent)
{
}

QString IntValidator::lastError() const
{
    return m_lastError;
}
void IntValidator::clearError()
{

    m_lastError.clear();
    emit lastErrorChanged();

}
bool IntValidator::checkInt(const QString &str)
{
    m_lastError.clear();
    try {
        bool ok;
        int value = str.toInt(&ok);
        if (!ok) {
            throw std::invalid_argument("String is not a valid integer: " + str.toStdString());
        }
        return true;
    } catch (const std::invalid_argument &e) {
        m_lastError = QString::fromStdString(e.what());
        emit errorOccurred(m_lastError);
        emit lastErrorChanged();
        return false;
    } catch (const std::exception &e) {
        m_lastError = QString("Exception: %1").arg(e.what());
        emit errorOccurred(m_lastError);
        emit lastErrorChanged();
        return false;
    }
}
