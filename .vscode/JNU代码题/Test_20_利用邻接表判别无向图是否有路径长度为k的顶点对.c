采用邻接表存储结构，编写一个算法，判别无向图中任意给定的两个顶点之间是否存在条长度为 k 的简单路径。
// 定义邻接表节点
typedef struct Node{
    int vertex; // 顶点
    struct Node* next; // 下一个节点
}Node;

// 定义邻接表
typedef struct Graph{
    int numVertices; // 顶点数
    Node** adjLists; // 邻接表数组
}Graph;

// 定义深度优先搜索函数
int DFS(Graph* graph, int startVertex, int endVertex, int k){
    static int pathLength = 0; // 路径长度
    static int* visited; // 访问标记数组

    // 初始化访问标记数组
    if(pathLength == 0){
        visited = (int*)malloc(graph->numVertices * sizeof(int));
        for(int i = 0; i < graph->numVertices; i++){
            visited[i] = 0;
        }
    }

    visited[startVertex] = 1; // 标记起始顶点为已访问
    pathLength++; // 增加路径长度

    if(startVertex == endVertex && pathLength == k+1){ // 如果找到目标顶点并且路径长度为k
        return 1;
    }
    else{
        Node* temp = graph->adjLists[startVertex];
        while(temp){
            if(visited[temp->vertex] == 0){ // 如果邻接顶点未被访问
                if(DFS(graph, temp->vertex, endVertex, k)){ // 递归搜索邻接顶点
                    return 1;
                }
            }
            temp = temp->next;
        }
    }

    visited[startVertex] = 0; // 标记起始顶点为未访问
    pathLength--; // 减少路径长度
    return 0;
}
