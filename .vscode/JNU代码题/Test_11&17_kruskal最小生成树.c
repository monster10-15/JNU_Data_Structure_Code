// 1、初始化：每个顶点被视为一个单独的连通分量。
// 2、排序：所有的边按照权值从小到大进行排序。
// 3、构建最小生成树：遍历所有的边，检查每一条边连接的两个顶点是否属于同一个连通分量。
//    如果不是（即这条边不会在生成树中形成环路），则将这条边添加到最小生成树中，并更新相关顶点所属的连通分量。

// 定义图的数据结构
typedef struct {
    int v;       // 顶点数
    int e;       // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph;
// 定义一个结构体Road，表示图中的一条边
typedef struct{
    int a, b; //一条边的两个顶点
    int w; // 边的权值
}Road;
// 定义一个Road类型的数组，用来存储图中的所有边
Road road[Maxsize];
// 定义一个并查集数组
int V[Maxsize];
// 从并查集中查找根结点的函数
int getRoot(int a){
    while(a!=V[a]) a=V[a];    
    return a;
}
// Kruskal算法的实现
void kruskal(Graph &G, int &sum, Road road[]){
    int i, N, E, a, b;
    N=G.n, E=G.e, sum=0; // N是顶点数，E是边数，sum用来存储最小生成树的权值和
    // 初始化并查集，每个顶点自己是自己的根
    for(i=0; i<N; ++i){
        V[i]=i;
    } 
    // 对所有的边按照权值进行排序
    sort(road, E);
    // 遍历所有的边
    for(i=0; i<E; ++i){
        // 查找当前边的两个顶点所在的集合的根
        a=getRoot(road[i].a);
        b=getRoot(road[i].b);
        // 如果两个顶点不在同一个集合中，说明这条边可以添加到最小生成树中
        if(a!=b){
            // 合并两个集合
            V[a]=b;
            // 将这条边的权值加到sum中
            sum+=road[i].w;
        }
    }
}

