// 定义最大数组大小
#define Maxsize 100
// 定义键类型
typedef int keytype;
// 定义记录类型
typedef struct {
    keytype key; // 键
    Infotype otherinfo; // 其他信息
} RedType;
// 定义顺序表类型
typedef struct {
    RedType r[Maxsize+1]; // 记录数组，r[0]用作哨兵或临时存储
    int length; // 表的长度
} SqList;

// 快速排序函数
void Qsort(SqList &L, int low, int high) {
    if (low < high) {
        pivotloc = Partition(L, low, high); // 对表进行划分，pivotloc是基准的位置
        Qsort(L, low, pivotloc - 1); // 对低子表递归排序
        Qsort(L, pivotloc + 1, high); // 对高子表递归排序
    }
}

// 划分函数
int Partition(SqList &L, int low, int high) {
    L.r[0] = L.r[low]; // 用子表的第一个记录作为基准
    pivotkey = L.r[low].key; // 基准记录的关键字
    while (low < high) { // 从表的两端交替向中间扫描
        while (low < high && L.r[high].key >= pivotkey) high--; // 找到比基准小的记录
        L.r[low] = L.r[high]; // 将比基准小的记录移到低端
        while (low < high && L.r[low].key <= pivotkey) low++; // 找到比基准大的记录
        L.r[high] = L.r[low]; // 将比基准大的记录移到高端
    }
    L.r[low] = L.r[0]; // 将基准记录移到正确的位置
    return low; // 返回基准的位置
}

// 2020年考察的形式变了（那个pivot从前面换成后面了）
假设一维数组 A 保存有 N 个整数，以下快速排序算法代码能够对数组 A 进行排序。请在处填上适当内容，使其成为一个完整的算法。
// 定义分区函数
int partition(int* A, int N, int p, int r){
    // 选择最后一个元素作为主元
    int x = A[r];
    // i 是小于主元的元素的索引
    int i= p-1;
    // 遍历数组，将小于主元的元素放在左边，大于主元的元素放在右边
    for (int j = p; j<=r-1; j++){
        if(A[j]>=x){
            i=i+1;
            // 交换 A[i] 和 A[j]
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    // 将主元放到正确的位置
    int temp = A[i+1];
    A[i+1]=A[r];
    A[r] = temp;
    // 返回主元的位置
    return i+1;
}
// 定义快速排序函数
void QuickSort(int* A, int N, int p, int r){
    int q;
    // 如果 p < r，说明数组中至少有两个元素
    if(p<r){
        // 对数组进行分区，并获取主元的位置
        q = partition(A, N, p, r);
        // 对主元左边的子数组进行快速排序
        QuickSort(A,N,p,q-1);
        // 对主元右边的子数组进行快速排序
        QuickSort(A,N,q+1,r);
    }
    return;
}

void main(){
    QuickSort(A,N,0,N-1); 
    return 0;
}