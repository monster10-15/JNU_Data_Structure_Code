//!先序非递归找第k个元素
void PreOrder(BiTree T, int k){
    Stack S;
    int x = 0;
    InitStack (&S);
    BiTNode *p = T;
    while(p || !IsEmpty(S)){
        while(p){
            visit (p);
            Push(S, p);
            k++;
            if(k == x){
                return p->data;
            }
            p=p->lchild;
        }
        while(!IsEmpty(S)){
            pop(p);
            p=p->rchild;
        }
    }
}
