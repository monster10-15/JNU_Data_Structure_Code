void BFS(Graph G, Status(*visit)(int v)){
    visit(v);
    EnQueue(Q, v);
    visted[v] = true;
    while(!IsEmpty(Queue)){
        DeQueue(Q,v);
        for(w=FirstAdj(G,v); w>=0; w=NextAdj(G,v,w)){
            if(visited[w]==0){
                visit(w);
                EnQueue(Q,v);
                visited[w]=1;
            }
        }
    }
}

void Dijkstra(Graph &G, int v0, int prev[], int dist[]){
    int flag[MAX];
    int k;
    // step1 初始化prev、dist、flag
    for(int i=0; i<G.vexnum; i++){
        flag[i] = 0;
        prev[i] = -1;
        dist[i] = G.martrix[v0][i];
    }
    // step2 对源点自身初始化
    flag[v0]=1;
    prev[v0]=0;
    // step3 对剩下的n-1个顶点遍历，势必找到[v0-k] + [k-j] < [v0-j]实现曲线救国
    for( int i = 1; i < G.vexnum; i++){
        int min = INF;
        for(int j = 1; j < G.vexnum; j++){
            if(flag[j]==0 && dist[j]<min){
                min = dist[j];
                k=j;
            }
        }
        flag[k]=1;
        for(int j = 0; j < G.vexnum; j++){
            if(flag[j]==0 && G.vexnum[k][j]+min<dist[j]){
                dist[j]=G.vexnum[k][j]+min;
                prev[j]=k;
            }
        }
    }
}