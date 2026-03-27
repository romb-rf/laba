#include "intvalidator.h"
#include <QDebug>
#include <stdexcept>
IntValidator::IntValidator(QObject *parent)
    : QObject(parent)
{}
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
            throw std::invalid_argument("Строка не является целым числом: " + str.toStdString());
        }
        if (value < 0 || value > 81) {
            throw std::out_of_range("Значение должно быть в диапазоне 0 < n < 81");
        }
        return true;
    } catch (const std::invalid_argument &e) {
        m_lastError = QString::fromStdString(e.what());
        emit errorOccurred(m_lastError);
        emit lastErrorChanged();
        return false;
    } catch (const std::exception &e) {
        m_lastError = QString("ОШИБКА: %1").arg(e.what());
        emit errorOccurred(m_lastError);
        emit lastErrorChanged();
        return false;
    }
}
