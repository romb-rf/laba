#include "doptask.h"
#include <vector>
#include <QString>
DopTask::DopTask(QObject *parent) : QObject(parent), m_res(""){}
void DopTask::calculate(int n)
{
    std::vector<int> div;
    int temp = n;
    while (temp % 2 == 0) {
        div.push_back(2);
        temp /= 2;
    }
    for (int i = 3; i * i <= temp; i += 2) {
        while (temp % i == 0) {
            div.push_back(i);
            temp /= i;
        }
    }
    if (temp > 1) {
        div.push_back(temp);
    }
    QString result;
    for (size_t i = 0; i < div.size(); ++i) {
        if (i != 0) result += " ";
        result += QString::number(div[i]);
    }
    if (m_res != result) {
        m_res = result;
        emit resChanged();
    }
}
