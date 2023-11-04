// 边的结构体
// typedef struct Edge {
//     int dest;   // 目标顶点
//     int weight; // 权重
// } Edge;

// 图的结构体
// typedef struct Graph {
//     int V;                      // 顶点数
//     Edge** adj;                 // 邻接表
// } Graph;

//  创建图
// Graph* createGraph(int V) {
//     Graph* graph = (Graph*)malloc(sizeof(Graph));
//     graph->V = V;
//     graph->adj = (Edge**)malloc(V * sizeof(Edge*));
//     for (int i = 0; i < V; i++) {
//         graph->adj[i] = NULL;
//     }
//     return graph;
// }

// 添加边
// void addEdge(Graph* graph, int src, int dest, int weight) {
//     Edge* newEdge = (Edge*)malloc(sizeof(Edge));
//     newEdge->dest = dest;
//     newEdge->weight = weight;
//     newEdge->next = graph->adj[src];
//     graph->adj[src] = newEdge;
// }

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
