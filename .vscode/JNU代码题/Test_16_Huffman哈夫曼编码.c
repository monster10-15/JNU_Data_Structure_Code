typedef struct {
    int weight;  // 权值
    int parent, lchild, rchild;  // 双亲和左右孩子结点下标
} HTNode, *HuffmanTree;

// 构造哈夫曼树
void CreateHuffmanTree(HuffmanTree &HT, int n, int w[]) {
    if (n <= 1) return;  // 如果只有一个结点或没有结点，不需要构造哈夫曼树
    int m = 2 * n - 1;  // 哈夫曼树的结点数
    HT = (HuffmanTree) malloc((m + 1) * sizeof(HTNode));  // 动态分配哈夫曼树的空间
    for (int i = 1; i <= n; i++) {  // 初始化叶子结点
        HT[i].weight = w[i-1];
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    for (int i = n + 1; i <= m; i++) {  // 初始化非叶子结点
        HT[i].weight = 0;
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    int s1, s2;  // s1和s2为权值最小的两个结点下标
    for (int i = n + 1; i <= m; i++) {  // 构造哈夫曼树
        Select(HT, i-1, s1, s2);  // 选择权值最小的两个结点
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

// 选择权值最小的两个结点
void Select(HuffmanTree HT, int n, int &s1, int &s2) {
    int min1 = INT_MAX, min2 = INT_MAX;
    s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++) {
        if (HT[i].parent == 0) {  // 如果结点没有双亲结点
            if (HT[i].weight < min1) {  // 如果权值比min1小
                min2 = min1;  // 将min1赋值给min2
                s2 = s1;  // 将s1赋值给s2
                min1 = HT[i].weight;  // 更新min1
                s1 = i;  // 更新s1
            } else if (HT[i].weight < min2) {  // 如果权值比min2小
                min2 = HT[i].weight;  // 更新min2
                s2 = i;  // 更新s2
            }
        }
    }
}

// 求哈夫曼编码
void HuffmanCoding(HuffmanTree HT, int n, HCNode *&HC) {
    HC = (HCNode*) malloc((n+1) * sizeof(HCNode));  // 动态分配哈夫曼编码的空间
    char *cd = (char*) malloc(n * sizeof(char));  // 分配临时存储编码的空间
    cd[n-1] = '\0';  // 编码结束符
    for (int i = 1; i <= n; i++) {  // 逐个求叶子结点的哈夫曼编码
        int start = n-1;  // 编码的开始位置
        int c = i;  // 从叶子结点开始
        int f = HT[i].parent;  // 双亲结点
        while (f != 0) {  // 如果结点有双亲结点
            if (HT[f].lchild == c) cd[--start] = '0';  // 如果是左孩子，编码为0
            else cd[--start] = '1';  // 如果是右孩子，编码为1
            c = f;  // 移动到双亲结点
            f = HT[f].parent;  // 移动到双亲结点的双亲结点
        }
        HC[i].ch = i-1;  // 第i个字符的编码
        HC[i].code = (char*) malloc((n-start) * sizeof(char));  // 分配存储编码的空间
        strcpy(HC[i].code, &cd[start]);  // 将编码复制到哈夫曼编码表中
    }
    free(cd);  // 释放临时存储编码的空间
}