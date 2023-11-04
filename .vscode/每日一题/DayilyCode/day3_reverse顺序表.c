// TODO: 设计一个算法，将顺序表的所有元素逆置，要求空间复杂度为O(1)
// 算法思想: 定义一个变量i，只遍历顺序表的一半长度，直接交换i和n-i.

void reverse_1(SqList &L){
    int n = L.length;
    Elemtype temp;
    for (int i =0;i < n/2; i++){
        temp = L.data[i]; 
        L.data[i] = L.data[n-i-1];
        L.data[n-i-1] = temp;
    }
}

// 0920review:100/100
void reverse_2(Sqlist &L){
    int i=0, n = L.length;
    Elemtype temp;
    while(i<n/2){
        temp = L.data[i];
        L.data[i] = L.data[n-i-1];
        L.data[n-i-1] = temp;
        i++;
    }

}