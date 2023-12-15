void BFS(Graph G, Status(*visit)(int v)){
    visit(v);
    EnQueue(Q, v);
    visted[v] = true;

    while(!IsEmpty(Queue)){
        DeQueue(Q,v);
        
    }
}
