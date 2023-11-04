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
