// 算法思想: （队列）1.将根节点入队，出队 2.访问出队结点，若它有左子树，则将左子树入队 3.若它有右子树，则将右子树入队...如此反复直至队列为空
// TODO: 入队出队访问，有左入左，有右入右
void LevelOrder(BiTree T){
    Queue Q;
    InitQueue(&Q); // 初始化队列Q
    BiTree p = T;
    EnQueue(Q, p); // 将根结点入队
    while(!IsEmpty(Q)){
        DeQueue(Q, p); // 将根结点出队
        visit(p); // 访问出队结点
        if(p->lchild != NULL){
            EnQueue(Q, p->lchild); // 若有左子树，则将左子树入队 
        }
        if(p->rchild != NULL){
            EnQueue(Q, p->rchild); // 若有右子树，则将右子树入队
        }
    }
}
// 1016 review: 75/100
void LevelOrder(BiTree T){
    InitQueue(&Q);
    BiTree *p = T;
    EnQueue(Q, p);
    while(!IsEmpty(Q)){
        if(p){
            DeQueue(Q, p);
            visit(p);
            if(p->lchild!=NULL){
                EnQueue(Q, p->lchild);
            }
            if(p->rchild!=NULL){
                EnQueue(Q, p->rchild);
            }
        }
    }
}
// 1017 review: 100/100
void LevelOrder(BiTree T){
    BiTree *p = T;
    Queue Q;
    InitQueue(&Q);
    EnQueue(&Q, &p);
    while(IsEmpty(Q) || p){
        if(p){
            DeQueue(&Q, &p);
            visit(p);
            if(p->lchild!=NULL){
                EnQueue(&Q, p->lchild);
            }
            if(p->rchild!=NULL){
                EnQueue(&Q, p->rchild);
            }
        }
    }
}