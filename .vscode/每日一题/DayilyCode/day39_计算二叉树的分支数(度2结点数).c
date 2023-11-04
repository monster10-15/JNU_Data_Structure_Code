// TODO: 假设二叉树采用二叉链表存储结构存储，试计算一颗给定二叉树的所有分支（度为2）的结点个数
int BiTNode(BiTree T){
    if(T==NULL) return 0;
    else if(T->lchild && T->rchild){
        return 1  + BiTNode(T->lchild) + BiTNode(T->rchild);
    }
}
// 1019 review: 100/100
int BiTNode(BiTNode T){
    if(T==NULL) return 0;
    else{
        if(T->lchild && T->rchild){
            return  BiTNode(T->lchild) + BiTNode(T->rchild)+1;
        }
    }
}