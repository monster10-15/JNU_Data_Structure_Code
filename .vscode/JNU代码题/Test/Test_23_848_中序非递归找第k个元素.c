// 中序非递归找第k个元素
// 定义一个中序遍历函数，用于查找二叉树中的第k个元素
int InOrder(BiTree T, int k){
    InitStack(&S); // 初始化一个栈S
    int key = 0; // 定义一个计数器key，用于记录已经访问过的节点数量
    if(T==NULL) return; // 如果二叉树为空，则直接返回
    BiNode *p=T; // 定义一个指针p，初始化为二叉树的根节点
    // 当指针p不为空或者栈S不为空时，执行循环
    while(p!=NULL || !IsEmpty(S)){
        // 如果指针p不为空
        if(p){
            push(S, p); // 将指针p指向的节点压入栈S
            p = p->lchild; // 将指针p更新为其左子节点
        }
        // 如果指针p为空
        else{
            pop(S, p); // 从栈S中弹出一个节点，并将其赋值给指针p
            key++; // 将计数器key加1
            if(key==k) return p->data; // 如果计数器key等于k，返回指针p指向的节点的数据
            p=p->rchild; // 将指针p更新为其右子节点
        }
    }
}


//! 复习：【Test18】非递归先序找第K个元素
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
//! 拓展：后序非递归找第K个元素
int PostOrder(BiTree T, int k) {
    Stack *top;
    InitStack(&top);
    BiTree p = T;
    int tag, count = 0;
    while (p || !IsEmpty(top)) {
        while (p) {
            Push(&top, p, 0);
            p = p->lchild;
        }
        Pop(&top, &p, &tag);
        if (tag == 0) {
            Push(&top, p, 1);
            p = p->rchild;
        } else {
            count++;
            if (count == k) return p->data;
            p = NULL;
        }
    }
    return -1;
}