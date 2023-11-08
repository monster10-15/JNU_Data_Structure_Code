// 拓扑排序算法思想💭：
// 1、选择一个入度为0的顶点并输出，不唯一
// 2、从图中删除入度为0的顶点并输出
// 3、循环进行12，循环🔄结束时，若输出顶点数小于图中顶点数，则有回路。否则则输出序列为拓扑排序的序列
''' 
使用了一个栈来存储所有入度为0的顶点。然后，它在栈不为空的情况下，不断地从栈中弹出顶点，并将其输出。
同时，它会遍历该顶点的所有邻接顶点，并将邻接顶点的入度减1。如果邻接顶点的入度变为0，那么就将其压入栈中。
最后，如果输出的顶点数小于图中的顶点数，那么就返回false，表示图中存在环；否则，返回true，表示成功进行了拓扑排序。
'''
//! 邻接表版
bool TP(Graph G){
    InitStack(S);// 使用一个栈来存储所有入度为0的顶点
    for(int i = 0; i < G.vexnum; i++){
        if(G.indegree[i] == 0){// 入度为0
            push(S, i);
        } 
    }
    int count = 0;
    while(!IsEmpty(S)){ // 如栈不为空，不断地从栈中弹出顶点，并将其输出
        int i;
        pop(S, i);
        count++;
        printf("%d ", i);
        ArcNode* p;
        // 遍历该顶点的所有邻接顶点，并将邻接顶点的入度减1
        for(p = G.vertice[i].firstarc; p != NULL; p = p->nextarc){
            int v = p->adjvex;
            // 如果邻接顶点的入度变为0，那么就将其压入栈中。
            if(!(--G.indegree[v])){
                push(S, v);
            }
        }
    }
    // 如果输出的顶点数小于图中的顶点数，就表示图中存在环: 返回false
    if(count < G.vexnum) return false;
    else return true;// 否则，返回true，表示成功进行了拓扑排序
}
// ! 邻接矩阵版
#define MAX_VERTEX_NUM 100 // 最大顶点数
typedef struct {
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
    int vexnum, arcnum; // 顶点数和边数
    int indegree[MAX_VERTEX_NUM]; // 顶点的入度
} Graph;
bool TP(Graph G) {
    InitStack(S);
    int count = 0;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.indegree[i] == 0) {
            push(S, i);
        }
    }
    while (!IsEmpty(S)) {
        int v;
        pop(S, v);
        printf("%d ", v); // 添加空格来分隔输出的顶点
        count++;
        for (int w = 0; w < G.vexnum; w++) {
            if (G.arcs[v][w] == 1) {
                if (--G.indegree[w] == 0) {
                    push(S, w);
                }
            }
        }
    }
    if (count == G.vexnum) { // 如果 count 等于顶点数，表示成功进行了拓扑排序
        return true;
    } else {
        return false; // 否则，表示存在环
    }
}