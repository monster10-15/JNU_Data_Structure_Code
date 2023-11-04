'''假设在n个城市之间的公路网中:已知直达城市之间的乘车费用,各城市之间均存在通路。
从Vo城市开始乘车经过若干个城市到S城市，有多条路线可以选择。
设计算法: 选择一条最节省费用的路线。要求:
(1) 选择一种合适的数据结构，描述 n 个城市之间的公路网;(4 分)
(2) 用伪代码描述求从 V,城市到 S 城市最节省费用的路线。(8 分)'''
// 定义图的数据结构
typedef struct {
    int vexnum;       // 顶点数
    int edgnum;       // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph;

// Dijkstra算法
void dijkstra(Graph G, int v0, int prev[], int dist[]) {
    int i,j,k;
    int min;
    int tmp;
    int flag[MAX]; // 【标记数组】flag[i]=1表示"顶点v0"到"顶点i"的最短路径已成功获取。
    // 初始化
    for (i = 0; i < G.vexnum; i++) {
        flag[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = 0;              // 顶点i的前驱顶点为0。
        dist[i] = G.matrix[v0][i]; // 顶点i的最短路径为"顶点v0"到"顶点i"的权。
    }
    // 对"顶点v0"自身进行初始化
    flag[v0] = 1;
    dist[v0] = 0;

    // 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
    for (i = 1; i < G.vexnum; i++) {
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
        min = INF;
        for (j = 0; j < G.vexnum; j++) {
            if (flag[j]==0 && dist[j]<min) {
                min = dist[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;

        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j = 0; j < G.vexnum; j++) {
            temp = (G.matrix[k][j]==INF ? INF : (min + G.matrix[k][j])); // 防止溢出
            if (flag[j] == 0 && (temp  < dist[j]) ) {
                dist[j] = temp;
                prev[j] = k;
            }
        }
    }
}
