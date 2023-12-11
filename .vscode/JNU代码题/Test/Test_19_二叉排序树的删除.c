// TODO: 代码解读及算法思路可参考文章: https://www.cnblogs.com/yutian-blogs/p/15138913.html
// 定义二叉树的节点结构
typedef struct BiTNode {
    TElemType data; // 节点数据
    struct BiTNode *lchild, *rchild; // 左右子节点
} BiTNode, *BiTree;

// 删除二叉排序树中的一个节点
Status DeleteBST(BiTree &T, KeyType key) {
    if (!T) return FALSE; // 如果树为空，则返回FALSE
    else { 
        if (EQ(key, T->data.key)) return Delete(T); // 如果找到了要删除的节点，则删除该节点
        else if (LT(key, T->data.key)) return DeleteBST(T->lchild, key); // 如果要删除的节点的值小于当前节点的值，则在左子树中删除
        else return DeleteBST(T->rchild, key); // 如果要删除的节点的值大于当前节点的值，则在右子树中删除
    }
}

// 删除一个节点
Status Delete(BiTree &p) {
    BiTree q, s;
    if (!p->rchild) { // 如果节点的右子树为空
        q = p; 
        p=p->lchild; // 则让节点的左子树替代该节点
        free(q); // 释放该节点
    }
    else if (!p->lchild) { // 如果节点的左子树为空
        q = p; 
        p=p->rchild; // 则让节点的右子树替代该节点
        free(q); // 释放该节点
    }
    else { // 如果节点的左右子树都不为空
        q = p; 
        s=p->lchild; // 找到节点的左子树
        while (s->rchild!=NULL) { // 找到左子树中最大的节点
            q = s; 
            s = s->rchild; 
        }
        p->data = s->data; // 用左子树中最大的节点替代要删除的节点
        if (q != p) q->rchild = s->lchild; // 如果最大的节点不是左子树的根节点
        else q->lchild=s->lchild; // 如果最大的节点是左子树的根节点
        free(s); // 释放最大的节点
    }
    return TRUE;
}
