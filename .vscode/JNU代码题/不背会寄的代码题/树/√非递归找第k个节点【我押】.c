//! 中序非递归找第k个元素
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
//! 非递归先序找第K个元素
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
//! 后序非递归找第K个元素
void PostOrderKth(BiTree T, int k){
    Stack S;
    InitStack(&S);
    BiTree p = T;
    BiTree r = NULL;
    int count = 0; // 添加计数器
    while(p || !StackEmpty(S)){
        if(p->lchild){
            Push(&S,p);// 一路向左
            p = p->lchild;// 左孩子不空，一直向左走
        }
        else{
            BiTree *top=GetTop(S,p);// 栈顶元素
            if(top->rchild && top->rchild != r){// 若右子树非空且未被访问过
                p = top->rchild;
                Push(&S,p);
                p = p->lchild;// 转左
            }
            else{// 若右子树为空或被访问过则出栈
                Pop(&S,p);
                count++; // 访问一个节点，计数器加1
                if(count == k){ // 如果计数器等于k
                    visit(p); // 访问该节点
                    break; // 找到第k个节点，结束循环
                }
                r = p;// r标记最近访问过的结点
                p = NULL;
            }
        }
    }
}
