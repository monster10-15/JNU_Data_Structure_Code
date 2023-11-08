// 定义图的数据结构
typedef struct {
    int vexnum;       // 顶点数
    int edgnum;       // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph;

// Floyd-Warshall算法
void floyd(Graph G, int path[][MAX], int dist[][MAX]) {
    int i, j, k;
    // step1: 初始化dist[][] && path[][]
    for (i = 0; i < G.vexnum; i++) {
        for (j = 0; j < G.vexnum; j++) {
            dist[i][j] = G.matrix[i][j]; // dist[i][j]表示顶点i到顶点j的距离
            path[i][j] = j; // 存储从顶点i到顶点j的最短路径经过的中间节点;初始化时假设最短路径是直接到达顶点 j
        }
    }
    // step2: 曲线救国: 对于每对节点 i和j，以及每个中间节点k，检查[i->k]+[k->j] 是否小于 [i->j]
    for (k = 0; k < G.vexnum; k++) {
        for (i = 0; i < G.vexnum; i++) {
            for (j = 0; j < G.vexnum; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) { // 如果[i->k]+[k->j] < [i->j]，则更新dist[i][j]
                    dist[i][j] = distD[i][k] + dist[k][j];
                    path[i][j] = path[i][k]; // 表示最短路径 经过了中间节点 k
                }
            }
        }
    }
}

// review[1109]: 100/100
void floyd (Graph G, int path[][MAX], int dist[][MAX]){
    // step 1: 初始化dist && path
    for(int i = 0; i < vexnum; i++){
        for(int j = 0; j < vexnum; j++){
            path[i][j] = j;
            dist[i][j] = G.martrix[i][j];
        }
    }
    // step 2: 曲线救国任务: 找[i->k]+[k->j] < [i->j]
    for(int k = 0; k < vexnum; k++){
        for(int i = 0; i < vexnum; i++){
            for(int j = 0; j < vexnum; j++){
                if(dist[k][j]+dist[i][k] < dist[i][j]){
                    dist[i][j] = dist[k][j]+dist[i][k];
                    path[i][j] = k;
                }
            }
        }
    }

}
