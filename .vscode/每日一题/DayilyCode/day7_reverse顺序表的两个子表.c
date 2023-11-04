// TODO: 已知在一维数组A[m+n]中依次存放两个线性表（a1,a2...am）和（b1,b2...bn）试编写一个算法使得数组中两个顺序表的位置互换
// 算法思想：①前m个逆置②后n个逆置③再整体逆置

void reverse_1(Elemtype L[], int start, int end){
    Elemtype temp;
    int len = end - start;
    // 下面这步的思想源自day3逆置顺序表
    for(int i=0; i<len/2; i++){
        temp = L.data[start+i];
        L.data[start+i] = Ldat[end-i];
        L.data[end-i] = temp;
    }
}
void swap_1(L, int m, int n){
    reverse_1(L, 0, m-1);
    reverse_1(L, m, m+n-1);
    reverse_1(L, 0, m+n-1);
}

// 0924review:
void reverse_2(int L[], int start, int end){
    int temp;
    while(start < end){
        temp = L[start];
        L[start] = L[end];
        L[end] = temp;
        start++, end--;
    }
}
void swap_2(L, int n, int m){
    reverse_2(L, 0, m-1);
    reverse_2(L, m, n-m+1);
    reverse_2(L, 0, n-1);
}
