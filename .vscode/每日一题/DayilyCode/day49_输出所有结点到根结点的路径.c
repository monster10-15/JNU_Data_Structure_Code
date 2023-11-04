// TODO: 设计一个算法，增加一个指向双亲的parent指针，并给指向指针赋值，并输出所有结点到根结点的路径
// 1、parent指针意义何在？2、先解决单个结点的路径再遍历整个树
typedef struct BtNode{
    char data;
    struct BTNode *parent, *lchild, *rchild;
}BTNode;
// 1、设置parent指针
void AddDad(BTNode *p, BTNode *q){
    if(p!=null){
        p->parent=q;
        q=p;
        AddDad(p->lchild, q);
        AddDad(p->rchild, q);
    }
}
// 2、打印单个结点路径
void SinglePath(BTNode *p){
    while(p!=null){
        print("%c", p->data);
        p=p->parent;
    }
}
// 3、打印所有结点
void AllPaths(BTNode *p){
    if(p!=null){
        SinglePath(p->lchild);
        SinglePath(p->rchild);
    }
}
// 1023 review: 70/100
typedef struct BTNode{
    char data;
    struct BTNode *lchild, *rchild, *parent;
}BTNode;
void AddDad(BTNode *p, BTNode *q){
    p->parent = q;
    q=p;
    AddDad(p->lchild,q);
    AddDad(p->rchild,q);
}
void SinglePath(BTNode *p){
    while(p!=null){
        printf("%d", p);
        SinglePath(p->parent);
    }
}
void AllPaths(BTNode *p){
    if(p!=null){
        SinglePath(p->lchild);
        SinglePath(p->rchild);
    }
}
// 1024 review: 80/100
typedef struct BTNode{
    char data;
    BTNode *parent, *lchild, *rchild;
}BTNode;
void AddDad(BTNode *p, BTNode *q){
    if(p->parent==NULL){
        p->parent=q;
        q=p;
        Add(p->lchild,q);
        Add(p->rchild,q);
    }
}
void Single(BTNode *p){
    if(p->parent!=NULL){
        printf("%s", p->data);
        Single(p->parent);
    }
}
void All(BTNode *p){
    if(p){
        Single(p->lchild);
        Single(p->rchild);
    }
}

