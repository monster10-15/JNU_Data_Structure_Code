// 代码填空题
// TODO: 先序的非递归算法
// 算法思想: 1、沿着根的左孩子依次访问，然后入栈2、栈顶元素出栈（若右孩子为空）3、否则执行1
// TODO: 访问入栈向左一直走，出栈右子树
void PreOrder(BiTree T){
    InitStack(S), BiTree P=T;
    while(P || !IsEmpty(S)){
        if(P){
            visit(P);
            push(S,P);// 一路向左
            P=P->lchild;// 左孩子不空，一直向左走
        }
        else{
            pop(S,P);// 栈顶元素出栈
            P=P->rchild;// 右孩子不空，一直向右走
        }
    }
}
// 1015 review: 100/100
// 1016 review: 80/100
// 1017 review: 100/100
void PreOrder(BiTree T){
    BiTree *p=T;
    InitStack(S);
    while(p || !IsEmpty(S)){
        if(p){
            visit(p);
            push(S, p);
            p=p->lchild;
        }
        else{
            pop(S, p);
            p=p->rchild;
        }
    }
}
// 22-830-代码填空题（1）
// 先序的非递归算法
void PreOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
    BTNode *p;
    SqStack *st;
    InitStack(st);
    if (T != NULL)
    {
        Push(st, T);
        while (!StackEmpty(st))
        {
            Pop(st, &p);
            Visit(p->data);
            if (p->lchild != NULL)
                Push(st, p->lchild);
            if (p->rchild != NULL)
                Push(st, p->rchild);
        }
    }
}