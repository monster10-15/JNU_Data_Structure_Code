// TODO: 假设二叉树采用二叉链表结构存储，设计一个算法求二叉树中值为x的层号
// 1、遍历二叉树，2、思考何时层+1(访根后)？何时层-1(rchild)？
int h=1;
void fun(BTNode *p, int x){
    if(p!=null){
        if(p->data==x){
            printf("%d", h);
        }
        ++h;
        fun(p->lchild, x);
        fun(p->rchild, x);
        --h;
    }
}
// 1023 review: 60/100
int depth = 1;
void fun(BTNode *p, int x){
    if(p!=null){
        if(p->data==x){
            printf("%d", depth);
        }
        depth++;
        fun(p->lchild, x);
        fun(p->rchild, x);
        depth--;
    }
}
// TODO: 1024 review: 100/100
int h=1;
void fun(BTNode *p, int x){
    if(p==null){
        return ;
    }
    else{
        if(p->data==x){
            printf("%d", h);
        }
        h++;
        fun(p->lchild,x);
        fun(p->rchild,x);
        h--;
    }
}
