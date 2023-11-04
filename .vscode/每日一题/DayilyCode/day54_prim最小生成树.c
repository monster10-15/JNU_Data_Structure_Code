// TODO: Prim算法求解最小生成树
// TODO: 算法思想: 1、 TODO: 初始化权值lowcost【v0到其他顶点的初始距离】2、 TODO: 更新lowcost【v0到其他结点的最短距离】3、 TODO: 【找k到其他结点的最短距离】
void Prim(Graph &G, int v0 = 0, int *adjvex, int *lowcost){
    // adjvex[vexnum]; //保存相关顶点下标
    // lowcost[vexnum]; //保存相关顶点间的权值
    //TODO: Step1: 初始化权值lowcost【v0到其他顶点的初始距离】
    for (i=1; i<G.vexnum; i++){ //循环除了下标为0外的全部顶点
        lowcost[i] = G.arcs[v0][i]; //将 与v0顶点有边 的点的权值 存入数组
        adjvex[i] = 0; // 初始化统一设为0 
    }
    // TODO: Step2: 更新lowcost【v0到其他结点的最短距离】
    for (i=1; i<G.vexnum; i++){
        int min = INFINITY;
        int k = 0;
        for (j = 1; j<G.vexnum; j++){  //循环全部顶点
            if(lowcost[j]!=0 && lowcost[j]<min){
                min = lowcost[j];
                k = j;   // 将当前距离最小值的下标存入k，k存储下一步的结点的标记
            }
        } //得到min{生成树的顶点的集合到其他各个顶点的最短距离}
        printf("顶点对:(%d, %d), lowcost:%d \n",adjvex[k], k, lowcost[k]); //打印当前顶点边中权值最小边及其权值
        lowcost[k] = 0; //将当前顶点的权值设置为0，表示该顶点已经完成任务
        // TODO: Step3: 继续更新lowcost【k到其他结点的最短距离】
        for (j = 1; j < G.vexnum; j++){   
            if (G.arcs[k][j]!= 0 && G.arcs[k][j] < lowcost[j]){
                lowcost[j] = G.arcs[k][j];
                adjvex[j] = k; // 将下标为k的顶点存入adjvex，也就是存储下一步的最短边的起点【继续找间接的间接距离】
            }
        } //得到目前已经是生成树的顶点的集合到其他各个顶点的最短距离
    }
}
// 1101 review: 60/100
void Prim(Graph &G, int v0=0 , int *NodeCP, int *lowcost){
    //TODO: Step1: 初始化lowcost【v0到其他顶点的初始距离】
    for(int i = 0; i < G.vexnum; i++){
        NodeCP[i] = -1;
        lowcost[i] = G.arcs[v0][i];
    }
    //TODO: Step2: 更新lowcost【v0到其他结点的最短距离】
    for(int i = 1; i < G.vexnum; i++){
        int min = INF;
        int k = -1;
        for(int j = 1; j < G.vexnum; j++){
            if(lowcost[j]<min && lowcost[j]!=0){
                min = lowcost[j];
                k = j;
            }
        }
        printf("(%d, %d) lowcost: %d", NodeCP[k], k, lowcost[k]);
        lowcost[k] = 0; // K's work DONE
        // TODO: Step3: 继续更新lowcost【k到其他结点的最短距离】
        for(int j = 1; j < G.vexnum; j++){
            if(G.arcs[k][j] < lowcost[j] && G.arcs[k][j]!=0){
                lowcost[j] = G.arcs[k][j];
                NodeCP[j] = k;
            }
        }
    }
}
