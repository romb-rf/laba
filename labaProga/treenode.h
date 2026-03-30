#ifndef TREENODE_H
#define TREENODE_H

#include <QObject>
#include <QQmlListProperty>

class TreeNode : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int n READ n CONSTANT)
    Q_PROPERTY(long long result READ result CONSTANT)
    Q_PROPERTY(QQmlListProperty<TreeNode> children READ children CONSTANT)

public:
    explicit TreeNode(int n, long long res, QObject *parent = nullptr);
    ~TreeNode();

    int n() const { return m_n; }
    long long result() const { return m_result; }

    QQmlListProperty<TreeNode> children();
    void appendChild(TreeNode *child);

    // Статические методы для работы с QQmlListProperty
    static void appendChild(QQmlListProperty<TreeNode> *list, TreeNode *child);
    static qsizetype childCount(QQmlListProperty<TreeNode> *list);
    static TreeNode* childAt(QQmlListProperty<TreeNode> *list, qsizetype index);
    static void clearChildren(QQmlListProperty<TreeNode> *list);

private:
    int m_n;
    long long m_result;
    QList<TreeNode*> m_children;
};

#endif // TREENODE_H
