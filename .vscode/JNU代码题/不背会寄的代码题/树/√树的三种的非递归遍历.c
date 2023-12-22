#define MAXTSIZE 100
typedef struct BiTNode {
    int data;                           //结点数据域
    struct BiTNode *lchild, *rchild;    //左右孩子指针
} BiTNode, *BiTree;

typedef struct Stack {
    BiTree st[MAXTSIZE];
    int top = -1;
};
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
// TODO: 中序的非递归算法
// 算法思想: 1、沿着根的左孩子依次入栈直到左孩子为空，2、栈顶元素出栈并访问（若右孩子为空，则继续执行）3、否则执行1
// TODO: 入栈向左一直走，出栈访问右子树
void InOrder(BiTree T){
    Stack S;
    InitStack(&S);
    BiTree p = T;
    while(p || !StackEmpty(S)){
        if(p){
            Push(&S,p);
            p = p->lchild;
        }
        else{
            Pop(&S,&p);
            visit(p);
            p = p->rchild;
        }
    }
}
// TODO: 后序的非递归算法
// 算法思想: ①、左孩子一一入栈 ②、读栈顶top,若top的右孩子不空且未被访问就将右子树执行①
// ③、栈顶元素出栈 ④、标记置空
// TODO: 入栈向左一直走，登顶判定右转左，出栈访问，标记，重置
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
                p = p->lchild;// 转左
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
