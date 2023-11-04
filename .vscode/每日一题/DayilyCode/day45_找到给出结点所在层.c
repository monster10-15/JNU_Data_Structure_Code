//TODO: 若二叉排序树采用链式存储结构，设法求出指定结点在给定二叉排序树的所在层次
int level(BiTree *T, BiTree *p){
    int level=1;
    BiTree *t=T;// 遍历指针
    if(T!=null){
        while(t->data!=p->data){
            if(t->data<p->data){
                t=t->rchild;// 比p所指小，去右边找
            }
            else{
                t=t->lchild;// 比p所指大，去右边找
                ++level;
            }
        }
    }
}
// 1021 review: 100/100
int level(BiTree *T, BiTree *p){
    int level = 0;
    BiTree *NPC=T;
    while(p){
        level++;
        if(NPC->data==p->data){
            return level;
        }
        else{
            if(NPC->data>p->data){
                NPC=NPC->lchild;
            }
            if(NPC->data<p->data){
                NPC=NPC->rchild;
            }
            level++;
        }
    }
}