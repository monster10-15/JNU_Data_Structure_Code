void DFS(Graph G, int v){// 从v出发,先标记第一个点
    visit(v);
    visited[v] = 1;
    for(w=FirstAdjVex(G, v); w>=0; w=Adj(G,v,w)){ // 找新点点 
        if(visited[v]==0){ //如果有新点点
            DFS[G,w];
        }
    }
}
// TODO: 1026 review: 70/100
void DFS(Graph G, int v){
    visit(v);
    visited[v] = 1;
    for(int w=FirstAdjvex(G, v); w>0; i++){
        if(visited[w]==0){
            DFS(G, w);
        }
    }
}
// TODO: 1027 review: 90/100
void DFS(Graph G, int v){
    visit(v);
    visited[v] = 1;
    for(int w=FirstAdjvex(G, v); w>0; w--){
        if(visited[w]==1){
            DFS(G, w);
        }
    }
}