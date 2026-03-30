#include "treenode.h"

TreeNode::TreeNode(int n, long long res, QObject *parent)
    : QObject(parent), m_n(n), m_result(res) {}

TreeNode::~TreeNode() {
    qDeleteAll(m_children);
}

QQmlListProperty<TreeNode> TreeNode::children() {
    return QQmlListProperty<TreeNode>(this, this,
                                      &TreeNode::appendChild,
                                      &TreeNode::childCount,
                                      &TreeNode::childAt,
                                      &TreeNode::clearChildren);
}

void TreeNode::appendChild(TreeNode *child) {
    m_children.append(child);
    child->setParent(this);
}

void TreeNode::appendChild(QQmlListProperty<TreeNode> *list, TreeNode *child) {
    static_cast<TreeNode*>(list->data)->appendChild(child);
}

qsizetype TreeNode::childCount(QQmlListProperty<TreeNode> *list) {
    return static_cast<TreeNode*>(list->data)->m_children.size();
}

TreeNode* TreeNode::childAt(QQmlListProperty<TreeNode> *list, qsizetype index) {
    return static_cast<TreeNode*>(list->data)->m_children.at(index);
}

void TreeNode::clearChildren(QQmlListProperty<TreeNode> *list) {
    static_cast<TreeNode*>(list->data)->m_children.clear();
}
