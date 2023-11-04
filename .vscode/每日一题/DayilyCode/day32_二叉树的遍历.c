typedef struct BiTNode{
    ElemyType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTNode;
void PreOrder(BiTNode T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void MidOrder(BiTNode T){
    if(T!=NULL){
        MidOrder(T->lchild);
        visit(T);
        MidOrder(T->rchild);
    }
}
void PostOrder(BiTNode T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}
// 1014 review: 100/100
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void MidOrder(BiTNode T){
    if(T!=NULL){
        MidOrder(T->lchild);
        visit(T);
        MidOrder(T->rchild);
    }
}
void PostOrder(BiTNode T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}