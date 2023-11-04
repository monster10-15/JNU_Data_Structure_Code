// TODO: 假设二叉树采用二叉链表存储结构，设计一个算法求二叉树的高度（递归和非递归）
// 递归算法思想: 递归求左子树高度右子树高度，取较大值+1
int BTD_1(BiTree T){
    if(T==NULL){
        return 0;
    }
    ldep=BTD_1(T->lchild);
    rdep=BTD_1(T->rchild);
    if(ldep>rdep){
        return ldep+1;
    }
    else{
        return rdep+1;
    }
}
// 非递归算法思想: 采用层级遍历算法，
// 首先判断二叉树是否为空，如果为空，则直接返回高度为0。
// 初始化变量level为0，用于记录当前的层数。
// 初始化队列Q，并将根节点T入队。
// 进入循环，当队列Q不为空时，执行以下操作：
// 获取当前队列Q的大小，即当前层的节点个数。
// 进入循环，遍历当前层的所有节点：
// 弹出队首元素p，并访问该节点。
// 如果p的左子节点存在，则将左子节点入队。
// 如果p的右子节点存在，则将右子节点入队。
// 当前层的所有节点已经遍历完毕，将level加1。
// 返回level作为二叉树的高度。
int BTH_1(BiTree T){
    if(!T){
        return 0; // 如果二叉树为空，直接返回高度为0
    }
    int level = 0; // 初始化变量level为0，用于记录当前的层数
    Queue Q; // 定义一个队列Q
    InitQueue(&Q); // 初始化队列Q
    EnQueue(&Q, T); // 将根节点T入队
    while(!QueueEmpty(Q)){ // 当队列Q不为空时，执行以下操作
        int size = QueueSize(Q); // 获取当前队列Q的大小，即当前层的节点个数
        for(int i = 0; i < size; i++){ // 遍历当前层的所有节点
            BiTree p;
            DeQueue(&Q, &p); // 弹出队首元素p，并访问该节点
            if(p->lchild){ // 如果p的左子节点存在，则将左子节点入队
                EnQueue(&Q, p->lchild);
            }
            if(p->rchild){ // 如果p的右子节点存在，则将右子节点入队
                EnQueue(&Q, p->rchild);
            }
        }
        level++; // 当前层的所有节点已经遍历完毕，将level加1
    }
    return level; // 返回level作为二叉树的高度
}
// 1017 review: 0/100
int BTD_2(BiTree T){
    if(T==NULL) return 0;
    int ldep=BTD_2(T->lchild);
    int rdep=BTD_2(T->rchild);
    return ldep>rdep? ldep+1:rdep+1;
}
// 1017 review: 60/100
int BTH_2(BiTree T){
    if(T==NULL) return 0;
    BiTree *p = T;
    int level = 0;
    Queue Q;
    InitQueue(&Q);
    EnQueue(&Q, p);
    while(!IsEmpty(&Q)){
        int size=QueueSize(Q);
        while(size>0){
            DeQueue(&Q, &p);
            visit(p);
            if(p->lchild!=NULL){
                EnQueue(&Q, p->lchild);
            }
            if(p->rchild!=NULL){
                EnQueue(&Q, p->rchild);
            }
            size--;
        }
        level++;
    }
    return level;
}
// 1018 review: 70/100
int BTD_3(BiTree T){
    int LD=0, RD=0;
    if(T==NULL) return 0;
    if(T){
        LD=BTD_3(T->lchild);
        RD=BTD_3(T->rchild);
    }
    return LD>BD?LD+1:BD+1;
}
int BTH_3(BiTree T) {
    if (T == NULL) {
        return 0;
    }   
    Queue q; // 创建一个队列，用于存储二叉树节点指针
    q.push(T); // 将根节点入队
    int height = 0; // 初始化高度为0
    while (!q.isEmpty() || T != NULL) { // 当队列不为空或者当前节点不为空时进行循环
        int size = q.size(); // 获取当前层的节点个数
        for (int i = 0; i < size; i++) { // 遍历当前层的节点
            BiTree node = q.front(); // 取出队列的第一个节点
            q.pop(); // 出队
            if (node->lchild != NULL) { // 如果当前节点有左子节点
                q.push(node->lchild); // 将左子节点入队
            }
            if (node->rchild != NULL) { // 如果当前节点有右子节点
                q.push(node->rchild); // 将右子节点入队
            }
        }   
        height++; // 当前层遍历完成，高度加1
    }
    return height; // 返回二叉树的高度
}
// 1019 review: 80/100
int BTD_4(BiTree T){
    if(T == NULL) return 0; 
    else{
        int LD=BTD_4(T->lchild);
        int RD=BTD_4(T->rchild);
    }
    return LD>RD? LD+1: RD+1;
}
int BTH_4(BiTree T){
    if(T == NULL) return 0;
    else{
        int level = 0;
        InitQueue Q;
        Q.push(T);
        int len = Q.size();
        while(len>0){
            Q.pop();
            BiTree *node=Q.front();
            if(node->lchild){
                Q.push(node->lchild);
                node=node->lchild;
            }
            if(node->rchild){
                Q.push(node->rchild);
                node=node->rchild;
            }
            len--;
        }
        level++;
    }
    return level;
}
// 1020 review: 70/100
int BTD_5(BiTree T){
    if(T==NULL){ return 0; }
    int BL=BTD_5(T->lchild);
    int RL=BTD_5(T->rchild);
    return BL>RL?BL+1:RL+1;
}
int BTH_5(BiTree T){
if(T==NULL){ return 0; }
else{
    InitQueue (Q);
    Q.push(T);
    int level=0;
    int len=Q.size();
    while(len>0){
        Q.pop();
        BiTree *root=Q.front();
        if(root->lchild){
            root=root->lchild;
        }
        if(root=root->rchild){
            root=root->rchild;
        }
        len--;
    }
    level++;
}
return level;
}
// 1021 review: 85/100
int BTD_6(BiTree T){
    if(T==NULL){ return 0; }
    else{
        LD=BD_6(T->lchild);
        RD=BD_6(T->rchild);
    }
    return LD>BD?LD+1:RD+1;
}
int BTH_6(BiTree T){
    if(T==NULL){ return 0;}
    else{
        int level = 0;  
        InitQueue (Q);
        Q.push(T);
        int len=Q.size();
        while(len--){
            Q.pop();
            p=Q.front();
            if(p->lchild){
                Q.push(p->lchild);
            }
            if(p->rchild){
                Q.push(p->rchild);
            }
        }
        level++;
    }
    return level;
}