void DFS(Graph G, int v){// 从v出发,先标记第一个点
    visit(v);
    visited[v] = 1;
    for(w=FirstAdjVex(G, v); w>=0; w=NextAdj(G,v,w)){ // 找新点点 
        if(visited[v]==0){ //如果有新点点
            DFS[G,w];
        }
    }
}
// TODO: 1026 review: 70/100
// TODO: 1027 review: 90/100