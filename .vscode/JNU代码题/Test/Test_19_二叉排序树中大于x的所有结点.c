// 从大到小输出二叉排序树中所有值不小于x的关键字
void find(BiTree T, int x) {
    if (T == NULL) {
        return;
    }
    
    if (T->data >= x) {
        find(T->rchild, x);  // 先遍历右子树
        find(T->lchild, x);  // 再遍历左子树
        printf("%d\n", T->data);  // 输出当前节点的值
    } else {
        find(T->rchild, x);  // 只遍历右子树
    }
}