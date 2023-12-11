//! 广度优先遍历
// 算法思想: 初始化访问标记数组及队列
// BFS: 1、找到与一个顶点相邻的顶点2、标记哪些顶点被访问过3、需要一个辅助队列4、图的基本操作
// (1) FirstAdjVex (G, v)：求图G中頂点的第一个邻接点，若存在，则返回顶点号，若v不存在邻接点或图中不存在x，則返回-1
// (2) NextAdjvex (G, v, w)：除v外的，下一个邻接点W，若存在，则返回顶点号，若v不存在邻接点或图中不存在x，則返回-1
for(i=0;i<G.vexnum;i++){
    visited[v]=0;// 数组
    InitQueue(Q);// 队列
    int adj;// 无权值 0或1
    char *infol// 有权值
    int Vexnum, arcnum;
    EdgeType arcs[maxsize][maxsize]
}// 使用邻接矩阵存储
int FirstAdjvex(MGraph G, int v){
    int i;
    for(i=0; i<G.vexnum; i++){
        if(G.arcs[v][i].adj==1) return i;
        else return -1;
    }
}
int NextAdjvex(MGraph G, int v, int w){
    int i;
    for(i=w+1;i<G.vexnum;i++){
        if(G.arcs[v][i].adj==1) return i;
        else return -1;
    }
}
void BFS(Graph G, int v){
    visit(v);// 访问初始数组
    visited[v]=1;
    EnQueue(Q,v);
    while(!IsEmpty(Q)){
        DeQueue(Q,v);
        for(w=FirstAdjVex(G,v);w>=0;w=NextAdj(G,v,w)){
            if(visited[w]==0){//检测V的邻接点
                visit(w);// 访问顶点W
                visited[w]=1;// 对W做已访问标记
                EnQueue(Q,w);// 顶点W入队
            }
        }
    }
}
//! BFS newbing version
// 初始化访问标记数组 // 初始化队列Q // 邻接图
int visited[G.vexnum];
for(int i=0; i<G.vexnum; i++){
    visited[i] = 0;
}
Queue Q;
InitQueue(Q);
EdgeType arcs[maxsize][maxsize];
void BFS(Graph G, int v){
    visit(v); // 访问初始顶点
    visited[v] = 1; // 对v做已访问标记
    EnQueue(Q, v); // 顶点v入队
    while(!IsEmpty(Q)){
        DeQueue(Q, v);
        for(int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)){
            if(visited[w] == 0){ // 检测v的邻接点
                visit(w); // 访问顶点w
                visited[w] = 1; // 对w做已访问标记
                EnQueue(Q, w); // 顶点w入队
            }
        }
    }
}
int FirstAdjVex(MGraph G, int v){
    for(int i = 0; i < G.vexnum; i++){
        if(G.arcs[v][i].adj == 1) return i;
    }
    return -1;
}
int NextAdjVex(MGraph G, int v, int w){
    for(int i = w + 1; i < G.vexnum; i++){
        if(G.arcs[v][i].adj == 1) return i;
    }
    return -1;
}

//! 1025 review: 50/100
//1.初始化队列 && 标记访问数组并初始化为0 && 邻接图
Queue Q;
InitQueue(Q);
int visited[G.vexnum];
for(int i = 0; i < G.vexnum;i++){
    visited[i] = 0;
}
//2.BFS
void BFS(Graph &G, int v){ 
    visit(v);
    visited[v]=1; // 访问初始结点后马上标记为1且入队
    EnQueue(Q, v);
    while(!IsEmpty(Q)){// 如果Q不空的话就找个与此点相邻的另一个点
    // FirstAdj: 找图G中顶点的第一个邻接点 （往复）NextAdjvex: 找第二个邻接点
        for(int w = FirstAdjVex(G, v); w >=0; w = NextAdjVex(G, v, w)){
            if(visited[w]==0){ // 找到了没访问过的新点点
                visit(w); // first就立马访问
                visited[w] = 1; // and then做标记
                EnQueue(Q, w); // and then入队
            }
        }
    }
}
void FirstAdjVex(G, v){
    for(int i=0; i<G.vexnum; i++){
        if(G.arcs[v][i].adj==1){ // 如果点点有朋友就把朋友的坐标告诉BFS(●'◡'●)
            return i;
        }
    }
    return -1; // 没有就算了
}
void NextAdjVex(G, v, w){
    for(int i=w+1; i<G.vexnum;i++){
        if(G.arcs[v][i].adj==1){ // 如果确实有新点点就...
            return i;
        }
        return -1; // 没有就算了
    }
}
//! 1026 review: 60/100
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
    visit(v);// 为第一个点点提供 访问 入队 标记 一条龙服务
    EnQueue(Q, v);
    visited[v] = 1;
    while(!IsEmpty(Q)){ // 为 第一个点点 提供 找呀找呀找朋友 服务 
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
//! 1027 review: 100/100
Queue Q;
Init Queue(Q);
EdgeType arcs[MaxSize][MaxSize];
int visited[G.vexnum];
for(i=0; i>MaxSize;i++){
    visited[i] =0;
}
void BFS(Graph G, int v){
    visit(v);
    visited[v]=1;
    EnQueue(Q, v);
    while(!Q){
        for(int w=firstAdjvex(G, v);w>0;w=NextAdjvex(G,v,W)){
            if(visited[w] == 0){
                visit(w);
                visited[w] = 1;
                EnQueue(Q, w);
            }
        }
    }
}
void FirstAdjvex(Graph G, int v){
    for(int i=0; i<G.vexnum;i++){
        if(arcs[v][i]==1){
            return i;
        }
    }
}
void NextAdjvex(Graph G, int v, int w){
    for(int i=w+1; i<G.vexnum;i++){
        if(arcs[v][i]==1){
            return i;
        }
    }
}