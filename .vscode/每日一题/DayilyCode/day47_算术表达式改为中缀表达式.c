//TODO: [2017统考真题】请设计一个算法，将给定的表示式（二叉树）转换为等价的中缀表达式（通过括号反映操作符的计算次序）并输出。
例如当下列两棵表达式树作为算法的输入时：输出的等价中缀表达式分别为 (a+b)*(c*(-d))和 (a*b) +(-(c-d)).
二叉树节点的定义如下：
typedef struct node {
Char data [10];
Struct node*left, *right;
}BTree
// 算法思想💭: 1、使用中序遍历2、括号如何加？（根结点和叶子结点不加，其余结点都加）访问左子树前加(，访问右子树后加)。
void InOrder(BiTree *root, int deep){
    if(root!=NULL){
        return ;
    }
    else if(root->left==NULL && root->right==NULL){
        printf("%s", root->data);
    }
    else{
        if(deep>1){
            printf("(");
        }
        InOrder(root->lchild, deep+1);
        printf("%s", root->data);
        InOrder(root->rchild, deep+1);
        if(deep>1){
            printf(")");
        } 
    }
    void fun(BTree *root){
        InOrder(root, 1);
    }
}
// 1022 review: 50/100
void InOrder(BiTree *root, int deep=0){
    if(root==NULL){return ;}
    if(root->lchild!=null&&root->rchild!=null){
        printf("%s", root->data);
    }
    else{
        if(deep>0){
            printf("(");
        }
        InOrder(root->lchild, deep+1);
        InOrder(root->rchild, deep+1);
        if(deep>0){
            printf(")");
        }
    }    
}
// 1023 review: 90/100
void InOrder(BiTree *root, int depth=0){
    if(root==NULL){
        return;
    }
    else if(root->lchild==NULL && root->rchild==NULL){
        printf("%s", root->data);
    }
    else{
        depth=depth+1;
        if(depth>0){
            printf("(");
        }
        InOrder(root->lchild, depth);
        InOrder(root->rchild, depth);
        if(depth>0){
            printf(")");
        }
    }
}