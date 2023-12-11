'''假设在n个城市之间的公路网中:已知直达城市之间的乘车费用,各城市之间均存在通路。
从Vo城市开始乘车经过若干个城市到S城市，有多条路线可以选择。
设计算法: 选择一条最节省费用的路线。要求:
(1) 选择一种合适的数据结构，描述 n 个城市之间的公路网;(4 分)
(2) 用伪代码描述求从 V,城市到 S 城市最节省费用的路线。(8 分)'''
// 定义图的数据结构
typedef struct {
    int vexnum;       // 顶点数
    int edgnum;       // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph;
// Dijkstra算法
void dijkstra(Graph G, int v0, int prev[], int dist[]) {
    int flag[MAX]; // 【标记数组】flag[i]=1表示已访问
    int k;
    // step1: 初始化flag && prev && dist
    for (i = 0; i < G.vexnum; i++) {
        flag[i] = 0;              // 顶点i还没被访问过
        prev[i] = -1;              // 顶点i无前驱顶点
        dist[i] = G.matrix[v0][i]; // "顶点v0"到"顶点i"的路径长度
    }
    // step2: 对"源点v0"自身进行初始化
    flag[v0] = 1;
    dist[v0] = 0;
    // step3: 对剩下的n-1个顶点遍历  旨在找到[v0->k]+[k->j] < [v0->j] 实现曲线救国
    for (int i = 1; i < G.vexnum; i++) {
        int min = INF;
        // !选出当前权重和最短的点【并且是没有标记访问过的】[即 找新捷径]
        for (int j = 0; j < G.vexnum; j++) {
            if (flag[j]==0 && dist[j] < min) {
                min = dist[j]; // 这里的j 只是遍历的，别搞错了
                k = j; //! min: [v0->k] 
            }
        }
        flag[k] = 1; // 标记"顶点k"已读 [或者说预备加入最短路径那意思]
        // step4: 找捷径 + 确认捷径是否可取
        for (int j = 0; j < G.vexnum; j++) {
            int newdist = min + G.matrix[k][j];
            if (flag[j] == 0 && (newdist < dist[j]) ) {// !如果[v0->k]+[k->j] < [v0->j] 曲线救国成功 
                dist[j] = newdist;
                prev[j] = k;
            }
        }
    }
}

// 1109 review: 80/100
void Dijkstra(Graph G, int v0, int prev[], int dist[]){
    // step 1: 初始化dist[] && prev[] && flag[]
    int flag[G.vexnum];
    int k;
    for(int i = 0; i < G.vexnum; i++){
        flag[i]=0;
        prev[i]=-1;
        dist[i]=G.martrix[v0][i];
    }
    // step 2: 对源点初始化
    flag[v0]=1;
    dist[v0]=0;
    // step 3: 对剩下的n-1个顶点遍历，旨在找到[v0->k]+[k->j]<[v0->j]实现曲线救国
    for(int i = 1; i < G.vexnum; i++){
        int min = INF;
        for( int j = 0; j < G.vexnum; j++){
            if(dist[j] < min && dist[j]!=0 && flag[j]==0){
                min=dist[j];
                k=j;
            }
        }
        flag[k] = 1;
        prev[k] = v0;
        // step4: 找捷径 + 确认捷径是否可取
        for(int j = 0; j < G.vexnum; j++){
            int newdist = min+G.martrix[k][j];
            if(newdist < dist[j] && flag[j]==0){
                prev[j] = k;
                flag[j] = 1;
                dist[j] = newdist;
            }
        }
    }
    
}
'''22[830]一个公司在某地区有n个产品销售点，现打算在这个地区的某个销售点上建一个中心仓库，负责向该地区的各个销售点提供销售产品。
由于运输线路和公交条件不同，向每个销售点运输一次产品的费用也不相同。若公司每天都会向每个运输点运输一次产品，
试设计一个算法，以帮助公司解决应将中心仓库建立在哪个销售点上才能使运输费用达到最低的问题。
'''
// 思路：
// TODO:初始化一个长度为n的数组cost，其中n是销售点的数量。数组的每个元素对应一个销售点，初始值都设为0。
// TODO:对于每个销售点i（从0到n-1），计算它到所有其他销售点的运输费用总和，然后将这个总和存储在cost[i]中。
// TODO:找出cost数组中的最小值，对应的索引就是最佳的中心仓库位置。[dijkstra]

#include <stdio.h>
#define MAXN 1000

int cost[MAXN][MAXN]; //! 运输费用矩阵
int n; // 销售点的数量

int find_min_cost() {//! 找出运输费用总和最小的销售点
    int min_cost = 0;//! 最小费用
    int min_index = 0;//! 对应的索引
    for (int i = 0; i < n; i++) {
        int total_cost = 0;
        for (int j = 0; j < n; j++) {
            total_cost += cost[i][j];
        }
        if (i == 0 || total_cost < min_cost) {
            min_cost = total_cost;
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    // 假设cost矩阵和n已经被初始化
    int min_index = find_min_cost();
    printf("最佳的中心仓库位置是：%d\n", min_index);
    return 0;
}

// TODO:这个程序首先定义了一个二维数组cost来存储每对销售点之间的运输费用，以及一个整数n来存储销售点的数量。
// TODO:然后，它定义了一个函数find_min_cost来找出运输费用总和最小的销售点。
// TODO:这个函数首先初始化一个最小费用min_cost和对应的索引min_index，然后遍历每个销售点，计算其到所有其他销售点的运输费用总和，
// TODO:并更新min_cost和min_index。最后，这个函数返回min_index，即运输费用总和最小的销售点的索引。
