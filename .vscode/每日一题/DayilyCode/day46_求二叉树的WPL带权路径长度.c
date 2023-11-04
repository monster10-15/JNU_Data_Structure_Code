// TODO: 【2014统考真题】二叉树的带权路径长度(WPL） 是二叉树中所有叶结点的带权路径之和。
// TODO:  给定一棵二叉树T，采用二叉链表存储，结点结构为 lchild | weight | rchild
// TODO:  其中叶结点的weight域保存该结点的非负权值。设root为指向T的根节点的指针，请设计求T的WPL的算法
// 算法思想: 将所有结点的WPL值累加即可;
int WPL = 0;
int WPL_PreOrder(BiTree root, int deep=0){
    if(root->lchild==null && root->rchild==null){// 若为叶子结点，则累计WPL
        WPL+=deep*root->weight;
    }
    if(root->lchild!=null){
        WPL_PreOrder(root->lchild, deep+1);// 若左子树不空，则左子树递归
    }
    if(root->rchild!=null){
        WPL_PreOrder(root->rchild, deep+1);// 若右子树不空，则右子树递归
    }
    return WPL;
}
// 1022 review:60/100
int WPL = 0;
int WPL_PreOrder(BiTree root, int deep=0){
    if(root->lchild==null&&root->rchild==null){
        WPL+=root->weight*deep;
    }
    else{
        WPL_PreOrder(root->lchild, deep+1);
        WPL_PreOrder(root->rchild, deep+1);
    }
}
// 1023 review: 100/100
int WPL_PreOrder(BiTree root, int deep=0){
    int WPL = 0;
    if(root == null){
        return 0;
    }
    if(root->lchild==null && root->rchild==null){
        WPL += root->weight * deep;
    }
    if(root->lchild){
        WPL += WPL_PreOrder(root->lchild, deep+1);
    }
    if(root->rchild){
        WPL += WPL_PreOrder(root->rchild, deep+1);
    }
    return WPL;
}