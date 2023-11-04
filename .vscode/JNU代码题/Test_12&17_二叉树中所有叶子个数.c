// TODO: 计算二叉树中所有叶子结点个数n
int Countleaf_1(BiTree T){
    int n1, n2;
    if(T==NULL) return 0;
    else if(T->lchild==NULL && T->rchild==NULL) {
        return 1;
    }
    else{
        n1=Countleaf(T->lchild);
        n2=Countleaf(T->rchild);
        return n1+n2;
    }
}
// 1019 review:100/100 (突发奇想: 叶子节点个数=度2结点个数+1)
int all_nodes(BiTree &T){
    if(T==NULL) return 0;
    else{
        if(T->lchild  && T->rchild){ // N0=N2+1
            return 1+1 + all_nodes(T->lchild) + all_nodes(T->rchild);
        }
    }
}
int Countleaf_2(BiTree T){
    if(T==NULL) return 0;
    else{
        int lleaf=Countleaf_2(T->lchild);
        int rleaf=Countleaf_2(T->rchild);
    }
    return lleaf + rleaf;
}
