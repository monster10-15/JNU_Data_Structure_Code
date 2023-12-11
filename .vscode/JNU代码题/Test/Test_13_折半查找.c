int Find(SqList L, int x){
    int i = 0, k = L.length() - 1;
    while(i <= k){
        int j = (i + k) / 2;
        if(x == L[j].data){
            return j;
        }
        else if(x > L[j].data){
            i = j + 1;
        }
        else{
            k = j - 1;
        }
    }
    return -1; // 如果没有找到元素，返回-1
}