// TODO: 计算二叉树中所有结点个数
// 递归法
int all_nodes(BiTree &T){
    if(T==NULL){ return 0; }
    else{
        return 1 + all_nodes(T->lchild) + all_nodes(T->rchild);
    }
}
// 遍历法（本质是递归）
int Count(BiTree T){
    int n=0;
    if(T!=NULL){
        n++;
        n += Count(T->lchild);
        n += Count(T->rchild);
    }
    return n;
}
// 1019 review: 100/100 
int all_leaves(BiTree T){
    if(T==NULL) return 0;
    else{
        return all_leaves(T->lchild)+all_leaves(T->rchild)+1;
    }
}