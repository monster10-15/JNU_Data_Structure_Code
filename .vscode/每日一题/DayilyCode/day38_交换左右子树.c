// 递归地交换左右子树
void Swap(BiTree T){
    if(T){
        Swap(T->lchild);
        Swap(T->rchild);
        BiTree temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}
// 1017 review: 0/100
void Swap(BiTree T){
    if(T){
        Swap(T->lchild);
        Swap(T->rchild);
        BiTree temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}
// 1018 review: 80/100
void Swap(BiTree T){
    if(T==NULL) {return;}
    if(T){
        Swap(T->lchild);
        Swap(T->rchild);
        BiTree *temp=T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
}
// 1019 review: 100/100
void Swap(BiTree T){
    if(T==NULL) {return 0;}
    else{
        Swap(T->lchild);
        Swap(T->rchild);
        BiTree *temp=T->lchild;
        T->lchild=T->rchild;
        T->rchild=temp;
    }
}