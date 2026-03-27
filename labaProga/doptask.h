#ifndef DOPTASK_H
#define DOPTASK_H
#include <Qobject>


using namespace std;
class DopTask : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString res READ res NOTIFY resChanged)


public:
    explicit DopTask(QObject *parent = nullptr);
    QString res() const { return m_res; }


public slots:
    void calculate(int n);

signals:
    void resChanged();

private:
    QString m_res;
};


#endif
