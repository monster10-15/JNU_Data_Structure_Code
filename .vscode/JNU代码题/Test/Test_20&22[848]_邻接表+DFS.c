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
    if(startVertex == endVertex && pathLength == k+1){ // 如果当前顶点就是目标顶点 且 路径长度为k
        return 1;
    }

    else{ // 如果当前顶点和目标顶点不一样或者路径长度不等于k那么继续遍历邻接表 
        Node* temp = graph->adjLists[startVertex]; // 【看看当前节点还有没有链接别的节点】
        while(temp){// 【如果还有分岔路口就往前走】
            if(visited[temp->vertex] == 0){ // 如果邻接顶点未被访问【这条路还没被人走过】
                if(DFS(graph, temp->vertex, endVertex, k)){ // 递归搜索邻接顶点【递归往前走】
                    return 1;
                }
            }
            temp = temp->next;
        }
    }

    // 如果都不符合要求 就回溯【吃回头草】
    visited[startVertex] = 0; // 标记起始顶点为未访问【从头来过】
    pathLength--; // 减少路径长度【抹去痕迹】
    return 0;
}

//! 1107 review: 60/100
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

//! [2022]采用邻接表存储结构，编写一个算法，判别无向图是否连通
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
int visited[MAX_VERTICES]; // 访问标记数组

// 邻接表的节点
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// 图的结构
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX_VERTICES];
} Graph;

// DFS算法
void DFS(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];    // 顶点vertex的邻接表
    Node* temp = adjList;    // temp指向这一条邻接表的表头
    visited[vertex] = 1; 
    // printf("Visited %d \n", vertex);
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

// 判断图是否连通
int isConnected(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }
    DFS(graph, 0); // 从顶点0开始DFS
    for (int i = 0; i < graph->numVertices; i++) {
        if (visited[i] == 0) {
            return 0; // 如果有顶点未被访问，则返回0
        }
    }
    return 1; // 如果所有顶点都被访问，则返回1
}

