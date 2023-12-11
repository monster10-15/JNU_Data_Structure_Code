#include <stdio.h>
#define MAX 100

// 定义顶点类型
typedef char VertexType;

// 边表节点
typedef struct ArcNode {
    int adjvex; // 该弧所指向的顶点的位置
    struct ArcNode *nextarc; // 指向下一条弧的指针
} ArcNode;

// 顶点表节点
typedef struct VNode {
    VertexType data; // 顶点信息
    ArcNode *firstarc; // 指向第一条依附该顶点的弧的指针
} VNode, AdjList[MAX];

// 邻接表
typedef struct {
    AdjList vertices; // 邻接表
    int vexnum, arcnum; // 图的当前顶点数和弧数
} ALGraph;

// 邻接矩阵
typedef struct {
    int vexnum; // 顶点数
    int edgnum; // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
} MGraph;
