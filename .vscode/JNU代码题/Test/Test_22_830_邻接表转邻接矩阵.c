#include <stdio.h>
#include <stdlib.h>
// !这个算法首先遍历邻接矩阵中的每一行（即每一个顶点），然后对于每一行，它从右到左遍历每一列（即每一个顶点的邻接顶点）。
// !如果在邻接矩阵中找到一个非零元素，那么就在邻接表中为这两个顶点添加一个边。
// !这个边的信息存储在一个ArcNode结构体中，包括邻接顶点的索引、边的权重以及指向下一个边的指针。
// !这个ArcNode结构体被插入到邻接表的相应位置。最后，这个算法将邻接矩阵的顶点数和边数复制到邻接表中。

// 定义边的结构体
typedef struct ArcNode {
    int adjvex;  // 邻接顶点的索引
    int weight;  // 边的权重
    struct ArcNode *nextarc;  // 指向下一个边的指针
} ArcNode;

// 定义顶点的结构体
typedef struct VNode {
    int data;  // 顶点的数据
    ArcNode *firstarc;  // 指向第一个边的指针
} VNode, AdjList[100];

// 定义图的结构体
typedef struct {
    AdjList vertices;  // 顶点数组
    int vexnum, arcnum;  // 顶点数和边数
} ALGraph;

// 创建邻接表的函数
void createALGraph(ALGraph *G, int adjMatrix[100][100], int n) {
    G->vexnum = n;  // 设置顶点数
    G->arcnum = 0;  // 初始化边数
    // 遍历每一个顶点
    for (int i = 0; i < n; i++) {
        G->vertices[i].data = i;  // 设置顶点的数据
        G->vertices[i].firstarc = NULL;  // 初始化第一个边的指针
        // 从右到左遍历每一个邻接顶点
        for (int j = n - 1; j >= 0; j--) {
            // 如果在邻接矩阵中找到一个非零元素
            if (adjMatrix[i][j] != 0) {
                // 为这两个顶点添加一个边
                ArcNode *arc = (ArcNode *)malloc(sizeof(ArcNode));
                arc->adjvex = j;  // 设置邻接顶点的索引
                arc->weight = adjMatrix[i][j];  // 设置边的权重
                arc->nextarc = G->vertices[i].firstarc;  // 设置指向下一个边的指针
                G->vertices[i].firstarc = arc;  // 将这个边插入到邻接表的相应位置
                G->arcnum++;  // 增加边数
            }
        }
    }
}

int main() {
    int adjMatrix[100][100];  // 邻接矩阵
    int n;  // 顶点数
    // 读取邻接矩阵和顶点数
    // ...
    ALGraph G;  // 图
    createALGraph(&G, adjMatrix, n);  // 创建邻接表
    return 0;
}