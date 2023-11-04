void Find_k(BiTree T, int k){
    InitStack(S);
    BiTNode *p=T;
    int a=0;
    while(p || !IsEmpty(S)){
        while(p){
            a++;
            visit(p);
            push(S,p);
            if(a==k){
                printf("%d\n",p->data);
                return;
            }
            p=p->lchild;
        }
        if(!IsEmpty(S)){
            pop(S,p);
            p=p->rchild;
        }
    }
}

