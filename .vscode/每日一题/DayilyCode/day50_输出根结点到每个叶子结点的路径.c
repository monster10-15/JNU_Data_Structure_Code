// 算法思想: 1、先序遍历 2、对特殊的结点(叶子结点)处理 3、栈
int i = 0, top = 0;
Elemtype Stack[Maxsize];
void Path(BTNode *p){
    if(p!=null){
        Stack [top] = p->data;
        ++ top;
    }
    if(p->lchild ==null && p->rchild==null){
        for(int i=0, i<top, ++i){
            printf("%d", Stack[i]);
            Path(p->lchild);
            Path(p->rchild);
            --top;
        }
    }
}
// TODO: 1023 review: 90/100
InitStack (&S);
void Path(BTNode *p) {
    if(p==NULL) return;
    else{
        S.push(p);
        if(p->lchild==null && p->rchild==null){
            for(int i=0;i<S.size();i++){
                printf("%d", S[i]);
            }
            printf("\n");
        }
        if(p->lchild){
            Path(p->lchild);
        }
        if(p->rchild){
            Path(p->rchild);
        }
        S.pop();
    }
}
