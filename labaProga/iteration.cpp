#include "iteration.h"
#include <QDebug>
#include <chrono>
#include <vector>
using namespace std;
Iteration::Iteration(QObject *parent):QObject(parent), m_result(0), m_callCnt(0), index(0), m_cnt(0) {
}

void Iteration::onComboIndexChanged(int indexInp){

    index = indexInp;

}
void Iteration::calculate(int n){

    auto start = std::chrono::high_resolution_clock::now();
    switch (index) {
    case 0:

        m_result = iterationFuncVar1(n);


        break;

    case 1:
        m_result = iterationFuncVar2(n);
        break;
    default:
        break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = end - start;
    m_cnt = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();



    emit resultChanged();
    emit callCntChanged();
    emit cntChanged();
    emit calculationDone(m_result, m_callCnt, m_cnt);
}
void Iteration::reset(){
    m_result = 0;
    m_callCnt = 0;
    emit resultChanged();
    emit callCntChanged();
}
int Iteration::iterationFuncVar1(int n)
{
    if (n <= 1) {
        m_callCnt = 0;
        return 1;
    }


    int prev = 3;
    if (n == 2) {
        m_callCnt = 0;
        return prev;
    }

    int result = 0;
    m_callCnt = 0;

    for (int i = 3; i <= n; ++i) {
        if (i % 2 == 0) {
            result = 3 * prev;
        } else {
            result = 4 * i + prev - 3;
        }
        prev = result;
        m_callCnt++;
    }

    return result;


}
int Iteration::iterationFuncVar2(int n)
{
    if (n == 1) {
        m_callCnt = 0;
        return 1;
    }
    if (n == 2) {
        m_callCnt = 0;
        return 2;
    }


    vector<int> f(n + 1);
    f[1] = 1;
    f[2] = 2;

    m_callCnt = 0;

    for (int i = 3; i <= n; ++i) {
        if (i % 2 == 0) {
            f[i] = int((7 * i + f[i - 3]) / 9);
        } else {
            f[i] = int((5 * i + f[i - 1] + f[i - 2]) / 7);
        }
        ++m_callCnt;
    }

    return f[n];
}
