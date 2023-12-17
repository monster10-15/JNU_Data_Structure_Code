Typedef enum PointerTag{Link, Thread};
// 二叉树的二叉线索存储表示
typedef struct BiThrNode{
    TelemTye data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag, RTag;
}BiThrNode, *BiThrTree;

// 孩子兄弟链表的存储结构
typedef struct CSNode{
    char data;
    struct CSNode *firstChild, *nextsibling;
}CSNode, CSTree; 