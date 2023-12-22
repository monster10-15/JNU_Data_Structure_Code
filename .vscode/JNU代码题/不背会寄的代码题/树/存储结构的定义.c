// 二叉树的二叉线索存储表示
typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int LTag, RTag;
}ThreadNode, *ThreadTree;

// 孩子兄弟链表的存储结构
typedef struct CSNode{
    char data;
    struct CSNode *firstChild, *nextsibling;
}CSNode, CSTree; 