//! 邻接矩阵版
// 定义图的数据结构
typedef struct {
    int vexnum;       // 顶点数
    int edgnum;       // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph;
// Dijkstra算法
void dijkstra(Graph G, int v0, int prev[], int dist[]) {
    int flag[MAX]; // 【标记数组】flag[i]=1表示已访问
    int k;
    // step1: 初始化flag && prev && dist
    for (i = 0; i < G.vexnum; i++) {
        flag[i] = 0;              // 顶点i还没被访问过
        prev[i] = -1;              // 顶点i无前驱顶点
        dist[i] = G.matrix[v0][i]; // "顶点v0"到"顶点i"的路径长度
    }
    // step2: 对"源点v0"自身进行初始化
    flag[v0] = 1;
    dist[v0] = 0;
    // step3: 对剩下的n-1个顶点遍历  旨在找到[v0->k]+[k->j] < [v0->j] 实现曲线救国
    for (int i = 1; i < G.vexnum; i++) {
        int min = INF;
        // !选出当前权重和最短的点【并且是没有标记访问过的】[即 找新捷径]
        for (int j = 0; j < G.vexnum; j++) {
            if (flag[j]==0 && dist[j] < min) {
                min = dist[j]; // 这里的j 只是遍历的，别搞错了
                k = j; //! min: [v0->k] 
            }
        }
        flag[k] = 1; // 标记"顶点k"已读 [或者说预备加入最短路径那意思]
        // step4: 找捷径 + 确认捷径是否可取
        for (int j = 0; j < G.vexnum; j++) {
            int newdist = min + G.matrix[k][j];
            if (flag[j] == 0 && (newdist < dist[j]) ) {// !如果[v0->k]+[k->j] < [v0->j] 曲线救国成功 
                dist[j] = newdist;
                prev[j] = k;
            }
        }
    }
}

//! 邻接表版
// 图的结构体
typedef struct Graph {
    int V;                      // 顶点数
    Edge** adj;                 // 邻接表
} Graph;
// Dijkstra算法求解最短路径
void Dijkstra(Graph* graph, int src, int* dist) {
    int V = graph->V;
    bool* visited = (bool*)malloc(V * sizeof(bool));
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;
    
    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        int minDist = INF;

        // 选择距离最小的顶点
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        visited[u] = true;
        // 更新邻接顶点的距离
        Edge* edge = graph->adj[u];
        while (edge != NULL) {
            int v = edge->dest;
            int weight = edge->weight;
            if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            edge = edge->next;
        }
    }

    free(visited);
}
