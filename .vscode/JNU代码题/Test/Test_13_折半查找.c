void ZBSort(Sqlist L, int x){
    int k = L.length()-1; // 初始化右边界为列表的长度减一
    int i = 1; // 初始化左边界为1
    while(i<k){ // 当左边界小于右边界时，继续查找
        int j =(i+k)/2; // 计算中间位置
        if(x==L[j].data){ // 如果找到了目标元素，返回其位置
            return j;
        }
        else if(x>L[j].data){ // 如果目标元素大于中间位置的元素，更新左边界为中间位置加一
            i=j+1;
        }
        else if(x<L[j].data){ // 如果目标元素小于中间位置的元素，更新右边界为中间位置减一
            k=j-1;
        }
    }
    return -1; // 如果没有找到目标元素，返回-1
}
