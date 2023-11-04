// 定义图的数据结构
typedef struct {
    int vexnum;       // 顶点数
    int edgnum;       // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph;

// Floyd-Warshall算法
void floyd(Graph G, int path[][MAX], int D[][MAX]) {
    int i, j, k;

    // 初始化
    for (i = 0; i < G.vexnum; i++) {
        for (j = 0; j < G.vexnum; j++) {
            D[i][j] = G.matrix[i][j]; // D[i][j]表示顶点i到顶点j的距离
            path[i][j] = j; // path[i][j]表示顶点i到顶点j的最短路径上，顶点i后面的那个顶点
        }
    }

    // 计算最短路径
    for (k = 0; k < G.vexnum; k++) {
        for (i = 0; i < G.vexnum; i++) {
            for (j = 0; j < G.vexnum; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) { // 如果经过顶点k路径比原两点间路径更短，则更新D[i][j]
                    D[i][j] = D[i][k] + D[k][j];
                    path[i][j] = path[i][k]; // 路径设置经过下标为k的顶点
                }
            }
        }
    }
}
