// G的邻接表存储类型定义如下： 
typedef struct Anode
{
    int adjvex;
    struct ANode *nextarc;
    InfoType weight;
} ArcNode;
typedef struct Vnode
{
    Vertex data;
    ArcNode *firstac;
} VNode;
typedef struct
{
    VNode adjlist[MAXV];
    int n, e;
} AdjGraph;

// G的邻接矩阵存储类型定义如下：
typedef struct
{
    int no;
    InfoType info;
} VertexType;
typedef struct
{
    int edges[MAXV][MAXV];
    int n, e;
    VertexType vexs[MAXV];
} MatGraph;
// !这个算法首先遍历邻接矩阵中的每一行（即每一个顶点），然后对于每一行，它从右到左遍历每一列（即每一个顶点的邻接顶点）。
// !如果在邻接矩阵中找到一个非零元素，那么就在邻接表中为这两个顶点添加一个边。
// !这个边的信息存储在一个ArcNode结构体中，包括邻接顶点的索引、边的权重以及指向下一个边的指针。
// !这个ArcNode结构体被插入到邻接表的相应位置。最后，这个算法将邻接矩阵的顶点数和边数复制到邻接表中。

void MatToList(MatGraph mg, AdjGraph *ag)
{
    int i, j;
    ArcNode *p;
    for (i = 0; i < mg.n; i++)
    {
        ag->adjlist[i].data = mg.vexs[i].no;
        ag->adjlist[i].firstac = NULL;
        for (j = mg.n - 1; j >= 0; j--)
        {
            if (mg.edges[i][j] != 0)
            {
                p = (ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = mg.edges[i][j];
                p->nextarc = ag->adjlist[i].firstac;
                ag->adjlist[i].firstac = p;
            }
        }
    }
    ag->n = mg.n;
    ag->e = mg.e;
}