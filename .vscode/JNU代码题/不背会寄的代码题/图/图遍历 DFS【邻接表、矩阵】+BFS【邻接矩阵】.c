//! 邻接矩阵的DFS
//! [2020]采用邻接表存储结构，判别无向图中任意给定的两个顶点之间是否有长度为k的简单路径
typedef struct Node{
    int vertex; // 顶点
    struct Node* next; // 下一个节点
}
typedef struct Graph{ 
    int verterxnum; // 顶点数
    Node** AdjList; // 邻接数组
}Graph;
int DFS(Graph* G, int Begin, int End, int k){
    // Step 1: 初始化访问标记数组以及路径长度
    static int* visited; // 访问标记数组
    int miles = 0;// 路径长度
    if(miles == 0){
        visited = (int*)malloc(G->numVertices * sizeof(int));
        for(int i = 0; i < G.vertexnum; i++){
            visited[i] = 0;
        }
    }
    // Step 2: 标记当前节点，miles++  
    visited[Begin] = 1;
    miles++;
    if(Begin == End && miles == k+1){
        return 1;
    }
    // Step 3: 检查一下当前节点还有没有分岔路【如果有继续走】
    else{
        Node temp=G.AdjList[Begin];
        while(temp != NULL){
            if(visited[temp] == 0){
                if(DFS(G, temp, End, miles)){
                    return 1;
                }
            }
            temp=temp->next;
        }
    }
    // Step 4: 回溯
    miles--;
    visited[Begin]=0;
    return 0;
}

//! [2022]采用邻接表存储结构，判别无向图是否连通
#define vertexnum 100 // 定义最大顶点数为100
// 定义邻接节点的数据结构
struct AdjNode {
    int vertex; // 顶点
    AdjNode* next; // 指向下一个邻接节点的指针
};
// 定义图的数据结构
struct Graph {
    AdjNode* adjList[vertexnum]; // 邻接表，数组中的每个元素都是一个链表的头节点
    int vertexnum; // 图中的顶点数
    int visited[vertexnum]; // 访问标记数组，如果某个顶点被访问过，相应的元素值为1，否则为0
};
// 深度优先搜索函数
void dfs(Graph* g, int v) {
    g->visited[v] = 1; // 标记顶点v已被访问
    AdjNode* p = g->adjList[v]; // 获取顶点v的邻接链表的头节点
    while (p != NULL) { // 遍历顶点v的所有邻接节点
        if (g->visited[p->vertex] == 0) { // 如果邻接节点未被访问过
            dfs(g, p->vertex); // 对邻接节点进行深度优先搜索
        }
        p = p->next; // 移动到下一个邻接节点
    }
}
// 判断图是否连通的函数
int isConnected(Graph* g) {
    for (int i = 0; i < g->vertexnum; i++) { // 初始化所有顶点为未访问状态
        g->visited[i] = 0;
    }
    dfs(g, 0); // 从顶点0开始进行深度优先搜索
    for (int i = 0; i < g->vertexnum; i++) { // 检查所有顶点是否都被访问过
        if (g->visited[i] == 0) { // 如果有未被访问过的顶点
            return 0; // 返回0，表示图不连通
        }
    }
    return 1; // 所有顶点都被访问过，返回1，表示图连通
}


//! 邻接矩阵版BFS
// step 1: 初始化
Queue Q;
InitQueue(Q);
EdgeType arcs[Maxsize][Maxsize];
int visited[G.vexnum];
for(i=0;i<G.vexnum;i++){
    visited[i]=0;
}
// step 2: BFS
void BFS(Graph G, int v){
    visit(v);// 为第一个点点 提供 访问 入队 标记 一条龙服务
    EnQueue(Q, v);
    visited[v] = 1;
    while(!IsEmpty(Q)){ // 为 第一个点点 提供 找呀找呀找朋友 服务 
        DeQueue(Q,v);
        for(w=FirstAdjVex(G, v); w>0; w=NextAdjVex(G, v, w)){
            if(visited[w]==0){
                visit(w);
                visited[w]=1;
                EnQueue(Q, w);
            }
        }
    }
}
// step 3: 为点点找朋友
void FirstAdjVex(G, v){
    for (int i=0; i<G.vexnum; i++){
        if(G.arcs[v][i]==1){ // 如果点点有朋友就把朋友的坐标告诉BFS(●'◡'●)
            return i;
        }
    }
}
// step 4: 为点点找第二个朋友
void NextAdjVex(G, v, w){
    for(int i=w+1; i<G.vexnum; i++){
        if(G.arcs[v][i]==1){
            return i;
        }
    }
}