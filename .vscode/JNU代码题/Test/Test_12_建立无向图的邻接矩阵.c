// 首先读取顶点数和边数，然后读取每个顶点的信息，并初始化邻接矩阵。
// 然后，对于每条边，读取边的两个顶点和权值，并在邻接矩阵中设置相应的值。
typedef struct {
    int vexs[Maxsize]; // 顶点表
    int arcs[Maxsize][Maxsize]; // 邻接矩阵
    int vexnum, arcnum; // 图的当前顶点数和弧数
} MGraph;

void CreateUDN(MGraph &G) {
    // 接收信息
    printf("输入顶点数和边数：\n");
    scanf("%d%d", &G.vexnum, &G.arcnum); // 输入顶点数和边数
    for(int i = 0; i < G.vexnum; ++i) {
        printf("输入顶点信息：\n");
        scanf("%d", &G.vexs[i]); // 输入顶点信息
    }
    // 开始构建
    for(int i = 0; i < G.vexnum; ++i) {
        for(int j = 0; j < G.vexnum; ++j) {
            G.arcs[i][j] = INFINITY; // 邻接矩阵初始化
        }
    }
    for(int k = 0; k < G.arcnum; ++k) {
        int i, j, w;
        printf("输入边（vi, vj）的上标i，下标j和权w：\n");
        scanf("%d%d%d", &i, &j, &w); // 输入边（vi, vj）上标i，下标j和权w
        G.arcs[i][j] = w; // 对称元素均赋值w
        G.arcs[j][i] = G.arcs[i][j];
    }
}
