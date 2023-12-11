// TODO: 中序的非递归算法
// 递归算法
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
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
// 1015 review: 0/100
// 1016 review: 50/100
// 1017 review: 100/100
// 代码填空题
下面是一个采用二叉链表存储结构, 中序遍历线索二叉树 T 的算法。 Visit 是对结点操作的应用函数
/*二叉树的二叉线索存储表示*/
Typedef enum PointerTag{Link, Thread};  // 定义指针标志，Link表示指向左右孩子的指针，Thread表示指向前驱或后继的线索
typedef struct BiThrNode { 
    TelemType data;  // 结点的数据域
    struct BiThrNode *lchild, *rchild;  // 左右孩子指针
    PointerTag LTag, RTag;  // 左右孩子指针标志
} BiThrNode, *BiThrTree;  // 定义二叉线索树的结点类型和指针类型

Status InOrderTraverse_Thr(BiThrTree T, Status(* Visit)(TelemType e)){
    BiThrNode *p;  // 定义指针p用于遍历二叉线索树
    p=T->lchild;  // p指向根结点的左孩子

    while(p!=T){  // 空树或遍历结束时 p==T
        while(p->LTag==Link) p=p->lchild;  // 找到最左下结点
        if(!Visit(p->data)) return ERROR;  // 对结点进行操作，如果操作失败则返回错误

        while (p->RTag==Thread && p->rchild!=T){  // 当右孩子是线索且不是指向头结点时
            Visit(p->data);  // 对结点进行操作
            p=p->rchild;  // 移动到右孩子
        }
        p=p->lchild;  // 移动到下一个结点
    }
    return OK;  // 遍历结束，返回成功
}