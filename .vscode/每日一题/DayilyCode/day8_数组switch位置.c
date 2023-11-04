// TODO: 设将n个整数存放到一维数组R中，将R中保存的序列循环左移p个位置(要求|在时间和空间两方面都尽可能高效的算法）
// [X0, X1, X2, X3, X4,..., Xn-1]->[Xp,Xp+1,...,X0,X1,X2,X3,...,Xp-1] 其中n>1, 0<p<n
// 算法思想: ①将前p个元素逆置②将后n-p个元素逆置③整体逆置
void Reverse_1(int R[], int Start, int End){
    int i, temp;
    for (i = 0; i < (End-Start+1)/2; i++){
        temp = R[Start+i];
        R[Start+i] = R[End-i];
        R[End-i] = temp;
    }
}
void Swap_1(int R[], int p){
    int n = sizeof(R)/sizeof(R[0]);
    Reverse_1(R, 0, p-1);
    Reverse_1(R, p, n-1);
    Reverse_1(R, 0, n-1);
}

// 0925review:100/100
void Reverse_2(int L[], int from, int to){
    int n = to - from +1;
    int temp, i = from;
    while(i < n/2){
        temp=L[i];
        L[i]=L[to- from + i];
        L[to - from + i] = temp;
        i++;
    }
}
void Swap_2(int L[], int p){
    int n = L.length;
    Reverse_2(L, 0, p-1);
    Reverse_2(L, p, n-1);
    Reverse_2(L, 0, n-1);
}
