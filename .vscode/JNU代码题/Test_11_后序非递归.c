// 算法思想: ①、左孩子一一入栈 ②、读栈顶top,若top的右孩子不空且未被访问就将右子树执行①
// ③、栈顶元素出栈 ④、标记置空
// TODO: 入栈向左一直走，登顶判定右子树，出栈访问，标记，重置
void PostOrder(BiTree T){
    Stack S;
    InitStack(&S);
    BiTree p = T;
    BiTree r = NULL;
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
                p = p->lchild;
            }
            else{// 若右子树为空或被访问过则出栈
                Pop(&S,p);
                visit(p);
                r = p;// r标记最近访问过的结点
                p = NULL;
            }
        }
    }
}
// 1016 review: 60/100
// 1017 review: 60/100
// 1018 review: 60/100 
// 1020 review: 50/100
// 1021 review: 100/100
void PostOrder(BiTree T){
    BiTree *p=T, *r=null;
    InitStack (S);
    push(T, S);
    while(p || IsEmpty(S)) {
        if(p->lchild){
            p=p->lchild;
            push(p,S);
        }
        BiTree *top=GetTop(S);
        else if(top->rchild && top->rchild!=r){
            p=top->rchild;
            if(p->lchild){
                p=p->lchild;
            }
        }
        else{
            pop(top,S);
            visit(top);
            r=p;
            p=null;
        }
    }
}