#include "recursionVar1.h"
#include <QDebug>
#include <chrono>

using namespace std;

Test::Test(QObject *parent):QObject(parent), m_result(0), m_callCnt(0), index(0), m_cnt(0) {

}

void Test::onComboIndexChanged(int indexInp){

    index = indexInp;

}
void Test::calculate(int n){
    m_callCnt = 0;
    auto start = std::chrono::high_resolution_clock::now();
    switch (index) {
    case 0:

        m_result = recursionFuncVar1(n);

        break;

    case 1:
        m_result = recursionFuncVar2(n);
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
void Test::reset(){
    m_result = 0;
    m_callCnt = 0;
    emit resultChanged();
    emit callCntChanged();
}
int Test::recursionFuncVar1(int n)
{

    m_callCnt++;

    if (n <= 1) {
        return 1;
    }
    if (n > 1 && n % 2 != 0) {
        return 4 * n + recursionFuncVar1(n - 1) - recursionFuncVar1(2);
    }
    if (n > 1 && n % 2 == 0) {
        return 3 * recursionFuncVar1(n - 1);
    }

    return 0;
}
int Test::recursionFuncVar2(int n)
{

    m_callCnt++;

    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (n > 2 && n % 2 == 0) {
        return int((7 * n + recursionFuncVar2(n - 3)) / 9);
    }
    if (n > 2 && n % 2 != 0) {
        return int((5 * n + recursionFuncVar2(n - 1) + recursionFuncVar2(n - 2)) / 7);
    }
    return 0;


}
