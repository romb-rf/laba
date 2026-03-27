#ifndef RECURSIONVAR1_H
#define RECURSIONVAR1_H
#include <Qobject>
#include <QDebug>
using namespace std;

class Test : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int result READ result NOTIFY resultChanged)
    Q_PROPERTY(int callCnt READ callCnt NOTIFY callCntChanged)
    Q_PROPERTY(int cnt READ cnt NOTIFY cntChanged)
public:
    explicit Test(QObject *parent = nullptr);
    int result() const {return m_result;}
    int callCnt() const {return m_callCnt;}
    int cnt() const {return m_cnt;}

public slots:
    void onComboIndexChanged(int n);
    void calculate(int n);
    void reset();

signals:
    void resultChanged();
    void callCntChanged();
    void cntChanged();
    void calculationDone(int result, int calls, int time);
    void errorOccurred(QString message);

private:
    uint32_t time = 0;
    int index = 0;
    int recursionFuncVar1(int n);
    int recursionFuncVar2(int n);
    int m_result;
    int m_callCnt;
    int m_cnt;
};

#endif
