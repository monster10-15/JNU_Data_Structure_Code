//TODO: 编写一个算法根据用户输入的偶对（以输入 0 表示结束）建立其有向图的邻接表（设有 n 个顶点）
// 定义链表节点结构
typedef struct LinkNode{
    int v; // 顶点
    LinkNode *next; // 指向下一个节点的指针
};

// 定义链表结构
typedef struct ListLink{
    LinkNode *head; // 链表的头节点
    LinkNode *tail; // 链表的尾节点
};

// 建立有向图的邻接表
void solve(ListLink L[], int n){
    // 初始化邻接表
    for(int i = 1; i <= n; i++){
        L[i].head = (LinkNode *)malloc(sizeof(LinkNode)); // 分配头节点
        L[i].head->next = NULL; // 头节点的next指针指向NULL
        L[i].tail = L[i].head; // 尾节点指向头节点
    }
    
    int v, u;
    // 读取用户输入的偶对
    while(scanf("%d", &u)){
        if(u!=0) scanf("%d", &v); // 如果输入的不是0，那么读取第二个顶点
        else break; // 如果输入的是0，那么结束输入

        // 创建一个新的节点
        LinkNode *p = (LinkNode *)malloc(sizeof(LinkNode));
        p->v = v; // 设置节点的顶点
        p->next = NULL; // 设置节点的next指针指向NULL
        // 将新节点添加到链表的尾部
        L[u].tail->next = p;
        L[u].tail = p;
    }
}
