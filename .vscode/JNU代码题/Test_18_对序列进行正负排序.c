// TODO: 对n个算法取实数值的记录序列进行整理，以使所有关键字为负值的记录排序在非负值的记录之前（要求尽量减少记录的交换次数）
void Sort(SqList &L){
    int last = 0; // last记录最后一个连续正整数
    for(int i = 0; i < L.length(); i++){
        if(L.data[i] < 0){
            int temp = L.data[i];
            L.data[i] = L.data[last];
            L.data[last] = temp;
        }
        last++; // 每次交换完记录后，将last自增1
    }
}