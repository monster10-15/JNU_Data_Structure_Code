// TODO: 邻接表的存储结构定义
"
顶点表结点: 顶点域data|边表头结点firstarc
边表结点: 邻接点域adjvex|指针域nextarc
"
typedef struct VNode{//顶点表结点
    VertexType data;//顶点信息
    ArcNode *firstarc;//指向第一条依附该结点的弧的指针
}VNode;//顶点表结点
typedef struct ArcNode{//边表结点
    int adjvex;// 该弧指向的顶点的位置
    struct ArcNode* nextarc;//指向下一条边弧的指针
}ArcNode;
typedef struct AdjList{//邻接表
    AdjList Vertiles;//邻接表
    int Vexnum arcnum;//图的顶点数和弧数
}AdjList;

// TODO: 1026 review: 0/100
typedef struct VNode{
    int data;
    ArcNode *firstarc;
}VNode;
typedef struct ArcNode{
    int adjvex;
    struct ArcNode* nextarc;
}ArcNode;
typedef struct AdjList{
    AdjList Vertiles;
    int Vexnum arcnum;
}AdjList;
// TODO: 1027 review: 60/100
Typedef struct VNode{
    VertexType data;
    arcnode *first;
}VNode;
Typedef struct ArcNode{
    int adjvex;
    struct arcnode *next;
}
Typedef AdjList{
    AdjList vertiles;// 邻接表
    int vexnum, arcnum;
}AdjList;